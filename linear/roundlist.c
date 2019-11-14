//delet()
//search()
//get_size()

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d\n", p->data);
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* delete(ListNode* head, element data){
	if (head == NULL) return;
	ListNode* p, * pre, *remove;
	pre = NULL;
	p = head->link;
	do {
		if (p->link->data == data) pre = p;
		p = p->link;
	} while (p != head);
	if (p->link->data == data) pre = p;
	if (pre == NULL)return;
	remove = pre->link;
	pre->link = pre->link->link;
	free(remove);
	return head;
}

ListNode* search(ListNode* head, element data) {
	if (head == NULL) return;
	ListNode* p = head->link;
	do {
		if (data == p->data) return p;
		p = p->link;
	} while (p != head);
	if (data == p->data) return p;
	fprintf(stderr, "no data\n");
}

int get_size(ListNode* head) {
	if (head == NULL) return 0;
	ListNode* p = head->link;
	int count = 0;
	do {
		count++;
		p = p->link;
	} while (p != head);
	count++;
	return count++;
}

int main(void) {
	ListNode* head = NULL;
	printf("SIZE: %d\n", get_size(head));
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	printf("SIZE: %d\n", get_size(head));
	ListNode* p = search(head, 30);
	printf("%d\n", p->data);
	p = search(head, 10);
	printf("%d\n", p->data);
	head = delete(head, 20);
	print_list(head);
	head = delete(head, 10);
	print_list(head);
	printf("SIZE: %d\n", get_size(head));
	return 0;
}
