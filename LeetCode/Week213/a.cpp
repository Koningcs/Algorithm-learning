
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