/*************************************************************************
	> File Name: same.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月04日 星期一 19时53分29秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include "file.h"
using namespace std;
#include <map>

int main() {
    int n;
    map<char, char*> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
    cout << __LINE__ << endl;
        char str[20] = {0}, code[15] = {0}; 
        int num[10] = {0};
        scanf("%s %d", str, num);
        int t = i;
        int j = 0;
        while (i) {
            num[j++] = t % 2;
            t >>= 1;
        }
    cout << __LINE__ << endl;
        sprintf(code, "%d%d%d%d%d", num[4], num[3], num[2], num[1],num[0]);
        m[str[0]] = code;
    cout << __LINE__ << endl;
        cout << m[str[0]] << endl;
    cout << __LINE__ << endl;
    }
    cout << __LINE__ << endl;
    int len = strlen(file);
    for (int i = 0; i < len; i++) {
        printf("%s", m[file[i]]);
    }
    return 0;
}
