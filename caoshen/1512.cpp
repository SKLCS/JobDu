#include <iostream>
#include <stack>
using namespace std;

template <typename T> class qu {
public:
	void appendTail(const T&);
	T popFront();
private:
	stack<T> stack1, stack2;
};

template <typename T> void qu<T> :: appendTail(const T& element) {
	stack1.push(element);
}

template <typename T> T qu<T> :: popFront() {
	if (stack2.empty()) {
		while (!stack1.empty()) {
			T e = stack1.top();
			stack1.pop();
			stack2.push(e);
		}
	}
	if (!stack2.empty()) {
		T e = stack2.top();
		stack2.pop();
		return e;
	}
	else {
		throw -1;
	}
	
}

int main() {
	int n;
	while (cin >> n) {
		qu<int> q;
		while (n--) {
			string s;
			cin >> s;
			if (s == "PUSH") {
				int num;
				cin >> num;
				q.appendTail(num);
			}
			else {
				try {
					int t = q.popFront();
					cout << t << endl;
				} catch (int e) {
					cout << e << endl;
				}
			}
		}
	}
	return 0;
}