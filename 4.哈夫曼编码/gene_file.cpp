/*************************************************************************
	> File Name: gene_file.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月04日 星期一 16时33分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_n 100

int main() {
    srand(time(0));
    for (int i = 0; i < max_n; i++) {
        for (int j = 1; j < 26; j += 2) {
            for (int k = 0; k < j; k++) {
                int op = rand() % 2;
                printf("%c", op + j - 1 + 'a');
            }
        }
    }
    return 0;
}
