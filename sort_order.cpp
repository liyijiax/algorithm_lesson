/*************************************************************************
	> File Name: sort_order.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年09月30日 星期一 08时00分47秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 1000000

int num[max_n + 5] = {0};

int main() {
    int i = -1;
    while (~scanf("%d", &num[++i]));
    int len = i;
    sort(num, num + len);
    for (int i = 0; i < len; i++) {
        i && cout << " ";
        cout << num[i];
    }
    return 0;
}
