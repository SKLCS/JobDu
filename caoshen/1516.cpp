#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void arrange(vector<int>& iv) {
	int n = iv.size();
	vector<int> t(n, 0);
	int j = 0, k = n - 1;
	for (int i = 0; i < n; ++i) {
		if (iv[i] & 1)
			t[j++] = iv[i];
		else 
			t[k--] = iv[i];
	}
	reverse(t.begin() + j, t.end());
	iv = t;
}

int main () {
	int n;
	while (cin >> n) {
		vector<int> iv;
		while (n--) {
			int num;
			scanf("%d", &num);
			iv.push_back(num);
		}
		arrange(iv);
		int len = iv.size();
		for (int i = 0; i < len; ++i)
			if (i == len - 1)
				printf("%d", iv[i]);
			else
				printf("%d ", iv[i]);
		cout << endl;
	}
	return 0;
}
