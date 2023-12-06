#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

struct TPoint {
	float iX;
	float iY;
};

struct TPoint read_point();
float distance(struct TPoint aPoint);

int main() {
	struct TPoint point = {0, 0};

	point = read_point();
	if (point.iX == 0 && point.iY == 0) {
		printf("X aj Y = 0, vysledok = 0!, Chybny format!3");
		return 1;
	}

	printf("Vzdialenost bodu od pociatku suradnic [0, 0]: %f", distance(point));

	return 0;
}

struct TPoint read_point() {
	struct TPoint point;

	printf("Zadaj bod x, y: ");
	if (scanf("%f, %f", &point.iX, &point.iY) != 2) {
		return (struct TPoint) {0, 0};
	}
	return point;
}

float distance(struct TPoint aPoint) {
	return sqrtf(aPoint.iX * aPoint.iX + aPoint.iY * aPoint.iY);
}