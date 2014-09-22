#include <iostream>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

int findSum(const vector<int>& a, int& mBegin, int& mEnd) {
    int cur = 0, ret = INT_MIN;
    int begin = 0, end = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (cur + a[i] >= a[i]) {
            cur += a[i];
            end = i;
        }
        else {
            cur = a[i];
            begin = end = i;
        }
        if (cur > ret) {
            ret = cur;
            mBegin = begin;
            mEnd = end;
        }
    }
    return ret;
}

int main() {
    int n;
    while (cin >> n, n) {
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int mSum = 0, mBegin = 0, mEnd = 0;
        mSum = findSum(a, mBegin, mEnd);
        cout << mSum << " " << mBegin << " " << mEnd << endl;
    }
    return 0;
}
