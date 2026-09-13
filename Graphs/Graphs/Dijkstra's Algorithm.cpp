

class Solution {
public:
    // using priority queue (minHeap)
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int source) {
        vector<vector<pair<int,int>>> adj(V);

        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(V, INT_MAX);

        result[source] = 0; // distance of source from source is zero obviously
        pq.push({0, source});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > result[node])
                continue;

            for (auto &vec : adj[node]) {
                int adjNode = vec.first;
                int wt = vec.second;

                if (d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }

        return result;
    }

    // dijkstra using set
    vector<int> dijkstraSet(int V, vector<vector<int>> &edges, int source) {
        vector<vector<pair<int,int>>> adj(V);

        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> result(V, INT_MAX);
        set<pair<int,int>> st;

        result[source] = 0;
        st.insert({0, source});

        while (!st.empty()) {
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(it);

            for (auto &vec : adj[node]) {
                int adjNode = vec.first;
                int dist = vec.second;

                if (d + dist < result[adjNode]) {
                    if (result[adjNode] != INT_MAX) {
                        st.erase({result[adjNode], adjNode});
                    }

                    result[adjNode] = d + dist;
                    st.insert({d + dist, adjNode});
                }
            }
        }

        return result;
    }
};
