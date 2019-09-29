/*************************************************************************
	> File Name: generate.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年09月29日 星期日 15时03分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int Random(int a, int b) {
    int res = rand() % (b - a) + a;
    return res;
}

int main() {
    int num, a, b;
    cin >> num >> a >> b;
    for (int i = 0; i < num; i++) {
        i && cout << " ";
        cout << Random(a, b);
    }
    return 0;
}
