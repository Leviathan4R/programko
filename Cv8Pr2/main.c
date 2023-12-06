#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

struct TPoint {
	float iX;
	float iY;
};


int main() {
	struct TPoint point = { 
		.iX = 0,
		.iY = 0
	};
	
	printf("Zadaj bod x: ");
	if (scanf("%f", &point.iX) != 1) {
		printf("Chyba! nie je platny float!");
		return 1;
	}

	printf("Zadaj bod y: ");
	if (scanf("%f", &point.iY) != 1) {
		printf("Chyba! nie je platny float!");
		return 1;
	}

	float r = sqrtf(point.iX * point.iX + point.iY * point.iY);

	printf("Vzdialenost od pociatocneho bodu [0, 0]: %f", r);

	return 0;
}