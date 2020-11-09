
/*

给你一个整数数组 arr ，数组中的每个整数 互不相同 。
另有一个由整数数组构成的数组 pieces，其中的整数也 互不相同 。
请你以 任意顺序 连接 pieces 中的数组以形成 arr 。
但是，不允许 对每个数组 pieces[i] 中的整数重新排序。

如果可以连接 pieces 中的数组形成 arr ，返回 true ；否则，返回 false



模拟
*/


class Solution {
public:
    int vis[104];
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int i = 0;
        int m = pieces.size();
        vector<string> s1;
        vector<string> s2;

        int flag = 1;


        for(int  i = 0; i < m; i ++) vis[i] = 0;
        while(i < n) {

            for(int j = 0; j < m; j ++) {
                if(!vis[j] &&  arr[i] == pieces[j][0]) {
                    vis[j]  = 1;
                    if(pieces[j].size() == 1) {
                        break;
                    }
                    else {
                        int k;
                        for(int k = 0; k < pieces[j].size(); k ++) {
                            if(arr[i] != pieces[j][k]) {
                                flag = 0;
                            }
                            i++;
                            if(flag == 0) break;
                        }
                        i--;
                    }

                }
            }

            if(flag == 0) break;
            i++;
        }

        for(int i = 0; i < m; i ++) {
            if(vis[i] == 0) flag = 0;
        }
        return flag;
    }
};