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


double distance(struct TPoint aPoint);
void points_print(size_t aPointsNum, const struct TPoint aPointsPtr[]);
struct TPoint points_max_distance(size_t aPointsNum, const struct TPoint aPointsPtr[]);


double distance(struct TPoint aPoint) {
	return hypot(aPoint.iX, aPoint.iY);
}

void points_print(size_t aPointsNum, const struct TPoint aPointsPtr[]) {
	for (size_t i = 0; i < aPointsNum; i++) {
		printf("[%lf, %lf]: %lf\n", aPointsPtr[i].iX, aPointsPtr[i].iY,
			distance(aPointsPtr[i]));
	}
}

// Function that returns maximal distance from point [0, 0] of given points from array
struct TPoint points_max_distance(size_t aPointsNum, const struct TPoint aPointsPtr[]) {
	struct TPoint maxPoint = aPointsPtr[0];
	
	for (size_t i = 1; i < aPointsNum; i++) {
		if (distance(maxPoint) < distance(aPointsPtr[i])) {
			maxPoint = aPointsPtr[i];
		}
	}

	return maxPoint;
}


int main() {
	struct TPoint* points_ptr = NULL;
	struct TPoint maxPoint;
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
		if (fscanf(fr, "%lf %lf", &points_ptr[i].iX, &points_ptr[i].iY) != 2){
			fprintf(stderr, "Chyba pri citani dat!\n");
			free(points_ptr);
			fclose(fr);
			return 5;
		}
	}

	fclose(fr);

	printf("Nacitane body: \n");
	points_print(points_num, points_ptr);

	
	printf("\nNajvacsi bod: \n  ");
	maxPoint = points_max_distance(points_num, points_ptr);
	points_print(1, &maxPoint);


	free(points_ptr);

	return 0;
}