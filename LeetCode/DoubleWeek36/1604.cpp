#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;



class Solution {
public:
    int getTime(string s) {
        return ( (s[0]-'0') *10 + (s[1]-'0') )*60 + (s[3]-'0') *10 + (s[4]-'0');
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int> > mp;
        int n = keyName.size();
        vector<string> ans;
        for(int i = 0; i < n; i ++) {
            mp[keyName[i]].push_back(getTime(keyTime[i]));  
        }    

        for(auto it = mp.begin(); it != mp.end(); it++) {
            sort(it->second.begin(), it->second.end());
            for(int i = 0; i < it->second.size()-2; i ++) {
                if(it->second[i+2] - it->second[i] <= 60) {
                    ans.push_back(it->first);
                    break;
                }
            }
        } 
        return ans;
    }
};