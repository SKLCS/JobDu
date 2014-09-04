#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T;
	while (scanf("%d", &T) != EOF) {
		while (T--) {
			int n, count = 0;
			scanf("%d", &n);
			while (n) {
				n &= n - 1;
				++count;
			}
			printf("%d\n", count);
		}
	}
	return 0;
}