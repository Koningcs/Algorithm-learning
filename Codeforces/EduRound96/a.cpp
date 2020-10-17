#include<cstdio>
#include<iostream>
using namespace std;

int main() {
    int n, t;
    cin >> t;
    while(t--) {
        cin >> n;
        int flag = 0;
        int x = 0;
        for(int i = 0; i <= 400; i ++) {
            x = 0;
            for(int j = 0; j <= 200; j ++) {
                for(int k = 0; k <= 200; k ++) {
                    if(flag == 1) break;
                    x = 3*i + 5*j + 7*k;
                    if(x == n) {
                        cout << i << " " << j << " " << k << endl;
                        flag = 1;
                        break;
                    }
                    if(x >= n) break;
                }

            }
        }
        if(flag == 0) cout << -1<< endl;
    }
    return 0;
}