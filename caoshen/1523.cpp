#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

struct TreeNode {
    TreeNode(int v): val(v), left(0), right(0) {
    }
    int val;
    int left, right;
};

void bfs(int n, const vector<TreeNode>& t, vector<int>& ret) {
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ret.push_back(t[x].val);
        if (t[x].left)
            q.push(t[x].left);
        if (t[x].right)
            q.push(t[x].right);
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<TreeNode> t(n + 1, TreeNode(0));
        for (int i = 0; i < n; ++i) {
            int num = 0;
            scanf("%d", &num);
            t[i + 1] = TreeNode(num);
        }
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (s == "d") {
                scanf("%d %d", &t[i + 1].left, &t[i + 1].right);
            }
            else if (s == "z")
                continue;
            else if (s == "l") {
                scanf("%d", &t[i + 1].left);
            }
            else {
                scanf("%d", &t[i + 1].right);
            }
        }
        vector<int> ret;
        bfs(1, t, ret);
        for (int i = 0; i < ret.size(); ++i)
            if (i == ret.size() - 1)
                printf("%d\n", ret[i]);        
            else
                printf("%d ", ret[i]);
    }
    return 0;
}
