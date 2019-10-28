/*************************************************************************
	> File Name: 2.暴力.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月28日 星期一 21时38分16秒
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
int xflag[max_n];
int yflag[200];

int lcs_len(int c[][200], int b[max_n][200], int m, int n) {
    int max_len;
    return max_len;
}

int main() {
    cin >> x >> y;
    int m = strlen(x);
    int n = strlen(y);
    int len = lcs_len(c, b, m, n);
    cout << len;
    return 0;
}

