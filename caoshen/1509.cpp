#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct TreeNode {
    TreeNode(int x): val(x), left(0), right(0) {
    }
    int val;
    TreeNode* left, *right;
};

TreeNode* buildTree() {
    int v;
    TreeNode* l, *r;
    scanf("%d", &v);
    if (v == 0)
        return 0;
    TreeNode* root = new TreeNode(v);
    root -> left = buildTree();
    root -> right = buildTree();
    return root;
}

bool getNodePath(TreeNode* root, int target, vector<int>& path) {
    if (root == NULL)
        return false;
    path.push_back(root -> val);
    if (root -> val == target)
        return true;
    if ( getNodePath(root -> left, target, path) || getNodePath(root -> right, target, path))
        return true;
    else {
        path.pop_back();
        return false;
    }
}
int main() {
    int n;
    cin >> n;
    while (n --) {
        TreeNode* root = buildTree();
        int t1, t2;
        cin >> t1 >> t2;
        vector<int> path1, path2;
        if (getNodePath(root, t1, path1) && getNodePath(root, t2, path2)) {
            int i;
            for (i = 0; i < path1.size() && i < path2.size() && path1[i] == path2[i]; ++i);
            cout << path1[i - 1] << endl;
        }
        else
            cout << "My God" << endl;
    }
    return 0;
}
