class Solution{
    public :
    vector<int> bellman_ford (int V , vector<vector<int>>&edges , int src) // int source 
    {

        vector<int> result( V , INT_MAX);
            result[src] = 0;
            for(int i = 0 ; i<V-1 ; i++){
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if( result[u]!=INT_MAX && result[u]+wt<result[v]){
                    result[v]=result[u]+wt;
                }
            }
        }
        // now one more iteration to check if its a negative cycle 
        for(auto &edge : edges){
            int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if( result[u]!=INT_MAX && result[u]+wt<result[v]){
                    return {-1};// negative cycle detected if one more relaxation occurs after V-1 relaxations , return -1;
                }

        }
        return result;
    }

};
