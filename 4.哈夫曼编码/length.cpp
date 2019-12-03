/*************************************************************************
	> File Name: length.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月04日 星期一 19时50分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    int cnt = 0;
    char ch;
    while (scanf("%c", &ch) != EOF) {
        cnt++;
    }
    cout << "sum: " << cnt;
    return 0;
}
