#include<cstdio>
#include<iostream>
#include<list>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

list<string> c;
char buf[10];

void test_list(long& value) {

    clock_t timeStart = clock();

    for(int i = 0; i < value; i ++) {
        try {
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        } catch(exception & p) {
            cout << "i = " << i << " " << p.what() << endl;
            abort();
        }
    }
    
    cout << "milli-seconds:" << (clock()-timeStart) << endl;
    cout << "list.size = " << c.size() << endl;
    cout << "list.max_size = " << c.max_size() << endl;
    cout << "list.front = " << c.front() << endl;
    cout << "list.back = " << c.back() << endl;
    
}

int main() {

    long a = 1000;
    test_list(a);

    return 0;
}