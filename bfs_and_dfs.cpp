#include<bits/stdc++.h>
 using namespace std;
class Solution {
    // tc O(N) + O(2E)
    // sc O(3N)
    public:
    vector<int>bfsOfGraph(int V , vector<int> adj[]){ // main function
        vector<int>vis(V,0);
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }

        }
        return bfs; // main function till here



    }
     class Solutionn{
        private:
        void dfs(int node , vector<int> adj[],vector<int>&vis , vector<int>&dfss){
            vis[node]=1;
            dfss.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it,adj,vis,dfss);
                }
            }

        }
        
        public:
        vector<int>dfsOfGraph(int V , vector<int> adj[]){
            vector<int>vis(V,0);
            int start = 0;
            vector<int>dfss;
            dfs(start,adj,vis,dfss);
            return dfss;
            
        

    }

     };
};
 int main(){
    // not important part
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // remove this for directed graph
    }

    Solution obj;

    vector<int> ans = obj.bfsOfGraph(V, adj);

    for (auto x : ans) {
        cout << x << " ";
    }

    
    return 0;
}