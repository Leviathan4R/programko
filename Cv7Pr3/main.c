#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

static inline bool is_leap_year(unsigned aYear);

static inline bool is_leap_year(unsigned aYear) {
	return !(aYear % 400) || (aYear % 100 && !(aYear % 4));
}


int main() {
	unsigned year;

	printf("Zadaj rok: ");

	if (scanf("%u", &year) != 1) {
		printf("Cislo nie je platny unsigned!");
		return 1;
	}

	if (is_leap_year(year))
		printf("Rok %u je piestupny!", year);
	else
		printf("Rok %u nie je piestupny!", year);
	
	return 0;
}