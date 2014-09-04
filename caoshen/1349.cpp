#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxN = 1000000 + 1;
int count[maxN];

int main() {
	int n;
	while (cin >> n) {
		memset(count, 0, sizeof(count));
		int num, i = 0;
		for (; i < n; ++i) {
			scanf("%d", &num);
			++count[num];
		}
		int m;
		cin >> m;
		while (m--) {
			int q;
			scanf("%d", &q);
			printf("%d\n", count[q]);
		}
	}
	return 0;
}
