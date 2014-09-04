#include <iostream>
using namespace std;

typedef unsigned int (*fun) (unsigned int);

unsigned int Solution3_Teminator(unsigned int n) {
    return 0;
}

unsigned int Sum_Solution3(unsigned int n) {
    fun f[2] = {Solution3_Teminator, Sum_Solution3};
    return n + f[!!n](n - 1);
}

int main() {
    int n;
    while (cin >> n)
        cout << Sum_Solution3(n) << endl;
    return 0;
}    