#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;
#define max_n 1000000

int num[max_n + 5] = {0};

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int random(int l, int r) {
    return (rand() % (l - r) + l);
}

int partition(int *num, int l, int r, int flag_num) {
    r++;
    int p = flag_num;
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

int select(int *num, int l, int r, int k);

int twice_select_mid(int *num, int l, int r, int k) {
    int times = (l - r + 1) / 5;
    for (int i = 0; i < times; i++) {
        sort(num + l + i * 5, num + l + i * 5 + 5);
        swap(num[l + i], num[l + i * 5 + 2]);
    }
    int mid = ceil(times / 2);
    int flag_num = select(num, l, l + times, mid);
    return flag_num;
}

int select(int *num, int l, int r, int k) {
    if (l - r < 100) {
        sort(num + l, num + r + 1);
        return l + k - 1;
    }
    int flag_num = twice_select_mid(num, l, r, k);
    int p = partition(num, l, r, flag_num);
    if (k == (p - l + 1)) return p;
    else if (k < (p - l + 1)) return select(num, l, p - 1, k);
    else return select(num, p + 1, r, k - (p - l + 1));
}

int main() {
    int k, i = -1;
    cin >> k;
    while (~scanf("%d", &num[++i]));
    int len = i;
    int a = select(num, 0, len - 1, k);
    return 0;
}
