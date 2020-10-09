#include<cstdio>
#include<iostream>
using namespace std;

class Solution {
public:
    int ans;
    int dp[50];
    
    void init() {
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= 30; i ++) {
            dp[i] = dp[i-1] * 2 + 1;
        }
    }
    int dfs(int x) {
        for(int i = 0; i <= 30; i ++) {
            if(x == dp[i] + 1) return dp[i+1];
        }
        int f = 0;
        for(int i = 30; i >= 0; i --) {
            if(x >= dp[i]+1) {
                f = i; break;
            }
        }
        return ( dfs(dp[f]+1) - dfs(x - (dp[f]+1)) );
        
    }
    int minimumOneBitOperations(int n) {
        ans = 0;
        init();
        if(n == 0) return 0;
        ans = dfs(n);
        return ans;

    }
};






int main() {

    Solution solve;
    int n;
    cin >> n;
    cout  <<  solve.minimumOneBitOperations(n) << endl; 

    return 0;
}


/*
打标找规律
class Solution {
public:
    int x;
    int ans = 0;
    void opt1() {
        x ^= 1;
        //cout << ans  << x << endl;
        ans++;
    }
    void opt2(int i) {
       
        x ^= (1 << i); //第i位取反
        //cout << ans << " " << x << endl;
        ans++;
    }
    void check(int i) {
       // cout << i  << x  << endl;
        if(i == 0) {
            opt1();
            return;
        }
        else {
            if( ((x >> (i-1)) & 1) == 0 ) {
                check(i-1);
            }
            for(int j = i-2; j >= 0; j -- ) {
                    if( ((x >> j) & 1) == 1 ) check(j);
                }
            opt2(i);
        }
        return;
    }
    int minimumOneBitOperations(int n) {
        x = n;
        ans = 0;
        for(int i = 31; i >= 0; i --) {
            //cout << x << endl;
            if( (x >> i) & 1 ) check(i);
        }
        return ans;
    }
};
*/