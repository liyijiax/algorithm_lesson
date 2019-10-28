/*************************************************************************
	> File Name: 3.贪重量.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月29日 星期二 00时57分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 10000000

typedef struct term {
    int v = 0;
    int w = 0;
    double vw;
    int flag = 0;
    int num;
}term;

term all[max_n + 5];

bool cmp(term a, term b) {
    return a.w > b.w;
}

int main() {
    int i = 0, cnt, bagV, load = 0;
    cin >> cnt >> bagV;
    for (int i = 0; i < cnt; i++) scanf("%d", &all[i].v), all[i].num = i;
    for (int i = 0; i < cnt; i++) scanf("%d", &all[i].w);
    for (int j = 0; j < cnt; j++) all[j].vw = 1.0 * all[j].v / all[j].w;
    sort(all, all + cnt, cmp);
    i = 0;
    while (load < bagV && i <= cnt) {
        if (all[i].w <= bagV - load) {
            load -= all[i].w;
            all[i].flag = 1;
            i++;
        } else {
            i++;
            continue;
        }
    }
    int sum = 0;
    cout << "selected:" << endl;
    for (int i = 0; i < cnt; i++) {
        if (all[i].flag) sum += all[i].v;
        //cout << "NUM" << all[i].num << " Weight:" << all[i].w 
        //<< " Value:" << all[i].v << endl 
    }
    cout << "贪重量总价值：" << sum << endl;
    return 0;
}
