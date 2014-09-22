#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>
using namespace std;

int numberOfOne(const string& num, int index) {
    int n = num.size() - index;
    if (n == 0 || !isdigit(num[index]))
        return 0;
    int first = num[index] - '0';
    if (n == 1 && first == 0)
        return 0;
    if (n == 1 && first > 0)
        return 1;
        
    int numOfFirst = 0;
    if (first > 1 )
        numOfFirst =  pow(10, n - 1);
    else if (first == 1){
        numOfFirst = atoi(num.substr(index + 1).c_str()) + 1;
    }
    int numOfOthers = first * (n - 1) * pow(10, n - 2);
    int numRecursive = numberOfOne(num, index + 1);
    return numOfFirst + numOfOthers + numRecursive;
}

void swap (int& a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a > b) swap(a, b);
        stringstream ss1, ss2;
        ss1 << (a - 1);
        ss2 << b;
        int n = numberOfOne(ss2.str(), 0);
        int m = numberOfOne(ss1.str(), 0);
        cout << n - m << endl;
    }
    return 0;
}
