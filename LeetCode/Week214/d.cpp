class Solution {
public:

    int tr[100005];
    int mod = 1e9 + 7;
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int c) {
        for(int i = x; i <= 100000; i += lowbit(i)) tr[i] += c; 
    }
    int sum(int x) {
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    int createSortedArray(vector<int>& instructions) {  
        int n = instructions.size();
        for(int i = 0; i <= 100000 ; i ++) tr[i] = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = (ans +  min(sum(instructions[i]-1), sum(100000) - sum(instructions[i]) ) )%mod;
            add(instructions[i], 1);
        }
        return ans;
    }
};