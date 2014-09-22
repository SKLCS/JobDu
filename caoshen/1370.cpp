#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool isHalf(const vector<int>& a, const int& t) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
        if (t == a[i])
            ++cnt;
    return 2 * cnt > a.size();
}

int findHalf(const vector<int>& a) {
    if (a.size() == 0)
        return -1;
    int cur = a[0], cnt = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (cnt == 0) {
            cur = a[i];
            cnt = 1;
        }
        else if (a[i] == cur)
            ++cnt;
        else
            --cnt;
    }
    if (isHalf(a, cur))
        return cur;
    else
        return -1;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        cout << findHalf(a) << endl;    
    }
    return 0;
}
