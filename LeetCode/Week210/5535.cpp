class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxn = 0;
        int now = 0;
        for(int i = 0; i < n; i ++) {
            if(s[i] == '(') now++;
            else if(s[i] == ')') now--;
            maxn = max(now, maxn); 
        }
        return maxn;
    }
};