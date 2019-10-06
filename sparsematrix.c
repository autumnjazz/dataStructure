#include <stdio.h>

#define ROWS 6
#define COLS 6
#define MAX_TERMS 36
typedef struct {
	int row;
	int col;
	int value;
} element;
typedef struct {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

//희소 행렬 덧셈 함수
SparseMatrix sparsematrix_add(SparseMatrix a, SparseMatrix b) {
	SparseMatrix c;
	int ca = 0, cb = 0, cc = 0;
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "희소행렬 크기 에러\n");
		exit(1);
	}
	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;

	while(ca < a.terms && cb < b.terms) {
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col;
		if (inda < indb) {
			c.data[cc++] = a.data[ca++];
		}
		else if (inda == indb) {
			if ((a.data[ca].value + b.data[cb].value) != 0) {
				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}
			else {
				ca++; cb++;
			}
		}
		else {
			c.data[cc++] = b.data[cb++];
		}
	}
	for (; ca < a.terms;)
		c.data[cc++] = a.data[ca++];
	for (; cb < b.terms;)
		c.data[cc++] = b.data[cb++];
	c.terms = cc;
	return c;
}

//희소행렬 출력 함수
sparsematrix_print(SparseMatrix m) {
	int p = 0;

	for (int i =0; i < m.rows * m.cols; i++) { //0~8
		int idx = -1;
		if (p < m.terms) {
			idx = m.data[p].row * m.cols + m.data[p].col; //3 5 7
		}
		if (idx == i) {
			printf("%d  ", m.data[p].value);
			p++;
		}
		else printf("0  ");
		if (i % m.rows == m.rows-1) printf("\n");
		
	}

}

main() {

	printf("2019.09.30. 자료구조 과제\n2017640018 장다래\n\n");

	SparseMatrix m1 = {
		{{0,0,1},{1,1,1},{2,1,1},{3,2,1},{4,3,1},{5,1,2},{5,3,-1}},6,6,7
	};
	SparseMatrix m2 = {
		{{0,0,1},{1,0,1},{2,1,1},{3,2,1},{4,0,1},{5,0,1}},6,6,6
	};
	SparseMatrix m3;
	m3 = sparsematrix_add(m1, m2);
	sparsematrix_print(m3);
}