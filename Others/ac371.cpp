#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll f[31][31][31][31][31];



int n, k;
int a[10];
int main() {

    while(scanf("%d",&k)) {
        if(k == 0) break;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= k; i ++) {
            scanf("%d",&a[i]);
        }
        memset(f, 0, sizeof(f)) ;
    
        f[1][0][0][0][0] = 1;
        for(int a1 = 1; a1 <= a[1]; a1 ++) {
            for(int a2 = 0; a2 <= min(a[1], a[2]); a2 ++) {
                for(int a3 = 0; a3 <= min(a[2],a[3]); a3 ++) {
                    for(int a4 = 0; a4 <= min(a[3],a[4]); a4 ++) {
                        for(int a5 = 0; a5 <= min(a[4],a[5]); a5 ++) {
                            if(f[a1][a2][a3][a4][a5] == 0) continue;
                            if(a1 < a[1]) f[a1+1][a2][a3][a4][a5] += f[a1][a2][a3][a4][a5];
                            if(a2 < a[2] && a2 < a1) f[a1][a2+1][a3][a4][a5] += f[a1][a2][a3][a4][a5];
                            if(a3 < a[3] && a3 < a2) f[a1][a2][a3+1][a4][a5] += f[a1][a2][a3][a4][a5];
                            if(a4 < a[4] && a4 < a3) f[a1][a2][a3][a4+1][a5] += f[a1][a2][a3][a4][a5];
                            if(a5 < a[5] && a5 < a4) f[a1][a2][a3][a4][a5+1] += f[a1][a2][a3][a4][a5];
                        }
                    }
                }
            }
        }

        printf("%lld\n",f[a[1]][a[2]][a[3]][a[4]][a[5]]);

    }
    return 0;
}