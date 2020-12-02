class Solution {
public:
    int x[100005];
    string getSmallestString(int n, int k) {
        string ans = "";
        memset(x, 0, sizeof(x));
        k -= n;
        for(int i = n-1; i >= 0; i --) {
            
            if(k <= 25) {
                x[i] += k;
                break;
            }
            k -= 25;
            x[i] += 25;
            
        }
        for(int i = 0; i < n; i ++) {
            ans += char(x[i]+'a');
        }
        return ans;
    }
};