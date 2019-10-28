/*************************************************************************
	> File Name: 1.dp.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月28日 星期一 21时35分55秒
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
int b[max_n][200];

void lcs_len(int c[][200], int b[max_n][200], int m, int n) {
    for (int i  = 1; i <= m; i++) c[i][0] = 0;
    for (int j  = 1; j <= n; j++) c[0][j] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1; //斜向
            } else if (c[i-1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2; //向上
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3; //向←
            }
        }
    }
}

void lcs(char *x, int b[][200], int i, int j) {
    if (i == 0 || j == 0) return ;
    if (b[i][j] == 1) {
        lcs(x, b, i - 1, j - 1);
        cout << x[i];
    } else if (b[i][j] == 2) {
        lcs(x, b, i - 1, j);
    } else {
        lcs(x, b, i, j - 1);
    }
}

int main() {
    cin >> x >> y;
    int m = strlen(x);
    int n = strlen(y);
    lcs_len(c, b, m, n);
    lcs(x, b, m, n);
    cout << endl;
    return 0;
}
