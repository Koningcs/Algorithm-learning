class Solution {
public:
    int inf = 1000;
    int g[220][220];
    int g1[220][220];
    int vis[100];
    vector<int> ans;
    vector<int> tmp;
    int d[20];
    void floyd(int n) {
        for(int k = 1; k <= n; k ++) {
            for(int i = 1; i <= n; i ++) {
                for(int j = 1; j <= n; j ++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    } 
    void init(int n, vector<vector<int>>& edges) {
        for(int i = 0; i <= n; i ++) {
            for(int j = 0; j <= n; j ++) {
                g1[i][j] = 0;
                g[i][j] = inf;
            }
        }
        int m = edges.size();
        for(int i = 0; i < m;  i ++) {
            g[ edges[i][0] ][ edges[i][1] ] = 1;
            g[ edges[i][1] ][ edges[i][0] ] = 1;
            g1[ edges[i][0] ][ edges[i][1] ] = 1;
            g1[ edges[i][1] ][ edges[i][0] ] = 1;
        }
    }
    void dfs(int u) {
        for(int i = 0; i < tmp.size(); i ++) {
            
            if(g1[u][ tmp[i] ] == 1 && vis[ tmp[i] ] == 0) {
                vis[ tmp[i] ] = 1;
                dfs(tmp[i]);
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        init(n,edges);
        floyd(n);
        for( int S = 1; S < (1 << n); S++ ) {
            tmp.clear();
            for(int i = 0; i < n; i ++) {
                if( (S >> i) & 1 ) {
                    tmp.push_back(i+1);
                    vis[i+1] = 0;
                }
            }
            //for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
            //cout << endl;
            vis[tmp[0]] = 1;
            
            dfs(tmp[0]);
            int flag = 0;
            for(int i = 0; i < tmp.size(); i ++) if(vis[ tmp[i] ] == 0) flag = 1;
            if(flag) continue;
            int maxn = 0;
            for(int i = 0; i < tmp.size(); i ++) {
                for(int j = i + 1; j < tmp.size(); j ++) {
                    maxn = max(maxn, g[tmp[i]][tmp[j]]);
                }
            }
            
            if(maxn < n) { 
                d[maxn]++;
            }
        }
        for(int i = 1; i < n; i ++) ans.push_back(d[i]);
        return ans;
    }
};
