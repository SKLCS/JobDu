#include <iostream>
#include <cstdio>
using namespace std;
 
struct ListNode {
    ListNode(int v): val(v), next(NULL){
    }
    int val;
    ListNode* next;
};
 
void printList(ListNode* p) {
    if (p == NULL)
        return;
    printList(p -> next);
    printf("%d\n", p -> val);
}
 
int main() {
    int num;
    ListNode list(0);
    ListNode* p = &list;
    while (scanf("%d", &num) != EOF) {
        if (num == -1)
            break;
        p -> next = new ListNode(num);
        p = p -> next;
    }
    printList(list.next);
    return 0;
}