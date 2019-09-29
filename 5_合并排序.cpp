#include <iostream>
#include <cstring>
#include "bs2.h"
using namespace std;
#define max_n 100000

int res[max_n + 5] = {0};

void merge(int *num, int l, int mid, int r) {
    int left = l, right = mid + 1, p = l;
    while (left <= mid && right <= r) {
        if (num[left] < num[right]) res[p++] = num[left++];
        else res[p++] = num[right++];
    }
    while (left <= mid) res[p++] = num[left++];
    while (right <= r) res[p++] = num[right++];
    int flag = 0;
    /*
    for (int i = l; i <= r; i++) {
        flag && cout << " ";
        flag = 1;
        cout << res[i];
    }*/
    cout << endl;
    for (int i = l; i <= r; i++) num[i] = res[i];
    return ;
}

void merge_sort(int *num, int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    merge(num, l, mid, r);
    return ;
}

int main() {
    int len = sizeof(num) / sizeof(num[0]);
    merge_sort(num, 0, len - 1);
    for (int i = 0; i < len; i++) cout << res[i] << endl;
    return 0;
}
