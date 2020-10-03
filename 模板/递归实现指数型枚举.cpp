#include<iostream>
using namespace std;
int n;
void dfs(int u, int state) {

    if(u == n) {
        for(int i = 0; i < n; i ++)
            if( state>>i & 1 ) 
                cout << i+1 << " ";
        cout << endl;
        return;
    }
    dfs(u + 1, state);
    dfs(u + 1, 1 << u | state);
}

int main() {

    cin >> n;
    dfs(0, 0);
    return 0;
}
//https://www.acwing.com/problem/content/94/