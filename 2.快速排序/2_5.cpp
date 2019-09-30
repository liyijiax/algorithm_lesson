/*************************************************************************
	> File Name: 2_5.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年09月30日 星期一 09时25分23秒
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
	for (int i = 0; i < len;i++) {                 
		for (int j = 0; j < len - i;j++) {     
			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	return 0;
}

