#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1000010;
int Tire[N][26], idx = 0, cnt[N];

void Insert(char str[]) {

    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a'; 
        if( !Tire[p][u] ) Tire[p][u] = ++ idx;
        p = Tire[p][u];
    }
    cnt[p] ++;
}

int Serach(char str[]) {
    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if( !Tire[p][u] ) return 0;
        p = Tire[p][u];
    }
    return cnt[p];
}

int main() {


    int n;
    cin >> n;
    char c[10];
    for(int i = 0; i < n; i ++) {
        cin >> c;
        Insert(c);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i ++) {
        cin >> c;
        cout << Serach(c) << endl;
    }

    return 0;
}


/*
abcd
acd
aaaa
bced
ed
feh

*/