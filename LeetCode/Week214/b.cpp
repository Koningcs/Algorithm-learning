class Solution {
public:
    int a[30];
    int b[100005];
    int minDeletions(string s) {
        int n = s.size();
        for(int i = 0; i < n; i ++) {
            a[s[i] - 'a'] ++;
        }
        int maxn = 0;
        for(int i = 0; i < 26; i ++) {
            if(a[i]) b[ a[i] ] ++;
            maxn = max(maxn, a[i]);
        }
        int sum = 0;
        for(int i = maxn; i >= 1; i--) {
            if(b[i] > 1) {
                b[i-1] += b[i]-1;
                sum += b[i]-1;
                b[i] = 1;
            }
        }
        return sum;
    }
};