#include <stdio.h>
#include <stdlib.h>
#include "TData.h"

/*	Reads data from the stream 'aFile' and saves them into dynamically allocated array
 *	
 *	 - data is read as the 'double' data type
 *	 - pointer to dynamically allocated array is saved into 'aPtrData'
 *	 - Note that stream 'aFile' can be any data stream including: stdin, stdout, and file streams*/
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

/*	Writes data to the stream 'aFile' from struct 'TData'
 *	
 *	 - data is written as the 'double' data type
 *	 - Note that stream 'aFile' can be any data stream including: stdin, stdout, and file streams*/
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

/*	Finds the minimum and maximum value from the 'aData' struct and saves them into memory given by pointers 'aPtrMin' and 'aPtrMax'
 *	
 *	*/
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

/*	Writes given 'aMin' and 'aMax' value to the stream 'aFile'
 *	
 *	 - data is written in format: "min=MinValue, max=MaxValue\n"
 *	 - Note that stream 'aFile' can be any data stream including: stdin, stdout, and file streams*/
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

/*	Empties memory given by pointer 'aPtrData' and frees any allocated memory in it.
 *	
 *	 - Array is set to value NULL to avoid any undefined program behavior.*/
void data_destroy(struct TData* aPtrData) {
	if (!aPtrData) {
		return;
	}

	free(aPtrData->iPtr_data);
	aPtrData->iPtr_data = NULL;
	aPtrData->iData_num = 0;
	return;
}
