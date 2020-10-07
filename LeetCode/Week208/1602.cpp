class Solution {
public:
    int in[25], out[25];
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int maxn = 0;
        for(int S = 0; S < 1<<m; S ++) {
            int cnt = 0;
            int i;
            for(int i = 0; i < n; i ++) {
                in[i] = 0, out[i] = 0;
            }
            for(i = 0; i < m; i ++) {
                if( S>>i&1 ) {
                    out[ requests[i][0] ]++;
                    in [ requests[i][1] ]++;
                    cnt++;
                }
            }

            for(i = 0; i < n; i ++) {
                if(in[i] != out[i]) break;
            }
            if(i == n) {
                maxn = max(maxn, cnt);
            }
        }
        return maxn;
    }
};