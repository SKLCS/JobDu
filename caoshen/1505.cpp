#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int findCommon(const vector<int>& a, const vector<int>& b) {
    if (a.size() < b.size())
        return findCommon(b, a);
    int m = a.size(), n = b.size();
    int d = m - n, i;
    for (i = d; i < m && a[i] != b[i - d]; ++i);
    if (i == m)
        return -1;
    else
        return a[i];
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<int> a(m, 0), b(n, 0);
        for (int i = 0; i < m; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);
        int c = findCommon(a, b);
        if (c == -1)
            cout <<  "My God" << endl;
        else
            cout << c << endl;
    }    
}
