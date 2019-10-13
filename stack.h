#include <stdlib.h>
#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef struct StackObjectRec {
	short r;
	short c;
}StackObject;

typedef struct {
	StackObject stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, StackObject item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

StackObject pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}


void printStack(StackType* s) {
	printf("Stack\n");
	if (is_empty(s)) {
		printf("This is empty stack\n");
	}
	else {
		for (int i = 0; i < MAX_STACK_SIZE; i++) {
			StackObject tmp = s->stack[i];
			if (&tmp == NULL || tmp.r <0 || tmp.c<0) {
				printf("No more elements\n");
				break;
			}
			else {
				printf("row, col = { %d, %d }\n", tmp.r, tmp.c);
			}
		}
	}
	printf("top: %d\n", s->top);
}
