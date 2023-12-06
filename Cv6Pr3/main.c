#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	unsigned u, w, r;

	printf("Zadaj prve cislo: ");
	if (scanf("%u", &u) != 1) {
		printf("Chyba! toto nie je cislo!");
		return -1;
	}
	printf("Zadaj druhe cislo: ");
	if (scanf("%u", &w) != 1) {
		printf("Chyba! toto nie je cislo!");
		return -1;
	}

	while (w) {
		r = u % w;
		u = w;
		w = r;
	}

	printf("Najvacsi spolocni delitel je: %u", u);

	return 0;
}