#include <cstdio>
#include <iostream>
using namespace std;
void swap(int* p1,int* p2){
    int* tmp = p1;
    p1 = p2;
    p2 = tmp;
    cout << &p1 << " " << &p2 << endl;
    cout << p1 << " " << p2 << endl;
}

int main(){

    int a = 1; int b = 2;
    int* p1 = &a;
    int* p2 = &b;
    cout << &p1 << " " << &p2 << endl;
    cout << p1 << " " << p2 << endl;
    cout << a << b << endl;
    swap(p1, p2);
    cout << a << b << endl;
    cout << p1 << " " << p2 << endl;
    return 0;

}