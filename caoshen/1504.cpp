#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(const string& s1, const string& s2) {
    return s1 + s2 < s2 + s1;
}

void minNum(const vector<int>& a) {
    vector<string> vs;
    for (int i = 0; i < a.size(); ++i) {
        stringstream ss;
        ss << a[i];
        vs.push_back(ss.str());
    }
    sort(vs.begin(), vs.end(), cmp);
    copy(vs.begin(), vs.end(), ostream_iterator<string>(cout));
}
int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        minNum(a);
        cout << endl;
    }
    return 0;
}
