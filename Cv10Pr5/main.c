#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include "check.h"

int minmax(size_t aNum, double aData[aNum], double* aPtrMin, double* aPtrMax);
int read_data(size_t* aPtrNum, double** aPtrData);

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

int read_data(size_t* aPtrNum, double** aPtrData) {
	if (!aPtrNum || !aPtrData || *aPtrData) {
		return -1;
	}

	size_t data_num;
	double* ptr_data = NULL;

	printf("Zadej pocet cisel: ");
	if (scanf("%zu", &data_num) != 1) {
		fprintf(stderr, "Chyba! nie je platny size_t!\n");
		return -1;
	}

	ptr_data = (double*)calloc(data_num, sizeof(double));

	if (!ptr_data) {
		free(ptr_data);
		fprintf(stderr, "Chyba alokacie!\n");
		return -2;
	}

	printf("Zadej %zu cisel: ", data_num);
	for (size_t i = 0; i < data_num; i++) {
		if (scanf("%lf", &ptr_data[i]) != 1) {
			free(ptr_data);
			fprintf(stderr, "Chyba! nie je platny double!\n");
			return -3;
		}
	}

	*aPtrNum = data_num;
	*aPtrData = ptr_data;

	return 0;
}

int main() {
	double* ptr_data = NULL;
	size_t data_num;

	if (read_data(&data_num, &ptr_data) < 0) {
		free(ptr_data);
		fprintf(stderr, "Chyba!");
		return 4;
	}

	double min, max;

	if (minmax(data_num, ptr_data, &min, &max) == -1) {
		free(ptr_data);
		fprintf(stderr, "Chyba vo funkcii!");
		return 4;
	}

	free(ptr_data);

	printf("Minimalna hodnota: %lf\nMaximalna hodnota: %lf\n", min, max);

	return 0;
}