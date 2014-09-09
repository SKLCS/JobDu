#include <iostream>
#include <cstdio>
using namespace std;
 
struct ListNode {
    ListNode(int x): val(x), next(NULL) {
    }
    int val;
    ListNode* next;
};
int findLastK(ListNode* head, int k) {
    ListNode* fast, *slow;
    slow = fast = head;
    if (k == 0)
        return -1;
    while (k--)
        if (fast)
            fast = fast -> next;
        else
            break;
    if (k > 0)
        return -1;
    while (fast) {
        fast = fast -> next;
        slow = slow -> next;
    }
    return slow -> val;
}
 
int main() {
    int n, k;
    while (cin >> n >> k) {
        int i;
        ListNode dummy(0), *p;
        p = &dummy;
        for (i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            p -> next = new ListNode(x);
            p = p -> next;
        }
        int r = findLastK(dummy.next, k);
        if (r == -1)
            cout << "NULL" << endl;
        else
            cout << r << endl;
    }
    return 0;
}