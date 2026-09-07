class Solution {
private:
// we are using leetcode 210 Course Schedule - II as it demonstrates Kahn's algo completely

    // Kahn's Algorithm using BFS
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj,
                                int n,
                                vector<int>& indegree) {

        queue<int> q;

        // Put all courses with no prerequisites into the queue
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;

        // BFS
        while(!q.empty()) {

            int u = q.front();
            q.pop();

            // Add this course to our answer
            res.push_back(u);

            // Remove this course from the graph
            for(int &v : adj[u]) {

                indegree[v]--;

                // All prerequisites of v are now completed
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If we couldn't include all courses,
        // there is a cycle, so no valid ordering exists
        if(res.size() != n) {
            return {};
        }

        return res;
    }


public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        vector<int> indegree(numCourses, 0);

        // Build directed graph
        for(auto &vec : prerequisites) {

            int a = vec[0];
            int b = vec[1];

            // b ---> a
            // We must complete b before a
            adj[b].push_back(a);

            // a has one incoming edge
            indegree[a]++;
        }

        // Get topological ordering
        return topologicalSort(adj, numCourses, indegree);
    }
};
