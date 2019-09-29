#include <iostream>
#include <cstring>
#include <cstdlib>
#include <random>
#include "bs2.h"
using namespace std;

int random(int l, int r) {
    return (rand() % (l - r) + l);
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

//一般
int partition(int *num, int l, int r) {
    r++;
    int p = l;
    while (l < r) {
        while (num[++l] < num[p]);
        while (num[--r] > num[p]);
        if (l > r) break;
        swap(num[l], num[r]);
    }
    swap(num[p], num[r]);
    return r;
}

//优化
int partition(int *num, int l, int r) {
    r++;
    int p = random(l, r);
    swap(num[p], num[l]);
    p = l;
    while (l < r) {
        while (num[++l] < num[p]);
        while (num[--r] > num[p]);
        if (l > r) break;
        swap(num[l], num[r]);
    }
    swap(num[p], num[r]);
    return r;
}

void quick_sort(int *num, int l, int r) {
    if (l < r) {
        int p = partition(num, l, r);
        quick_sort(num, l, p - 1);
        quick_sort(num, p + 1, r);
    }
}

int main() {
    int len = sizeof(num) / sizeof(num[0]);
    quick_sort(num, 0, len - 1);
    for (int i = 0; i < len; i++) {
        cout << num[i] << endl;
    }
    return 0;
}
