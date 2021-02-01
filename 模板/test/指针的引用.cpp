#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;




void test1() {
    cout << "--------test1---------" << endl;
    int v = 1;
    int* p = &v;
    cout << *p << endl;
    (*p)++;
    cout << "*p = " <<  *p << endl;
    cout << "v = "  << v << endl;
}
void test2() {
    cout << "--------test2---------" << endl;
    int v = 1;
    int* q;
    q = &v;
    (*q) = 3;
    cout << v << endl;
}

void test3() {
    cout << "--------test3---------" << endl;
    int v = 1;
    int &q = v;
    int* p = &q;
    cout << v << endl;
}

void test4() {
    cout << "--------test4---------" << endl;
    int v = 1;
    int *p = &v;
    int* &rp = p; //指针的引用
    cout << *rp << endl;
};

int main() {

    //test1();
    //test2();
    //test3;
    test4();
    return 0;
}