#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	unsigned int rok;

	printf("Zadaj rok: ");

	if (scanf("%u", &rok) != 1) {
		printf("Rok nie je platny!");
		return -1;
	}

	if (!(rok % 400) || (rok % 100 && !(rok % 4))) {
		printf("Rok %u je priestupny", rok);
	}
	else {
		printf("Rok %u nie je priestupny", rok);
	}

	return 0;
}