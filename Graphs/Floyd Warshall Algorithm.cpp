class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // O(N^3) obviously
        int n = dist.size();
        const int INF = 1e8;
        for(int via = 0 ; via<n ;via++){
            for(int i = 0 ;i<n ; i++){
                for(int j = 0 ; j<n ; j++){
                    if(dist[i][via] == INF || dist[via][j] == INF) continue; // check overflow
                    dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};
