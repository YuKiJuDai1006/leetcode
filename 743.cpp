class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for(auto& it : times){
            g[it[0]-1][it[1]-1] = it[2];
        }

        vector<int> dist(n, inf);
        vector<bool> visit(n);
        dist[k-1] = 0;

        for(int i = 0; i < n; i++){
            int dis = INT_MAX;
            int idx;
            for(int j = 0; j < n; j++){
                if(!visit[j] && dist[j] < dis){
                    dis = dist[j];
                    idx = j;
                }
            }

            visit[idx] = 1;
            for(int j = 0; j < n; j++){
                dist[j] = min(dist[j], dist[idx] + g[idx][j]);
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};