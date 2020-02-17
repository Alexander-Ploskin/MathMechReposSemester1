#include <stdio.h>
#include <math.h>

int main()
{
	int number;
	printf("Enter the number : \n");
	scanf_s("%d", &number);
	printf("Your numbers : \n");
	int divider;
	for (int new_number = 2; new_number <= number; new_number++)
	{
		for (divider = 2; divider <= sqrt(new_number); divider++)
			if (new_number % divider == 0) break;
		if (divider > sqrt(new_number))
			printf("%d ", new_number);
	}
	return 0;
}