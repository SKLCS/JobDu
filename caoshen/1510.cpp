#include <iostream>
#include <string>
using namespace std;

string replaceBlank(string s) {
	int n = s.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == ' ')
			++cnt;
	int m = n + cnt * 2;
	string ret(m, ' ');
	
	for (int i = n - 1, j = m - 1; i >= 0;) {
		if (s[i] == ' ') {
			ret[j--] = '0';
			ret[j--] = '2';
			ret[j--] = '%';
			--i;
		}
		else {
			ret[j--] = s[i];
			--i;
		}
	}
	return ret;
}
int main() {
	string s;
	while (getline(cin, s)) {
		cout << replaceBlank(s) << endl;
	}
	return 0;
}
