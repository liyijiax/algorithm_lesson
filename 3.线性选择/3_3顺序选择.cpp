/*************************************************************************
	> File Name: 3_3顺序选择.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年09月30日 星期一 08时16分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 1000000

int num[max_n + 5] = {0};

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int i = -1, k;
    cin >> k;
    while(~scanf("%d", &num[++i]));
    int len = i;
    for (int i = 0; i < k; i++) {
        int min = i;
        for (int j = i; j < len; j++) {
            if (num[min] < num[j]) min = j;
        }
        swap(num[min], num[i]);
    }
    return 0;
}
