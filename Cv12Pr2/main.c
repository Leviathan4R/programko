#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include "./Source/check.h"

struct TData {
	double* iPtr_data;
	size_t iData_num;
};

int data_read(FILE* aFile, struct TData* aPtrData);
int data_write(FILE* aFile, const struct TData aData);
int data_minmax(const struct TData aData, double* aPtrMin, double* aPtrMax);
int data_minmax_write(FILE* aFile, double aMin, double aMax);
void data_destroy(struct TData* aPtrData);

int data_read(FILE* aFile, struct TData* aPtrData) {
	if (!aFile || !aPtrData) {
		fprintf(stderr, "Chyba! vstupne hodnoty su Null!\n");
		return -1;
	}

	size_t data_num;
	double* ptr_data;

	if (fscanf(aFile, "%zu", &data_num) != 1) {
		fprintf(stderr, "Chyba pri citani dat!\n");
		return -1;
	}

	ptr_data = (double*)calloc(data_num, sizeof(double));

	if (!ptr_data) {
		fprintf(stderr, "Chyba alokacie!\n");
		free(ptr_data);
		return -1;
	}

	for (size_t i = 0; i < data_num; i++) {
		if (fscanf(aFile, "%lf", &ptr_data[i]) != 1) {
			fprintf(stderr, "Chyba pri citani dat!\n");
			free(ptr_data);
			return -1;
		}
	}

	aPtrData->iData_num = data_num;
	aPtrData->iPtr_data = ptr_data;

	return 0;
}

int data_write(FILE* aFile, const struct TData aData) {
	if (!aFile || !aData.iPtr_data) {
		return -1;
	}
	for (size_t i = 0; i < aData.iData_num; i++) {
		if (fprintf(aFile, "%lf\n", aData.iPtr_data[i]) < 0) {
			fprintf(stderr, "Chyba pri zapisovani dat!\n");
			return -1;
		}
	}

	return 0;
}

int data_minmax(const struct TData aData, double* aPtrMin, double* aPtrMax) {
	if (!aData.iData_num || !aPtrMin || !aPtrMax) {
		fprintf(stderr, "Chyba pri vstupnych parametroch == NULL\n");
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

int data_minmax_write(FILE* aFile, double aMin, double aMax) {
	if (!aFile) {
		fprintf(stderr, "Chyba pri vstupnych parametroch\n");
		return -1;
	}

	if (fprintf(aFile, "min=%lf, max=%lf\n", aMin, aMax) < 0) {
		fprintf(stderr, "Chyba pri zapisovani dat Min Max\n");
		return -1;
	}

	return 0;
}

void data_destroy(struct TData* aPtrData) {
	if (!aPtrData) {
		return;
	}

	free(aPtrData->iPtr_data);
	aPtrData->iPtr_data = NULL;
	aPtrData->iData_num = 0;
	return;
}

// Main process
int main(int argc, char* argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Chyba - nebolo zadane meno vstupneho a vystupneho suboru!");
		return 1;
	}

	struct TData data;
	FILE* fr = fopen(argv[1], "r");

	if (data_read(fr, &data) < 0) {
		fprintf(stderr, "Chyba vo funkcii data_read!");
		fclose(fr);
		return -1;
	}
	fclose(fr);

	if (data_write(stdout, data) < 0) {
		fprintf(stderr, "Chyba vo funkcii data_write");
		data_destroy(&data);
		return -1;
	}

	double min, max;

	if (data_minmax(data, &min, &max) < 0) {
		fprintf(stderr, "Chyba vo funkcii data_minmax!");
		data_destroy(&data);
		return -1;
	}

	data_destroy(&data);

	if (data_minmax_write(stdout, min, max) < 0) {
		fprintf(stderr, "Chyba vo funkcii data_minmax_write");
		return -1;
	}

	FILE* fw = fopen(argv[2], "w");

	if (data_minmax_write(fw, min, max) < 0) {
		fprintf(stderr, "Chyba vo funkcii data_minmax_write");
		fclose(fw);
		return -1;
	}

	fclose(fw);

	return 0;
}
