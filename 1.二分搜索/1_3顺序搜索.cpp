/*************************************************************************
	> File Name: 1_3顺序搜索.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年09月30日 星期一 07时55分59秒
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
    int i = -1, obj;
    cin >> obj;
    while (~scanf("%d", &num[++i]));  
    int len = i;
    for (int i = 0; i < len; i++) {
        if (num[i] == obj) {
            break;
        }
    }
    //cout << i << endl;
    return 0;
}
