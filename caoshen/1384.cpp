#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int findT(vector<vector<int> >& matrix, int t) {
	int m, n;
	m = matrix.size();
	n = matrix[0].size();
	int i = 0, j = n - 1;
	while (i < m && j >= 0) {
		int rtop = matrix[i][j];
		if (rtop == t)
			return true;
		else if (rtop > t) {
			--j;
		}
		else {
			++i;
		}
	}
	return false;
}

int main() {
	int m , n, t;
	while (cin >> m >> n) {
		cin >> t;
		vector<vector<int> > matrix(m, vector<int>(n, 0));
		int i, j;
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				scanf("%d", &matrix[i][j]);
		int f = findT(matrix, t);
		if (f)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
