#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
	ListNode(int v): val(v), next(NULL){
	}
	int val;
	ListNode* next;
};

ListNode* merge(ListNode* head1, ListNode* head2) {
	ListNode dummy(0), *r;
	r = &dummy;
	while (head1 && head2) {
		if (head1 -> val < head2 -> val) {
			r -> next = head1;
			head1 = head1 -> next;
		}
		else {
			r -> next = head2;
			head2 = head2 -> next;
		}
		r = r -> next;
	}
	if (head1)
		r -> next = head1;
	else
		r -> next = head2;
	return dummy.next;
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) {
			printf("NULL\n");
			continue;
		}
		ListNode list1(0) , list2(0);
		ListNode* p = &list1, *q = &list2;
		int num;
		while (m--) {
			scanf("%d", &num);
			p -> next = new ListNode(num);
			p = p -> next;
		}
		while (n--) {
			scanf("%d", &num);
			ListNode t(num);
			q -> next = new ListNode(num);
			q = q -> next;
		}
		ListNode* r = merge(list1.next, list2.next);
		while (r) {
			if (r -> next)
				printf("%d ", r -> val);
			else
				printf("%d", r -> val);
			r = r -> next;
		}
		printf("\n");
	}
	return 0;
}
