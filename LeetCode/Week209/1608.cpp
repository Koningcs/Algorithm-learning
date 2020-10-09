class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = -1;
        for(int i = 0; i < n; i ++) {
            if(nums[i] >= n-i) {
                if(i == 0) x = n-i;
                if(i >= 1 && n-i > nums[i-1])
                    x = n-i;
                
            }
        }
        return x;
    }
};