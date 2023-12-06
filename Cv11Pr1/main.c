#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include "check.h"

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
	FILE* fr = fopen("vstup.txt","r");

	if (!fr) {
		fprintf(stderr, "Chyba pri otvarani vstupneho suboru!\n");
		return 2;
	}
	
	size_t data_num;
	
	if (fscanf(fr, "%zu", &data_num) != 1) {
		fprintf(stderr, "Chyba pri citani dat!\n");
		fclose(fr);
		return 3;
	}

	double* ptr_data = (double*)calloc(data_num, sizeof(double));

	if (!ptr_data) {
		fprintf(stderr, "Chyba alokacie!\n");
		fclose(fr);
		return 4;
	}

	for (size_t i = 0; i < data_num; i++) {
		if (fscanf(fr, "%lf", &ptr_data[i]) != 1) {
			fprintf(stderr, "Chyba pri citani dar!\n");
			free(ptr_data);
			fclose(fr);
			return 5;
		}
	}

	fclose(fr);

	for (size_t i = 0; i < data_num; i++) {
		printf("%lf\n", ptr_data[i]);
	}

	double min, max;


	if (minmax(data_num, ptr_data, &min, &max) < 0) {
		fprintf(stderr, "Chyba vo funkcii!");
		free(ptr_data);
		return 6;
	}

	free(ptr_data);
	
	printf("Minimalna hodnota: %lf\nMaximalna hodnota: %lf\n", min, max);
	
	FILE* fw = fopen("vystup.txt", "w");

	if (!fw) {
		fprintf(stderr, "Chyba pri otvarani vystupneho suboru!");
		return 7;
	}

	if (fprintf(fw, "Minimalna hodnota: %lf\nMaximalna hodnota: %lf\n", min, max) <= 10) {
		fprintf(stderr, "Chyba pri zapisu do vystupneho suboru!");
		fclose(fw);
		return 8;
	}
	
	fclose(fw);

	return 0;
}