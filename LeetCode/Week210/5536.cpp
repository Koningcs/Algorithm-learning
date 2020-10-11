class Solution {
public:
    int deg[104];
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxn = 0;
        vector<int> road[104];
        int m = roads.size();
        for(int i = 0; i < m; i ++) {
            road[roads[i][0]].push_back(roads[i][1]);
            road[roads[i][1]].push_back(roads[i][0]);
            
        }
        for(int i = 0; i < n; i ++) {
            deg[i] = road[i].size();
        }
        for(int i = 0; i < n; i ++) {
            for(int j = i+1; j < n; j ++) {
                if(deg[i] + deg[j] > maxn) {
                    int flag = 0;
                    for(int k = 0; k < road[i].size(); k ++) {
                        if(road[i][k] == j) {
                            flag = 1; break;
                        }
                    }
                    //cout << i << j << " " << maxn << endl;
                    maxn = max(maxn, deg[i]+deg[j]);
                    maxn -= flag;
                }
            }
        }
        return maxn;
    }
};