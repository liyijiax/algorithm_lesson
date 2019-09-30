#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


//递归
int binary_search(int *num, int l, int r, int obj) {
	if (l <= r) {
		int mid = (l + r) >> 1;
		if (num[mid] == obj) return mid;
		else if (num[mid] < obj) l = mid + 1;
		else r = mid - 1;
		return binary_search(num, l, r, obj);
	}
	return 0;
}
/*
//非递归
int binary_search(int *num, int l, int r, int obj) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (num[mid] == obj) return mid;
        else if (num[mid] < obj) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}*/

int main() {
    int obj, i = -1;
    cin >> obj;
    while (~scanf("%d", &num[++i]));
    int len = i;
    int ans = binary_search(num, 0, len - 1, obj);
    cout << ans + 1;
    return 0;
}
