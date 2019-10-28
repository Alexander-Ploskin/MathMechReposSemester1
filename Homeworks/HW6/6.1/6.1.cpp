#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "stack.h"

bool isNumber(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

int counting(char* string, bool &isSuccesfull)
{
	Stack* stack = createStack();

	const int length = strlen(string);
	if (length == 0)
	{
		deleteStack(stack);
		isSuccesfull = false;
		return 0;
	}

	for (int i = 0; i < strlen(string); ++i)
	{
		if (isNumber(string[i]))
		{
			int realNumber = 0;
			while (isNumber(string[i]))
			{
				realNumber = realNumber * 10 + string[i] - '0';
				i++;
			}
			push(realNumber, stack);
		}
		else if (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/')
		{
			if (string[i] == '/' && checkHead(stack) == 0)
			{
				deleteStack(stack);
				isSuccesfull = false;
				return 0;
			}

			if (isEmpty(stack))
			{
				deleteStack(stack);
				isSuccesfull = false;
				return 0;
			}
			int number2 = pop(stack);

			if (isEmpty(stack))
			{
				deleteStack(stack);
				isSuccesfull = false;
				return 0;
			}
			int number1 = pop(stack);

			switch (string[i])
			{
			case '+':
			{
				number1 += number2;
				break;
			}
			case '-':
			{
				number1 -= number2;
				break;
			}
			case '*':
			{
				number1 *= number2;
				break;
			}
			case '/':
			{
				number1 /= number2;
				break;
			}
			}

			push(number1, stack);
		}
	} 

	if (isEmpty(stack))
	{
		isSuccesfull = false;
		return 0;
	}

	int result = pop(stack);

	if (!isEmpty(stack))
	{
		isSuccesfull = false;
		deleteStack(stack);
		return 0;
	}

	deleteStack(stack);
	return result;
}

bool test()
{
	char test1[] = { "9 6 - 1 2 + *" };
	bool isTest1 = true;
	int resultTest1 = counting(test1, isTest1);

	char test2[] = { "99 124 -" };
	bool isTest2 = true;
	int resultTest2 = counting(test2, isTest2);

	char test3[] = { "1 0 /" };
	bool isTest3 = true;
	counting(test3, isTest3);

	char test4[] = { "1 1 1 +" };
	bool isTest4 = true;
	counting(test4, isTest4);

	char test5[] = { "1 + +" };
	bool isTest5 = true;
	counting(test5, isTest5);

	char test6[] = { "+ 1 1 +" };
	bool isTest6 = true;
	counting(test6, isTest6);

	return !isTest6 && !isTest5 && !isTest4 && !isTest3 && isTest2 && resultTest1 == 9 && resultTest2 == -25;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	setlocale(LC_ALL, "Russian");

	char inputString[100]{};
	printf("Введите выражение:\n");
	scanf("%[^\n]%*c", &inputString);

	bool isSuccesfull = true;
	int result = counting(inputString, isSuccesfull);
	if (isSuccesfull)
	{
		printf("Результат: %d", result);
	}
	else
	{
		printf("Некорректный ввод");
	}

	return 0;
}
