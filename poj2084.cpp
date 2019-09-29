#include <iostream>
#include <cstdio>
using namespace std;
typedef long long intl;

intl catalan(int n) {
    intl ans = 1;
    int big = 2 * n;
    int small = n;
    while (big > n) {
        ans *= (big--);
        //cout << ans << " " << big << " " << small << endl;
        while (ans % small == 0 && small > 1) ans /= small--;
    }
    //cout << "-----" << endl;
    while(ans % small == 0 && small > 1) ans /= small--;
    return ans / (n + 1);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n == -1) break;
        cout << catalan(n) << endl;
    }
    return 0;
}
