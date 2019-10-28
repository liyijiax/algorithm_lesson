/*************************************************************************
	> File Name: 4.直接地柜.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月28日 星期一 21时38分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;
#define max_n 1000000

char x[max_n];
char y[200];
int c[max_n][200];

int lcs(int i, int j) {
    if (i == 0 || j == 0) {
        c[i][j] = 0;
        return c[i][j];
    }
    if (x[i] == y[j]) {
        c[i][j] = lcs(i - 1, j - 1) + 1;
    } else {
        c[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    }
    return c[i][j];
}

int main() {
    cin >> x >> y;
    int m = strlen(x);
    int n = strlen(y);
    int len = lcs(m, n);
    cout << len;
    return 0;
}
