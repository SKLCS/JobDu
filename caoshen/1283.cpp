#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <cstdio>
using namespace std;

int cnt[26];
int pos[26];

int main() {
	string s;
	while (cin >> s) {
		memset(cnt, 0, sizeof(cnt));
		memset(pos, -1, sizeof(pos));
		for (int i = 0; i < s.size(); ++i) {
			int c = s[i] - 'A';
			if (cnt[c] == 0)
				pos[c] = i;
			++cnt[c];
		}
		int minpos = INT_MAX;
		for (int i = 0; i < 26; ++i)
			if (cnt[i] == 1 && minpos > pos[i]) {
				minpos = pos[i];
			}
		if (minpos == INT_MAX)
			cout << "-1" << endl;
		else
			cout << minpos << endl;
	}
	return 0;
}