#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int main() {

    int ia[6] = {27, 210, 12, 47, 109, 83};
    vector<int, allocator<int> > vi(ia, ia + 6);
    //cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
    

    for(int i : {2, 3, 5, 7, 9, 13, 17, 19}) {
        cout << i << endl;
    }
    std::vector<double> vec;
    for( auto elem : vec) {
        cout << elem << endl;
    }    
    return 0;
}