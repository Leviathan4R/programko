#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap_numbers(int* aPtr1, int* aPtr2);

void swap_numbers(int* aPtr1, int* aPtr2) {
	int a = *aPtr1;
	*aPtr1 = *aPtr2;
	*aPtr2 = a;
}

int main() {
	int x = 10;
	int y = 20;
	
	printf("Hodnota x: %i, y: %i\n", x, y);

	swap_numbers(&x, &y);

	printf("Hodnota x: %i, y: %i\n\n", x, y);

	void (*p_swap_numbers)(int* aPtr1, int* aPtr2) = NULL;
	p_swap_numbers = swap_numbers;

	printf("Hodnota x: %i, y: %i\n", x, y);

	p_swap_numbers(&x, &y);

	printf("Hodnota x: %i, y: %i\n", x, y);

	return 0;
}