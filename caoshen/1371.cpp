#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <iterator>
using namespace std;

typedef priority_queue<int, vector<int>, less<int> > pHeap;

void findK(const vector<int>& data, pHeap& leastNumbers, int k) {
    if (k < 1 || data.size() < k)
        return;
    for (vector<int>::const_iterator it = data.begin(); it != data.begin() + k; ++it)
        leastNumbers.push(*it);
    for (vector<int>::const_iterator it = data.begin() + k; it != data.end(); ++it)
        if (*it < leastNumbers.top()) {
            leastNumbers.pop();
            leastNumbers.push(*it);
        }
}

void print( pHeap& h) {
    if (h.empty()) return;
    int e = h.top();
    h.pop();
    bool f = h.empty();
    print(h);
    if (f)
        cout << e ;
    else
        cout << " " << e ;
   
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n , 0);
        pHeap h;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        findK(a, h, k);
        print(h);
        cout << endl;
    }
    return 0;
}