#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-||%d||-> ", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

DListNode* search(DListNode* head, element data) {
	for (DListNode* p = head->rlink; p != head; p = p->rlink) {
		if (p->data == data) return p;
	}
	return;
}

void reverse_print(DListNode* head) {
	init(head);
	printf("enter a number of data: ");
	int size, tmp;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		printf("data #%d: ",i+1);
		scanf("%d", &tmp);
		dinsert(head, tmp);
	}
	printf("reversed order: ");
	
	for (DListNode* p = head->rlink; p != head; p=p->rlink) {
		printf("%d ", p->data);
	}
}

int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("inserting\n");
	for (int i = 0; i < 5; i++) {
		dinsert(head, i);
		print_dlist(head);
	}
	printf("p->data: %d\n", search(head,4)->data);
	printf("deleting\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);

	DListNode* head2 = (DListNode*)malloc(sizeof(DListNode));
	reverse_print(head2);
	return 0;
}