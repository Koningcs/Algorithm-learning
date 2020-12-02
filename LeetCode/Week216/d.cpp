    struct node {
        int a; int b;
    };
    bool cmp(node x, node y) {
        return (x.b - x.a) < (y.b - y.a);
    }

class Solution {
public:

    int minimumEffort(vector<vector<int>>& tasks) {
        node s[100005];
        int n = tasks.size();
        for(int i = 0; i < n; i ++) {
            s[i].a = tasks[i][0];
            s[i].b = tasks[i][1];
        }
        int ans = 0;
        sort(s, s + n, cmp);
        for(int i = 0; i < n; i ++) {
            if(i == 0) ans += s[i].b;
            else {
                if(ans+s[i].a > s[i].b) ans += s[i].a;
                else ans = s[i].b;
            }
                
        }
        return ans;
    }
};