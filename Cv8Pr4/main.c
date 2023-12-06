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

int main() {
	struct TRect rectangle = {
		{0, 0 },
		{0, 0 }
	};

	printf("Zadej souradnice leveho horniho rohu: ");
	if (scanf("%f, %f", &rectangle.iPointLH.iX, &rectangle.iPointLH.iY) != 2) {
		return 1;
	}

	printf("Zadej souradnice praveho dolniho rohu: ");
	if (scanf("%f, %f", &rectangle.iPointRD.iX, &rectangle.iPointRD.iY) != 2) {
		return 1;
	}
	
	float diag = sqrtf(powf(rectangle.iPointLH.iX - rectangle.iPointRD.iX, 2) + 
		powf(rectangle.iPointLH.iY - rectangle.iPointRD.iY, 2));
	
	printf("Dlzka uhlopriecky: %f", diag);

	return 0;
}