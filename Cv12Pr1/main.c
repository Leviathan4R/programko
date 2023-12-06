//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <uchar.h>


int main(int argc, char* argv[]) {
	char* stary = setlocale(LC_ALL, NULL);
	printf("%s\n", stary);
	char* novy = setlocale(LC_ALL, "cs_CZ.UTF-8");
	//printf("%s\n", novy);

	char* text = "České znaky i různé symboly ‰ ✉ ✆ ☺ ☕.\n";
	printf("%s", text);		// Je treba nastavit font NimSum v prikazovom riadku
	printf("%lf\n", 3.14);
	double vysledok;
	if (sscanf(argv[2], "%lf", &vysledok) != 1) {
		fprintf(stderr, "Chyba! nepodarilo sa nacitat prvy argument!");
		return -1;
	}

	printf("%lf\n", vysledok);
	
	return 0;
}