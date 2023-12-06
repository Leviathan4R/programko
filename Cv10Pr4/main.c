#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include "check.c"

int minmax(size_t aNum, double aData[aNum], double* aPtrMin, double* aPtrMax);

int minmax(size_t aNum, double aData[aNum], double* aPtrMin, double* aPtrMax) {
	if (aNum == 0 || aPtrMin == NULL || aPtrMax == NULL) {
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
	double* ptr_data;
	size_t data_num;

	printf("Zadej pocet cisel: ");
	if (scanf("%zu", &data_num) != 1) {
		printf("Chyba! nie je platny size_t!\n");
		return 1;
	}
	ptr_data = (double*)calloc(data_num, sizeof(double));

	if (!ptr_data) {
		printf("Chyba alokacie!\n");
		return 2;
	}

	printf("Zadej %zu cisel: ", data_num);
	for (size_t i = 0; i < data_num; i++) {
		if (scanf("%lf", &ptr_data[i]) != 1) {
			free(ptr_data);
			printf("Chyba! nie je platny double!\n");
			return 3;
		}
	}

	double min, max;

	if (minmax(data_num, ptr_data, &min, &max) == -1) {
		free(ptr_data);
		printf("Chyba vo funkcii!");
		return 4;
	}

	free(ptr_data);

	printf("Minimalna hodnota: %lf\nMaximalna hodnota: %lf\n", min, max);


	//memory_stat();
	return 0;
}