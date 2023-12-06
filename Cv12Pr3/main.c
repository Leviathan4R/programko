#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Source/check.h"
#include "TData.h"

// Main process
int main(int argc, char* argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Chyba - nebolo zadane meno vstupneho a vystupneho suboru!");
		return 1;
	}

	struct TData data;
	/*	File opened for reading	*/
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
