#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        double PI = atan(1)*4;
        int x = location[0], y = location[1];
        
        int ans = 0;
        
        vector<double> angles;
        int n = points.size();
        for(int i = 0; i < n; i ++) if(x == points[i][0] && y == points[i][1]) ans++;
       
        for(int i = 0; i < n; i ++) {
            if(x == points[i][0] && y == points[i][1]) continue;
            double ang = atan2(points[i][1] - y, points[i][0] - x);
            angles.push_back(ang * 180/PI) ;
        }
        
        sort(angles.begin(), angles.end());
        int i = 0, j = 0;
        int maxn = 0;
        int k = angles.size();
        printf("%d\n",k);
        for(int i = 0; i < k; i ++) printf("%lf\n",angles[i]);
        while(i < k) {
            double last = angles[i] + angle*1.0;
            while( j < k && angles[j] < last + 0.0001 ) j++;
            maxn = max(maxn, j - i);
            i++;
        }
        
        ans += maxn;
        return ans;
    }
};