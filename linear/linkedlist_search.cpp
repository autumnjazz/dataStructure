#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("NULL \n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return NULL;
}

int main(void) {
	ListNode* head = NULL;
	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	ListNode* p;
	if ( ( p=search_list(head, 20)) != NULL){
		printf("리스트에서 20을 찾았습니다. \n");
		printf("%d \n", p);
	}
	else
		printf("No 30 in list. \n");
	return 0;
}