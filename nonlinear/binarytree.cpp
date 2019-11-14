#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//Queue
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))	error("queue is full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))	error("queue is empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

//레벨 순회 함수
void level_order(TreeNode* ptr) {
	QueueType q;
	init_queue(&q);
	if (ptr == NULL)	return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)	enqueue(&q, ptr->left);
		if (ptr->right)	enqueue(&q, ptr->right);
	}
}

//레벨 순회 최소값 탐색
TreeNode* btmin(TreeNode* ptr) {
	QueueType q;
	init_queue(&q);
	if (ptr == NULL)	return NULL;
	enqueue(&q, ptr);
	ptr = dequeue(&q);
	TreeNode* min = ptr;
	do {
		if (ptr->left)	enqueue(&q, ptr->left);
		if (ptr->right)	enqueue(&q, ptr->right);
		ptr = dequeue(&q);
		if (ptr->data < min->data) min = ptr;
	} while (!is_empty(&q));
	return min;
}

//레벨 순회 최대값 탐색
TreeNode* btmax(TreeNode* ptr) {
	QueueType q;
	init_queue(&q);
	if (ptr == NULL)	return NULL;
	enqueue(&q, ptr);
	ptr = dequeue(&q);
	TreeNode* max = ptr;
	do {
		if (ptr->left)	enqueue(&q, ptr->left);
		if (ptr->right)	enqueue(&q, ptr->right);
		ptr = dequeue(&q);
		if (ptr->data > max->data) max = ptr;
	} while (!is_empty(&q));
	return max;
}

TreeNode n10 = { 2, NULL, NULL };
TreeNode n9 = { 3, NULL, NULL };
TreeNode n8 = { 12, &n10, NULL };
TreeNode n7 = { 1, NULL, NULL };
TreeNode n6 = { 11, &n9, NULL };
TreeNode n5 = { 7, &n7, &n8 };
TreeNode n4 = { 9, NULL, NULL };
TreeNode n3 = { 4, NULL, &n6 };
TreeNode n2 = { 5, &n4, &n5 };
TreeNode n1 = { 8, &n2, &n3 };
TreeNode* root = &n1;

int main(void) {
	printf("레벨 순회: ");
	level_order(root);
	printf("\n");
	printf("min: %d\n", btmin(root)->data);
	printf("max: %d\n", btmax(root)->data);
	return 0;
}