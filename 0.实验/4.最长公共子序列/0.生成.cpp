/*************************************************************************
	> File Name: 0.生成.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月28日 星期一 21时53分24秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

void generate(int num) {
    int tmp;
    for (int i = 0; i < num; i++) {
        int op = rand() % 2;
        if (op) {
            tmp = rand() % 26 + 65;
        } else {
            tmp = rand() % 26 + 97;
        }
        printf("%c", char(tmp));
    }
}


int main() {
    srand(time(0));
    int m, n;
    cin >> m >> n;
    generate(m);
    cout << endl;
    generate(n);
    return 0;
}
