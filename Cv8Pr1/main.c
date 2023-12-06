#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

float distance(float aX, float aY);

float distance(float aX, float aY) {
	return sqrtf(aX * aX + aY * aY);
}

int main() {
	float x, y;

	printf("Zadaj bod x: ");
	if (scanf("%f", &x) != 1) {
		printf("Chyba! nie je platny float!");
		return 1;
	}

	printf("Zadaj bod y: ");
	if (scanf("%f", &y) != 1) {
		printf("Chyba! nie je platny float!");
		return 1;
	}
	
	float r = distance(x, y);
	
	printf("Vzdialenost od pociatocneho bodu [0, 0]: %f", r);

	return 0;
}