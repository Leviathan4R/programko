#define _CRT_SECURE_NO_WARNINGS
#define N 2U

#include <stdio.h>

unsigned gcd(unsigned aU, unsigned aW);

unsigned gcd(unsigned aU, unsigned aW) {
	unsigned aR;

	while (aW) {
		aR = aU % aW;
		aU = aW;
		aW = aR;
	}

	return aU;
}

int main() {
	unsigned u, w;

	printf("Zadaj cislo u: ");
	if (scanf("%u", &u) != 1) {
		printf("Toto nie je platny unsigned!");
		return 1;
	}

	printf("Zadaj cislo w: ");
	if (scanf("%u", &w) != 1) {
		printf("Toto nie je platny unsigned!");
		return 1;
	}

	printf("Najvacsi spolocni delitel je: %u", gcd(u, w));

	return 0;
}