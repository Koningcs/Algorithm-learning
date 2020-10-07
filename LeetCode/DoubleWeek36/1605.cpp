#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int> > ans(n, vector<int>(m));
        int i = 0, j = 0;
        while(1) {
            int x = min(rowSum[i], colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
            if(rowSum[i] == 0) i ++;
            if(colSum[j] == 0) j ++;
            if(i >= n || j >= m) break;
        }
        return ans;
    }
};