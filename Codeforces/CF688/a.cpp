#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a[104], b[105];
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int x;
        int cnt = 0;
        for(int i = 0; i <= 100; i ++) {
            a[i] = 0;
            b[i] = 0;
        }
        for(int i = 0; i < n; i ++) {
            cin >> x;
            a[x] = 1;
        }
        for(int i = 0; i < m; i ++) {
            cin >> x;
            b[x] = 1;
        }
        for(int i = 1; i <= 100; i ++) {
            if(a[i] && b[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}