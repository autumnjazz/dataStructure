#include "stack.h"
#define MAZE_SIZE 10

StackObject here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1','1','1','1','1'},
	{'e','0','0','0','1','0','0','0','0','1'},
	{'1','0','0','0','1','0','0','0','0','1'},
	{'1','0','1','1','1','0','0','1','0','1'},
	{'1','0','0','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','0','0','0','1','0','x'},
	{'1','1','1','1','1','1','1','1','1','1'},
};

void pushLoc(StackType *s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		StackObject tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void printMaze(char maze[][MAZE_SIZE]) {
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			printf("%c ", maze[i][j]);
		}

		printf("\n");
	}

}

void main() {
	int r, c;
	StackType s;
	init(&s);
	here = entry;
	printf("Initial Maze\n");
	printMaze(maze);
	printf("\n");
	printStack(&s);
	int count = 1;
	while (maze[here.r][here.c] != 'x') {
		if (count % 4 == 0) {
			printf("\nTURN: %d\n", count);
			printMaze(maze);
			printf("\n");
		}
		count++;

		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		pushLoc(&s, r - 1, c);
		pushLoc(&s, r + 1, c);
		pushLoc(&s, r, c - 1);
		pushLoc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("탈출 실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("%d 번만에 성공!\n", count);
	printMaze(maze);
	printStack(&s);
}