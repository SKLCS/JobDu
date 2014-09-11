#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int findLastOne(int a) {
	int i;
	for (i = 0; i < 32; ++i) {
		if (a & 1)
			break;
		a >>= 1;
	}
	return i;
}

int isOne(int a, int index) {
	return (a >> index) & 1;
}

int findTwo(const vector<int>& ivec, int& a, int& b) {
	int n = ivec.size();
	if (n == 0)
		return -1;
	int result = 0, i = 0;
	for (; i < n; ++i)
		result ^= ivec[i];
	int index = findLastOne(result);
	for (i = 0; i < n; ++i) {
		if (isOne(ivec[i], index))
			a ^= ivec[i];
		else
			b ^= ivec[i];
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> iv;
		while (n--) {
			int t;
			scanf("%d", &t);
			iv.push_back(t);
		}
		int a = 0, b = 0;
		findTwo(iv, a, b);
		if (a < b)
			cout << a << " " << b << endl;
		else
			cout << b << " " << a << endl;
	}
	return 0;
}
