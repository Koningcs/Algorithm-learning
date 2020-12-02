// 树状数组

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;


typedef long long ll;
const int N = 200005;
ll great[N];
ll lower[N];
ll a[N];
ll tr[N];
int n;

int lowbit(int x) {return x & (-x);}
void add(int x, int c) {
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

ll sum(int x) {
    ll res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
int main() {

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        lower[i] = sum(a[i]);
        great[i] = sum(n) - sum(a[i]-1);
        
        add(a[i], 1);
    }
    memset(tr, 0, sizeof(tr));
    ll ans1 = 0;
    ll ans2 = 0;
    for(int i = n; i > 0; i --) {
        ans1 += lower[i] * sum(a[i]);
        ans2 += great[i] * (sum(n) - sum(a[i]-1) );
        add(a[i], 1);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}