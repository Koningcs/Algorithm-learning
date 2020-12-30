#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;


typedef long long ll;
int n;
int a[200005];

ll ffabs(int x, int y) {
    if(x > y) {
        return (1ll*x - 1ll*y);
    }
    else return (1ll*y - 1ll*x);
}
int main() {

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        a[0] = a[1];
        a[n+1] = a[n];
        ll cnt = 0;
        ll ans = 0;
        for(int i = 1; i < n; i ++) {
            cnt += ffabs(a[i], a[i+1]);
        }
        ans = cnt;
        ans = min(ans, cnt - ffabs(a[1], a[2]));
        
        for(int i = 2; i < n; i ++) {
            ans = min(ans, cnt+ffabs(a[i-1],a[i+1])- ffabs(a[i-1],a[i]) - ffabs(a[i],a[i+1]));
        }
        ans = min(ans,cnt- ffabs(a[n-1], a[n]));
        cout << ans << endl;
    }
    return 0;
}


