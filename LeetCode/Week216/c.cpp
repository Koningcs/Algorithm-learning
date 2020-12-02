class Solution {
public:
    int sump[1000005];//O
    int sums[1000005];
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        sump[0] = nums[0];
        if(n > 1) sump[1] = nums[1];
        for(int i = 2; i < n; i += 2) {
            if(i < n) sump[i] = sump[i-2] + nums[i];
            if(i+1 < n) sump[i+1] = sump[i-1] + nums[i+1];
        }
        if(n >= 1) sums[n-1] = nums[n-1];
        if(n >= 2) sums[n-2] = nums[n-2];
        for(int i = n-3; i >= 0; i --) {
            if(i >= 0) sums[i] = sums[i+2] + nums[i];
            if(i -1 >= 0) sums[i-1] = sums[i+1] + nums[i];
        }
        int ans = 0;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i ++) {
            sum1 = 0; sum2 = 0;
            if(i > 0 ) sum1 += sump[i-1];
            if(i > 1) sum2 += sump[i-2];
            if(i < n-2) sum1 += sums[i+2];
            if(i < n-1) sum2 += sums[i+1];
            if(sum1 == sum2) ans++;
        }
        return ans;
    }
};