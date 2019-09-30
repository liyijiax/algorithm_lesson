/*************************************************************************
	> File Name: 2_4冒泡排序.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年09月30日 星期一 08时26分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 1000000

int num[max_n + 5] = {0};

void bubble_sort(int *num, int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i; j < len; j++) {
            if (num[j] < num[min]) min = j;
        }
        swap(num[i], num[min]);
    }
}

int main() {
    int i = -1;
    while(~scanf("%d", &num[++i]));
    int len = i;
    bubble_sort(num, len);
    /*for (int i = 0; i < len; i++) {
        i && cout << " ";
        cout << num[i];
    }*/
    return 0;
}
