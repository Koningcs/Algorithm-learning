#include<cstdio>
#include<iostream>
using namespace std;

const int N = 3005;
int a[N], b[N];
int dp[N][N];
int main()  {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int j = 1; j <= n; j ++) cin >> b[j];

    int S = 0;
    for(int i = 1; i <= n; i ++) {
        S = 0;
        for(int j = 1; j <= n; j ++) {
            dp[i][j] = dp[i-1][j];
            if(b[j] < a[i])
                S = max(S, dp[i - 1][j]);
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], S + 1);
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= n; j ++) ans = max(ans, dp[n][j]);
    cout << ans << endl;
}


