#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "check.h"

struct TPoint {
	double iX;
	double iY;
};

int main() {
	struct TPoint* points_ptr = NULL;
	size_t points_num;
	
	FILE* fr = fopen("vstup.txt", "r");
	if (!fr) {
		fprintf(stderr, "Chyba pri otvarani vstupneho suboru!\n");
		return 2;
	}

	
	if (fscanf(fr, "%zu", &points_num) != 1) {
		fprintf(stderr, "Chyba pri citani dat!\n");
		fclose(fr);
		return 3;
	}

	points_ptr = (struct TPoint*)calloc(points_num, sizeof(struct TPoint));

	if (!points_ptr) {
		fprintf(stderr, "Chyba alokacie!\n");
		fclose(fr);
		return 4;
	}

	for (size_t i = 0; i < points_num; i++) {
		if (fscanf(fr, "%lf", &points_ptr[i].iX) != 1 ||
			fscanf(fr, "%lf", &points_ptr[i].iY) != 1) {
			fprintf(stderr, "Chyba pri citani dar!\n");
			free(points_ptr);
			fclose(fr);
			return 5;
		}
	}

	fclose(fr);

	for (size_t i = 0; i < points_num; i++) {
		printf("[%lf, %lf]: %lf\n", points_ptr[i].iX, points_ptr[i].iY, 
			sqrt(pow(points_ptr[i].iX, 2) + pow(points_ptr[i].iY, 2)));
	}

	free(points_ptr);

	return 0;
}