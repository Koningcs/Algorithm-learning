#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct node {

    int x, y;
    node(int x, int y):x(x), y(y){}
    bool operator< (const node &a ) const {
        return a.x < x; 
    }

};


priority_queue<int> q_default;//默认是大顶堆序
priority_queue<int,vector<int>,less<int> >q;//大顶堆
priority_queue<int,vector<int>,greater<int> > q2;//小顶堆
priority_queue<node> q3;//重载运算符的优先队列， x小在前

void fun() {
    priority_queue<int> q;
    q.top();//取队列首元素，也就是堆顶元素
    q.empty();//判断队列是否为空
    q.size();//返回队列的元素个数
    q.push(1);//向优先队列中插入一个元素
    q.pop();//弹出队列头元素
}
int mian() {
    return 0;
}