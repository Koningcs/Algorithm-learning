#include<cstdio>
#include<iostream>
using namespace std;
int t, n;
int a[200005];
int b[200005];
int main() {

    scanf("%d", &t);
    while(t--) {

        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) {
            scanf("%1d", &a[i]);
            b[i] = 0;
        }
        b[n+1] = 0;
        int k = 0;
        a[0] = 2;
        for(int i = 1; i <= n; i ++) {
            if(a[i] != a[i-1]) { k++; b[k] = 1;}
            else b[k]++;
        }
        int i = 1, j = 1;
        k++;
        int ans = 0;
        while(i < k && j < k) {
            while(j < k && b[j] <= 1) {
                j++;
            }
            if(i == j) {
                ans++;
                i++;j++;
            }
            else {  
                if(b[j] > 1) {
                    b[j]--; i++; 
                    ans++;
                }
            }
        }
        //printf("%d %d %d\n",k, i,j);
        ans += (k-i + k-j + 1) / 2;
        printf("%d\n",ans);
    }


    return 0;
}
