#include <stdio.h>

//Лобовое вычисление степени рекурсивным алгоритмом
int simpleExponentiation(int power, int number)
{
	if (power == 0)
	{
		return 1;
	}
	else
	{
		return simpleExponentiation(power - 1, number) * number;
	}
}

//Вычисление степени эффективным алгоритмом
int effectiveExponentation(int power, int number)
{
	int count = 1;
	if (power == 0)
	{
		return 1;
	}
	while (power > 0)
	{
		if (power % 2 == 0)
		{
			power /= 2;
			number *= number;
		}
		else
		{
			count *= number;
			--power;
		}
	}
	return count;
}


int main()
{
	printf("Enter the number: \n");
	int number = 0;
	scanf("%d", &number);
	printf("Enter the power: \n");
	int power = 0;
	scanf("%d", &power);
	printf("%d in %d power is %d", number, power, effectiveExponentation(power, number));
	return 0;
}
