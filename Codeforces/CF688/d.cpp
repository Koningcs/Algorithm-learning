#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


typedef long long ll;
ll p[100], n;
vector<ll> ans;
int main() {

    int t;
    cin >> t;
    p[0] = 2;
    for(int i = 1; i <= 60; i ++) {
        p[i] = p[i-1] * 2 + 2;
    }
    while(t--) {
        cin >> n;
        ans.clear();
        if(n & 1) {
            cout << -1 << endl;
            continue;
        }
        ll k = n - 2;
        ans.push_back(0);
        for(int i = 60; i >= 0; i --) {
            while(k >= p[i]) {

                k -= p[i];
                ans.push_back(i);
            }
        }
    
        int res = 0;
        for(int i = 0; i < ans.size(); i ++) {
            res += ans[i] +1;
        }
        cout << res << endl;
        for(int i = 0; i < ans.size(); i ++) {
            cout << 1 << " ";
            for(int j = 0; j < ans[i]; j++) cout << "0" << " "; 
        }


    }
    

}