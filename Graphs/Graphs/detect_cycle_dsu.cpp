class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionn(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) {
            return;
        }

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool detectCycle(int V, vector<int> adj[]) {

        parent.resize(V);
        rank.resize(V, 0);

        for(int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for(int u = 0; u < V; u++) {

            for(int &v : adj[u]) {

                // Process each undirected edge onlyy once
                if(u < v) {

                    int parent_u = find(u);
                    int parent_v = find(v);

                    if(parent_u == parent_v) {
                        return true;
                    }
                    else {
                        unionn(u, v);
                    }
                }
            }
        }

        return false;
    }
};
