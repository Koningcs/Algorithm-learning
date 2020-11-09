
/*

https://leetcode-cn.com/problems/furthest-building-you-can-reach/

我的思路是 二分答案, 然后贪心check, 复杂度是log(n)*n*log(n)

官解n*log(n)
核心问题是前K大的gap 要用梯子, 剩下的用砖块. 
问题就成了 如何找到前K大
*/

class Solution {
public:

    priority_queue<int, vector<int>, greater<int> > q2; //小
   

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        while( !q2.empty() ) q2.pop();
        int n = heights.size();
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n-1; i ++) {
            int x = heights[i+1] - heights[i];
            if(x > 0) {

                if(q2.size() < ladders) q2.push(x);
                else {
                    if(!q2.empty() && q2.top() < x) {
                        bricks -= q2.top();
                        q2.pop();
                        q2.push(x);
                    }
                    else bricks -= x;
                }
                if(bricks < 0) break;
            }
            ans = i + 1;
        }
        return ans;
    }
};