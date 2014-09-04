// jobdu.cpp : 定义控制台应用程序的入口点。
//



#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double power2(double base, int e) {
	if (e == 0)
		return 1;
	if (e == 1)
		return base;
	double result  = 1.0;
	result = power2(base * base, e >> 1);
	if (e & 1)
		result *= base;
	return result;
}

double power(double base, int e) {
	if ( e >= 0)
		return power2(base, e);
	else
		return 1.0/ power2(base, -e);
}

int main()
{
	int t = 0, e = 0;
	double base = 0;
	while (cin >> t) {
		while (t--) {
			cin >> base >> e;
			double result = 0;
			if (abs(base - 0.0) < 0.0000001)
				if (e >= 0)
					cout << setprecision(2) <<  setiosflags(ios::scientific) << result << "f" <<  endl;
				else
					cout << "INF" << endl;
			else
				//printf ("%.2ef\n", result);
				cout << setprecision(2) <<  setiosflags(ios::scientific) << power(base, e) << "f" << endl;
		}
	}
	return 0;
}
