/*
###Including functions###
erorr()
insert_first()
insert()
delete_first()
delete()
print_list()
get_entry() : return nth data in linked list (index from 0)
get_length() : return number of nodes in linked list
add_data(): add all the data in linked list
count_data(): count how many times the datum "N" has saved
alternate(): from two given linked list A,B, the function takes a node alternatively and create a new one
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value){
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

element get_entry(ListNode* head, int index) {
	int i = 0;
	if (head == NULL) error("The list is empty");
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (i == index) return p->data;
		i++;
	}
	error("Index is out of bound");
}

int get_length(ListNode* head) {
	int i = 0;
	if (head == NULL) return 0;
	for (ListNode* p = head; p != NULL; p = p->link) {
		i++;
	}
	return i;
}

int add_data(ListNode* head) {
	if (head == NULL) error("The list is empty");
	int result = 0;
	for (ListNode* p = head; p != NULL; p=p->link) {
		result += p->data;
	}
	return result;
}

int count_data(ListNode* head, int n) {
	if (head == NULL) error("The list is empty");
	int result = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (n == p->data) result += 1;
	}
	return result;
}

void add_last(ListNode* head, element value) {
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->data = value; tmp->link = NULL;
	if (head == NULL) head = tmp;
	else {
		ListNode* p = head;
		while (p != NULL)
			p = p->link;
		p->link = tmp;
	}
}

ListNode* alternate(ListNode* head1, ListNode* head2){
	ListNode* head3 = NULL;
	ListNode *p1, *p2 = NULL;

	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	p1 = head1; p2 = head2;
	while (p1 && p2) {
		if (p1 != NULL) {
			add_last(head3, p1->data);
			p1 = p1->link;
		}
		if (p2 != NULL) {
			add_last(head3, p2->data);
			p2 = p2->link;
		}
	}
	return head3;
}

int main(void) {
	ListNode* head = NULL;
	
	for (int i = 5; i > 0; i--) {
		head = insert_first(head, i);
	}
	print_list(head);

	//printf("%d\n", get_entry(head, 2)); 
	//printf("%d", get_entry(head, 9));
	//printf("%d\n", get_length(head));
	//printf("%d\n", add_data(head));
	//printf("%d\n", count_data(head,2));

	ListNode* test = NULL;
	for (int i = 5; i < 10; i++) {
		test = insert_first(test, i);
	}
	print_list(test);

	ListNode* result= alternate(head, test);
	print_list(result);
	return 0;
}
