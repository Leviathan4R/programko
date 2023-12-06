#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

struct TPoint {
	float iX;
	float iY;
};

struct TRect {
	struct TPoint iPointLH;
	struct TPoint iPointRD;
};

struct TRect read_rect();
struct TPoint read_point();

static inline float diagonal(struct TRect aRect) {
	return sqrtf(powf(aRect.iPointLH.iX - aRect.iPointRD.iX, 2) +
		powf(aRect.iPointLH.iY - aRect.iPointRD.iY, 2));
}

int main() {
	struct TRect rectangle = {
		{0, 0 },
		{0, 0 }
	};

	rectangle = read_rect();
	
	float diag = diagonal(rectangle);
	
	printf("Dlzka uhlopriecky: %f", diag);
	
	return 0;
}

struct TRect read_rect() {
	struct TRect rect = {
		{0, 0},
		{0, 0}
	};

	printf("Zadej souradnice leveho horniho rohu: ");
	rect.iPointLH = read_point();

	printf("Zadej souradnice praveho dolniho rohu: ");
	rect.iPointRD = read_point();

	return rect;
}

struct TPoint read_point() {
	struct TPoint point;

	if (scanf("%f, %f", &point.iX, &point.iY) != 2) {
		return (struct TPoint) { 0, 0 };
	}
	return point;
}