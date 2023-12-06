#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int x = 10;
	int y = 20;

	int* ptr_x = NULL; 
	int* ptr_y = NULL;
	ptr_x = &x;
	ptr_y = &y;
	
	printf("Hodnota\nx: %i,\ny: %i,\nptr_x: %p,\nptr_y: %p\n\n", x, y, ptr_x, ptr_y);
	printf("Adresa\nx: %p,\ny: %p,\nptr_x: %p,\nptr_y: %p\n\n", &x, &y, &ptr_x, &ptr_y);
	
	int z = *ptr_x;
	*ptr_x = *ptr_y;
	*ptr_y = z;

	printf("Po vymene:\nHodnota\nx: %i,\ny: %i\n\n", x, y);

	return 0;
}