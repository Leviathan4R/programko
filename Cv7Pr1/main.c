#define _CRT_SECURE_NO_WARNINGS
#define MIN -4.0
#define MAX 5.0
#define N 6

#include <stdio.h>


int main() {
	double data[N];
	double min, max;
	unsigned char i = 0;

	printf("Zadaj %i cisel: \n", N);
		
	while (i < N) {
		printf("Zadaj cislo %u: ", (i+1));
		if (scanf("%lf", &data[i]) != 1) {
			printf("Nie je platny unsigned!\n");
			continue;
		}
		if (data[i] > MAX || data[i] < MIN) {
			printf("Zadane cislo je mimo povoleny rozsah!\n");
			continue;
		}

		i++;
	}

	for (i = 0; i < N; i++) 
		printf("Prvok %u: %lf\n", (i+1), data[i]);
	

	min = data[0];
	max = data[0];

	for (i = 1; i < N; i++) 
		if (data[i] < min) 
			min = data[i];
		else if (data[i] > max) 
			max = data[i];
		
	
	printf("Min = %lf\n", min);
	printf("Max = %lf\n", max);
	return 0;
}