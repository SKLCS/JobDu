#include <iostream>
#include <vector>
using namespace std;

int isPostTree(const vector<int>& post, int left, int right) {
	if (left >= right)
		return 1;
	int root = post[right];
	int p = left;
	while (p < right && post[p++] < root);
	for (int i = p ; i < right; ++i)
		if (post[i] < root)
			return 0;
	if (p = left || p == right)
		return isPostTree(post, left, right - 1);
	else
		return isPostTree(post, left, left + p) && isPostTree(post, left + p, right - 1);
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			a.push_back(num);
		}
		if (isPostTree(a, 0, n - 1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
