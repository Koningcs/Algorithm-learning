
class Solution {
public:


    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int> > q2; //小
   

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        while( !q1.empty() ) q1.pop();
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