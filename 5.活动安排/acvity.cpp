/*************************************************************************
	> File Name: acvity.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月04日 星期一 20时33分40秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include <set>
#define max_n 100000

struct Act {
    int no, s, f;
    bool operator<(const Act &a) const {
        if (f - a.f) return f < a.f;
        if (s - a.s) return s < a.s;
        return no - a.no;
    }
} arr[max_n + 5];

int main() {
    set<Act> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].no, &arr[i].s, &arr[i].f);
        s.insert(arr[i]);
    }
    int pre = 0;
    while (s.size()) {
        while (s.size() && s.begin()->s < pre) s.erase(s.begin());
        if (s.size() == 0) break;
        cout << s.begin()->no << " ";
        pre = s.begin()->f;
        s.erase(s.begin());
    }
    return 0;
}

