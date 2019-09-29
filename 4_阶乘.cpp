#include <iostream>
using namespace std;
#define max_n 10000

int num[max_n + 5] = {0};

int main() {
    int k;
    cin >> k;
    num[0] = 1, num[1] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= i;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (num[0] == j);
        }
    }
    for (int i = num[0]; i > 0; i--) cout << num[i];
    cout << endl;
    return 0;
}
