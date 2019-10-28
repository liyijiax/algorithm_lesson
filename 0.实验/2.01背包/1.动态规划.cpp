/*************************************************************************
	> File Name: 1.动态规划.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月29日 星期二 00时53分48秒
 ************************************************************************/
#include<iostream>
using namespace std;
#include <algorithm>
#define max_n 1000000

int v[max_n + 5];
int w[max_n + 5];
double vw[max_n + 5];
int dp[7000][70000] = {0};
int main()
{
    int i = 0, cnt, bagV;
    cin >> cnt >> bagV;
    for (int i = 0; i < cnt; i++) scanf("%d", &v[i]);
    for (int i = 0; i < cnt; i++) scanf("%d", &w[i]);
    
	for (int i = 1; i < cnt; i++) {
		for (int j = 1; j <= bagV; j++) {
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

    cout << "DP最大价值" << endl;
    cout << dp[cnt][bagV + 1] << endl;
for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
 
	return 0;
}
