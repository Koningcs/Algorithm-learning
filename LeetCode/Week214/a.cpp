class Solution {
public:
    int a[300];
    int getMaximumGenerated(int n) {
        a[0] = 0;
        a[1] = 1;
        int maxn = 0;
        for(int i = 1; 2* i <= n; i ++) {
            a[2*i] = a[i];
            a[2*i+1] = a[i] + a[i+1];
        }

        for(int i = 0; i <= n; i ++) {
            maxn = max(a[i], maxn);
        }
        return maxn;
    }
};