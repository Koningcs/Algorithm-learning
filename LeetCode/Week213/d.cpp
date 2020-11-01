class Solution {
public:
    int c[20][20];
    void init(int n, int m) {
        for(int i = 1; i <= n; i ++ ) {
            for(int j = 1; j <= m; j ++) {
                c[i][j] = c[i - 1][j] + c[i-1][j-1];
            }
        }
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        int n = destination[0]; int m = destination[1];
        init(n, m);
        int i = 0, j = 0;
        // H的数量m, V的数量n
        string s = "";
        while(i < n && j < m) {
            if(k < c[m-j-1][n+m-i-j-1]) s += 'H';
            else s += 'V';
        }
        return s;
    }
};