/*************************************************************************
	> File Name: generate.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月04日 星期一 20时42分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;

int main() {
    srand(time(0));
    int max_op;
    cin >> max_op;
    printf("%d\n", max_op);
    for (int i = 0; i < max_op; i++) {
        int s = rand() % 1000;
        int f = s + rand() % 100;
        printf("%d %d %d\n", i, s, f);
    }
    return 0;
}
