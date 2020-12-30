#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int n;
int a[2005][2005];


int ans[15];
int mnc[15], mxc[15], mnr[15], mxr[15];

void solve() {
    
    for(int i = 0; i <= 9; i ++) {
        mxc[i] = 0;
        mnc[i] = 1 << 30;
        mxr[i] = 0;
        mnr[i] = 1 << 30;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            mnc[ a[i][j] ] = min(mnc[ a[i][j] ], i);
            mxc[ a[i][j] ] = max(mxc[ a[i][j] ], i);

            mnr[ a[i][j] ] = min(mnr[ a[i][j] ], j);
            mxr[ a[i][j] ] = max(mxr[ a[i][j] ], j);

        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int x = a[i][j];
            ans[x] = max(ans[x], max( i-mnc[x], mxc[x] - i )* max(j-1, n-j));
            ans[x] = max(ans[x], max(i-1, n-i) * max(j-mnr[x], mxr[x] - j));
        }
    }
}


int main() {

    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++)
                scanf("%1d", &a[i][j]);
        }

        for(int i = 0; i <= 9; i ++) ans[i]  = 0;
        solve();

        for(int i = 0; i <= 9; i ++) cout << ans[i] << " ";
        cout << endl;

    }

    return 0;
}


