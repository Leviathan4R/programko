#ifndef TDATA
#define TDATA

#include <stdio.h>

/*	TData is set up to contain a pointer to dynamically allocated array and arrays length*/
struct TData {
	double* iPtr_data;
	size_t iData_num;
};

int data_read(FILE* aFile, struct TData* aPtrData);
int data_write(FILE* aFile, const struct TData aData);
int data_minmax(const struct TData aData, double* aPtrMin, double* aPtrMax);
int data_minmax_write(FILE* aFile, double aMin, double aMax);
void data_destroy(struct TData* aPtrData);

#endif