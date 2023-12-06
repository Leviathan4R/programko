#include <stdio.h>
#include <math.h>

int main()
{
	double a;
	double b;
	double c;

	printf("Zadaj parameter a: ");
	if (scanf("%lf", &a) != 1)
	{
		printf("Toto nie je cislo! (Zly format pr.: 3.2, 5.1, 4.99999)\n");
		return -1;
	}
	printf("Zadaj parameter b: ");
	if (scanf("%lf", &b) != 1)
	{
		printf("Toto nie je cislo! (Zly format pr.: 3.2, 5.1, 4.99999)\n");
		return -1;
	}
	printf("Zadaj parameter c: ");
	if (scanf("%lf", &c) != 1)
	{
		printf("Toto nie je cislo! (Zly format pr.: 3.2, 5.1, 4.99999)\n");
		return -1;
	}

	double D = (b * b) - (4 * a * c);

	if (D > 0)
	{
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);

		printf("Kvadraticka rovnica ma 2 korene: \nPrvy koren (x1): %f\nDruhy Koren (x2): %f\n", x1, x2);
		return 0;
	}
	else if (D == 0)
	{
		double x = (-b) / (2 * a);

		printf("Kvadraticka rovnica ma 1 koren: \nKoren (x): %f\n", x);
		return 1;
	}
	else
	{
		printf("Riesenie je komplexne!\n");
		return -2;
	}
}