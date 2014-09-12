#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

long merge(vector<int>& ivec1, vector<int>& ivec2, vector<int>& ivec) {
	long m, n, cnt = 0;
	m = ivec1.size(), n = ivec2.size();
	int i, j, k = 0;
	for (i = 0, j = 0; i < m && j < n;) {
		if (ivec1[i] <= ivec2[j]) {
			ivec[k] = ivec1[i];
			++i;
		}
		else {
			ivec[k] = ivec2[j];
			++j;
			cnt += m - i;
		}
		++k;
	}
	if (i == m)
		copy(ivec2.begin() + j, ivec2.end(), ivec.begin() + k);
	else
		copy(ivec1.begin() + i, ivec1.end(), ivec.begin() + k);
	return cnt;
}

long reverseSort(vector<int>& ivec) {
	int n = ivec.size();
	if (n == 1 || n == 0)
		return 0;
	vector<int> leftPart(ivec.begin(), ivec.begin() + n / 2);
	vector<int> rightPart(ivec.begin() + n / 2, ivec.end());
	long left = reverseSort(leftPart);
	long right = reverseSort(rightPart);
	long cnt = merge(leftPart, rightPart, ivec);
	return left + right + cnt;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> iv;
		for (int i = 0; i < n; ++i) {
			int num;
			scanf("%d", &num);
			iv.push_back(num);
		}
		cout << reverseSort(iv) << endl;
	}
	return 0;
}
