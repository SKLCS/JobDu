#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		stack<int> st, stMin;
		while (n--) {
			string s;
			cin >> s;
			if (s == "s") {
				int num;
				cin >> num;
				if (st.empty()) {
					st.push(num);
					stMin.push(num);
					cout << num << endl;
					continue;
				}
				if (num <= stMin.top()) {
					st.push(num);
					stMin.push(num);
				}
				else {
					st.push(num);
				}
				cout << stMin.top() << endl;
			}
			else if (s == "o") {
				if (st.empty()) {
					cout << "NULL" << endl;
					continue;
				}
				int x = st.top(), y = stMin.top();
				st.pop();
				if (x == y) {
					stMin.pop();
					if (stMin.empty())
						cout << "NULL" << endl;
					else
						cout << stMin.top() << endl;
				}
				else
					cout << y << endl;
			}
		}
	}
	return 0;
}
