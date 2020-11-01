class Solution {
public:
    int a[55][10];
    int sum1[55][10];
    int countVowelStrings(int n) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= 6; j ++) sum1[i][j] = 0;
        }
        for(int i = 1; i <= 5; i ++) {
            a[0][i] = 1;
        }
        for(int i = 5; i >= 0; i --) sum1[0][i] = a[0][i] + sum1[0][i+1];

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= 5; j ++) {
                a[i][j] = sum1[i-1][j];
            }
            for(int j = 5; j >= 0; j --) {
                sum1[i][j] = sum1[i][j+1] + a[i][j];
            }

        }
        return a[n][1];
    }
    
};