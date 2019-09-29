/*************************************************************************
	> File Name: 2_2选择排序.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年09月29日 星期日 14时48分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define max_n 1000000

int num[max_n + 5] = {0};

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int i = -1;
    while (~scanf("%d", &num[++i]));
    int len = i;
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i; j < len; j++) {
            if (num[j] < num[min]) min = j;
        }
        swap(num[min], num[i]);
    }
    for (int i = 0; i < len; i++) {
        i && cout << " ";
        cout << num[i];
    }
    //cout << endl;
    //cout << "sum: " << len << endl;
    return 0;
}
