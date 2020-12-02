#include<cstdio>
#include<iostream>
using namespace std;


int a[100005];
int n;
int tr[100005];
int lowbit(int x) {return x & -x;}
void add(int x , int c) {
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}
int sum(int x) {
    int res = 0;
    for(int i = x; i > 0; i -=lowbit(i)) res += tr[i];
    return res;
}
int main() {

    cin >> n;
    
    for(int i =  2; i <= n; i ++) {
        cin >> a[i];
        add(i, 1);
    }
    add(1,1);
    for(int i = n; i >= 1; i --) {

        int l = 1; int r = n;
        while(l < r) {
            int mid = l + r >> 1;
            if(sum(mid) > a[i]) r = mid;
            else l = mid + 1;
        }
        a[i] = l;
        add(l , -1);
    }
    for(int i = 1; i <= n; i ++) {
        if(sum(i) == 1) {
            a[1] = i; break;
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << a[i] << endl;
    }
    return 0;
}