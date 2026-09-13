#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  typedef pair<int,int>P;
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Construct adjacency list
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>inMST(V,false);
        
        pq.push({0,0});
        
        int sum = 0;
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second; // parent
            
            if(inMST[node] == true) continue;
            
            inMST[node] = true;
            sum += wt;
            
            for(auto &tmp : adj[node]){
                int neighbour = tmp.first;
                int neighbour_wt = tmp.second;
                
                if(inMST[neighbour] == false){
                    // pq.push({neighbour_wt,neighbour,parent}) if we want parent too
                    pq.push({neighbour_wt,neighbour});
                }
            }
        }
        
        return sum;
    }
};
// if in the end any node remains false inMST that means full MST construction is impossible as there's at least one node which is unreachable
