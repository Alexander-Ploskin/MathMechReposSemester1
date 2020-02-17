#include <stdio.h>
#include <stdlib.h>

int main()
//a=b*q+r r=a-b*q
{
	printf("Enter the numbers: \n");
	int a, b;
	scanf_s("%d%d", &a, &b);
	while (b == 0)
	{
		printf("Enter the nozero b: \n");
		scanf_s("%d", &b);
	}
	int result;
	for (int quotient = -abs(a) / 2, abs_b = abs(b), abs_a = abs(a); quotient <= abs_a / 2; quotient++)
		if ((a - b * quotient >= 0) && (a - b * quotient < abs_b))
			result = quotient;
	printf("Quotient: %d", result);
	return 0;
}