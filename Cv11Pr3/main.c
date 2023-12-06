#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include "check.h"

struct TData {
	double* iPtr_data;
	size_t iData_num;
};

int minmax(struct TData aData, double* aPtrMin, double* aPtrMax);

int minmax(struct TData aData, double* aPtrMin, double* aPtrMax) {
	if (aData.iData_num == 0 || aPtrMin == NULL || aPtrMax == NULL) {
		return -1;
	}

	double min, max;

	min = aData.iPtr_data[0];
	max = aData.iPtr_data[0];
	for (size_t i = 0; i < aData.iData_num; i++) {
		if (aData.iPtr_data[i] > *aPtrMax) {
			max = aData.iPtr_data[i];
		}
		if (aData.iPtr_data[i] < *aPtrMin) {
			min = aData.iPtr_data[i];
		}
	}

	*aPtrMin = min;
	*aPtrMax = max;
	return 0;
}


int main(int argc, char* argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Chyba - nebolo zadane meno vstupneho a vystupneho suboru!");
		return 1;
	}

	struct TData data;

	FILE* fr = fopen(argv[1], "r");

	if (!fr) {
		fprintf(stderr, "Chyba pri otvarani vstupneho suboru!\n");
		return 2;
	}
	
	if (fscanf(fr, "%zu", &data.iData_num) != 1) {
		fprintf(stderr, "Chyba pri citani dat!\n");
		fclose(fr);
		return 3;
	}

	data.iPtr_data = (double*)calloc(data.iData_num, sizeof(double));

	if (!data.iPtr_data) {
		fprintf(stderr, "Chyba alokacie!\n");
		fclose(fr);
		return 4;
	}

	for (size_t i = 0; i < data.iData_num; i++) {
		if (fscanf(fr, "%lf", &data.iPtr_data[i]) != 1) {
			fprintf(stderr, "Chyba pri citani dar!\n");
			free(data.iPtr_data);
			fclose(fr);
			return 5;
		}
	}

	fclose(fr);

	for (size_t i = 0; i < data.iData_num; i++) {
		printf("%lf\n", data.iPtr_data[i]);
	}

	double min, max;


	if (minmax(data, &min, &max) < 0) {
		fprintf(stderr, "Chyba vo funkcii!");
		free(data.iPtr_data);
		return 6;
	}

	free(data.iPtr_data);
	
	printf("Minimalna hodnota: %lf\nMaximalna hodnota: %lf\n", min, max);
	
	FILE* fw = fopen(argv[2], "w");

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