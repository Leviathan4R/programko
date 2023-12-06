#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>

int minmax(size_t aNum, double aData[aNum], double* aPtrMin, double* aPtrMax);

int minmax(size_t aNum, double aData[aNum], double* aPtrMin, double* aPtrMax) {
	if (!aNum || !aPtrMin || !aPtrMax || !aData) {
		return -1;
	}

	*aPtrMin = aData[0];
	*aPtrMax = aData[0];
	for (size_t i = 0; i < aNum; i++) {
		if (aData[i] > *aPtrMax) {
			*aPtrMax = aData[i];
		}
		if (aData[i] < *aPtrMin) {
			*aPtrMin = aData[i];
		}
	}
	return 0;
}

int main() {
	double data[N];
	size_t data_num;

	printf("Zadej pocet cisel: ");
	if (scanf("%zu", &data_num) != 1) {
		printf("Chyba! nie je platny size_t!\n");
		return 1;
	}

	if (data_num > N) {
		printf("Chyba! Cislo vacsie ako %i!\n", N);
		return 2;
	}

	printf("Zadej %zu cisel: ", data_num);
	for (size_t i = 0; i < data_num; i++) {
		if (scanf("%lf", &data[i]) != 1) {
			printf("Chyba! nie je platny double!\n");
			return 3;
		}
	}

	double min, max;

	if (minmax(data_num, data, &min, &max) == -1) {
		printf("Chyba!");
		return 4;
	}

	printf("Minimalna hodnota: %lf\nMaximalna hodnota: %lf\n", min, max);

	return 0;
}