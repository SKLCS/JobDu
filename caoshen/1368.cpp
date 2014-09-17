#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
	TreeNode(int v, int l, int r) : val(v), left(l), right(r) {
	}
	int val;
	int left;
	int right;
};

void dfs(int root, int target, vector<int>& path,  vector<vector<int> >& ret, const vector<TreeNode>& treeArray) {
	target -= treeArray[root].val;
	path.push_back(root);
	if (treeArray[root].left == -1 && treeArray[root].right == -1) {
		if (target == 0)
			ret.push_back(path);
	}
	if (treeArray[root].left != -1)
		dfs(treeArray[root].left, target, path, ret, treeArray);
	if (treeArray[root].right != -1)
		dfs(treeArray[root].right, target, path, ret, treeArray);
	path.pop_back();
}

int main() {
	int n, k;
	while (cin >> n >> k) {
		vector<TreeNode> a(n + 1, TreeNode(0, 0, 0));
		for (int i = 0; i < n; ++i) {
			int v, l, r;
			cin >> v >> l >> r;
            if (l < r)
			    a[i + 1] = TreeNode(v, l, r);
            else
                a[i + 1] = TreeNode(v, r, l);
		}
		vector<vector<int> > ret;
		vector<int> path;
		dfs(1, k, path, ret, a);
		cout << "result:" << endl;
		for (int i = 0; i < ret.size(); ++i) {
			cout << "A path is found:" ;
			int m = ret[i].size();
			for (int j = 0; j < m; ++j) {
				cout << " " << ret[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
