#include <iostream>
#include <cstring>
#include <cstdlib>
#include <random>
#include "bs2.h"
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int random(int l, int r) {
    return (rand() % (l - r) + l);
}

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

int select(int *num, int l, int r, int k) {
    if (l == r) return num[l];
    int p = partition(num, l, r);
    if (k == (p - l + 1)) return num[p];
    else if (k < (p - l + 1)) return select(num, l, p - 1, k);
    else return select(num, p + 1, r, k - (p - l + 1));
}

int main() {
    int k;
    cin >> k;
    int len = sizeof(num) / sizeof(num[0]);
    cout << select(num, 0, len - 1, k) << endl;
    return 0;
}
