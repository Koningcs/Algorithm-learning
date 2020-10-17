#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int t;
int a[200005];

bool cmp(int x, int y) { return x > y;}
int main() {

    cin >> t;
    int k, n;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }

        sort(a, a + n, cmp);
        long long  ans = 0ll;
        k++;
        for(int i = 0; i < min(k, n); i ++)
            ans += a[i];
        cout << ans << endl;
    }

    return 0;
}