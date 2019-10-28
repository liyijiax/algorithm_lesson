/*************************************************************************
	> File Name: 0.生成.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月29日 星期二 02时14分19秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    srand(time(0));
    cout << endl;
    for (int i = 0; i < cnt; i++) {
        int tmp = rand() % 100;
        cout << tmp << " ";
    }
    for (int i = 0; i < cnt; i++) {
        int tmp = rand() % 100;
        cout << tmp << " ";
    }
    return 0;
}
