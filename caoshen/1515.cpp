// jobdu.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void printNumber(string s) {
	int n = 0, len = s.length();
	while (n < len && s[n] == '0')
		++n;
        if (n == len) return;
	int i = n;
	while (i < len) {
		printf("%c", s[i]);
		++i;
	}
	printf("\n");
}

void dfs(string& number, int n, int index) {
	if (index == n) {
		printNumber(number);
		//cout << number << endl;
		return;
	}
	for (int i = 0; i < 10; ++i) {
		number[index] = i + '0';
		dfs(number, n, index + 1);
	}
}

void printAll(int n) {
	if (n <= 0)
		return;
	string number(n, '0');
	dfs(number, n, 0);
}

int main()
{
	int n = 0;
	while (cin >> n)
		printAll(n);
	return 0;
}
