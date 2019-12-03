/*************************************************************************
	> File Name: trans_code.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月04日 星期一 16时55分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string.h>
#include "file.h" 
using namespace std;
#include <map>

int main() {   
    map<char, char*> m;
    int n;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char *str = (char *)malloc(sizeof(char) * 10); //必须动态开辟
        char *code = (char *)malloc(sizeof(char) * 20);
        scanf("%s %s", str, code);
        m[str[0]] = code;
        cout << str[0] << " " << code << " " << m[str[0]] << endl;
    }
    int i = 0;
    int len = strlen(file);
    for (int i = 0; i < len; i++) {
        printf("%s", m[file[i]]);
    }
    return 0;
}
