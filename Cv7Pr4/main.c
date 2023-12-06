#define _CRT_SECURE_NO_WARNINGS
#define ROWS 2
#define COLS 3

#include <stdio.h>

int main() {
	unsigned char i, j;
	int matA[ROWS][COLS] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};
	int matB[ROWS][COLS] = {
		{ 10, 20, 30 },
		{ 40, 50, 60 },
	};
	int matC[ROWS][COLS];

	printf("Matica A: \n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++)
			printf("%i ", matA[i][j]);
		printf("\n");
	}

	printf("Matica B: \n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++)
			printf("%i ", matB[i][j]);
		printf("\n");
	}


	printf("Matica C: \n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			matC[i][j] = matA[i][j] + matB[i][j];
			printf("%i ", matC[i][j]);
		}
		printf("\n");
	}
	return 0;
}