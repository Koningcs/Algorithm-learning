#include<cstdio>
#include<iostream>

using namespace std;

const int N = 100004;
typedef long long ll;
int n, m;
ll a[N];
ll b[N];
int lowbit(int x) {return x & - x;}
void add(int x, ll c) {
    for(int i = x; i <= n; i += lowbit(i)) b[i] += c;
}
ll sum(int x ) {
    ll res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) res += b[i];
    return res;
}
int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        add(i, a[i] - a[i-1]);
    }
    char c;
    int l,  r;
    ll d;
    for(int i = 0; i < m; i ++) {
        cin >> c;
        if( c == 'Q') {
            cin >> l;
            cout << sum(l) << endl;
        }
        else {
            cin >>  l >> r >> d;
            add(l, d);
            add(r+1, -d);
        }
    }

}