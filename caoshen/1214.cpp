#include <iostream>
using namespace std;

const int MAXN = 1500 + 5;
int a[MAXN];

inline int min(int a, int b, int c) {
    return a > b ? (b > c ? c : b) : ( a > c ? c : a);
}

void uglyNum() {
    a[0] = 1;
    int p2, p3, p5;
    p2 = p3 = p5 = 0;
    for (int i = 0; i < MAXN; ++i) {
        int minU = min(a[p2] * 2, a[p3] * 3, a[p5] * 5);
        a[i + 1] = minU;
        while (a[p2] * 2 <= minU) ++p2;
        while (a[p3] * 3 <= minU) ++p3;
        while (a[p5] * 5 <= minU) ++p5;
    }
}
int main() {
    uglyNum();
    int n;
    while (cin >> n) {
        cout << a[n - 1] << endl;
    }
    return 0;
}
