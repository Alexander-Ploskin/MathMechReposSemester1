#include <stdio.h>

int main()

{
	int array[10]; // Набирается с клавиатуры
	printf("Enter the array elements: \n");
	int counter = 0;
	int i; // Счетчик цикла
	for (i = 0;i < 10;i++)
	{
		scanf_s("%d", &array[i]);
		if (array[i] == 0) counter++;
	}
	printf("Array contains %d null elements", counter);
	return 0;
}

