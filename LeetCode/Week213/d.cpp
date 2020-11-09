class Solution {
public:
    int c[40][40];
    void init(int n, int m) {
        int x = n + m;
        c[0][0] = 1;
        for(int i = 1; i <= x; i ++) {
            c[i][0] = 1;
            for(int j = 1; j <= x; j ++) {
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
        //cout << c[5][2] << endl;
        while(i < n && j < m) {
            if(k <= c[n+m-i-j-1][m-j-1]){
                s += 'H';
                j++;
            }
            else { 
                s += 'V';
                k -= c[n+m-i-j-1][m-j-1];
                i++;
            }
        }
        for(; i < n; i ++) s+='V';
        for(; j < m; j ++) s+='H';
        return s;
    }
};