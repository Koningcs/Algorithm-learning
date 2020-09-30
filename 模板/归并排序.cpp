#include<cstdio>
#include<iostream>
using namespace std;

const int N = 1000010;

int n, q[N], tmp[N];

void merge_sort(int q[], int l, int r) {
    if (l >= r) return ;                            //如果区间元素没有或者只有一个

    int mid = l + r >> 1;                           //找到重点

    merge_sort(q, l, mid), merge_sort(q, mid+1, r); // 排左边右边

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for(int i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for(int i = 0; i < n; i ++) printf("%d", q[i]);
    
    return 0;
}


/*

    1.确定分界点
    2.递归排序left, night
    3. 归并 合二为一

*/