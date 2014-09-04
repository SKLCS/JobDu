#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int findM(vector<int>& A) {
    int n = A.size();
    int left, right;
    left = 0;
    right = n - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (A[left] == A[mid] && A[mid] == A[right])
            left += 1;
        else if (A[left] <= A[mid]) {
            if (A[mid] <= A[right])
                return A[left];
            else
                left = mid + 1;
        }
        else
            right = mid;
    }
    return A[left-1];
}

int main() {
    int t;
    while (cin >> t) {
        vector<int> A;
        int i = 0, n;
        for (; i < t; ++i) {
            scanf("%d", &n);
            A.push_back(n);
        }
        cout << findM(A) << endl;
    }
    return 0;
}