
#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    char ch;
    map<char, int> m;
    while (scanf("%c", &ch) != EOF) {
        if (ch < 'a' || ch > 'z') continue;
        m[ch] += 1;
    }
    cout << m.size() << endl;
    for (auto iterator = m.begin(); iterator != m.end(); iterator++) {
        cout << iterator->first << " " << iterator->second << endl;
    }
    return 0;
}
