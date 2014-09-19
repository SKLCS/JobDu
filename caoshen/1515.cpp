#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

void printNum(string num) {
    int i = 0;
    for (; i < num.size() && num[i] == '0'; ++i);
    if (i == num.size()) return;
    for (int j = i; j < num.size(); ++j)
        printf("%c", num[j]);
    printf("\n");
}

void dfs(int index, int n, string& num) {
    if (index == n) {
        printNum(num);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        num[index] = i + '0';
        dfs(index + 1, n, num);
    }
}

void printAll(int n) {
    if (n <= 0)
        return;
    string num(n, '0');
    dfs(0, n, num);    
}

int main() {
    int n;
    while (cin >> n) {
        printAll(n);
    }
    return 0;
}
