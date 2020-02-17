#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "stack.h"

bool balanceCheck(const char* string)
{
	OpenBracket* head = nullptr;

	for (int i = 0; i < strlen(string); ++i)
	{
		const char symbol = string[i];

		if (symbol == '(' || symbol == '{' || symbol == '[')
		{
			push(symbol, &head);
		}
		else if (symbol == ')' || symbol == '}' || symbol == ']')
		{
			if (isEmpty(head))
			{
				return false;
			}
			const char currentBracket = pop(&head);

			if (currentBracket == '(' && symbol != ')')
			{
				return false;
			}
			if (currentBracket == '{' && symbol != '}')
			{
				return false;
			}
			if (currentBracket == '[' && symbol != ']')
			{
				return false;
			}
		}
	}

	if (!isEmpty(head))
	{
		while (!isEmpty(head))
		{
			deleteStackElement(&head);
		}
		return false;
	}

	return true;
}

bool test()
{
	const char test1[] = "((()";
	if (balanceCheck(test1))
	{
		return false;
	}

	const char test2[] = "(){}[]";
	if (!balanceCheck(test2))
	{
		return false;
	}

	const char test3[] = "()))";
	if (balanceCheck(test3))
	{
		return false;
	}

	const char test4[] = "({)}";
	if (balanceCheck(test4))
	{
		return false;
	}

	const char test5[] = "[.](/)";
	if (!balanceCheck(test5))
	{
		return false;
	}

	const char test6[] = "((()";
	if (balanceCheck(test6))
	{
		return false;
	}

	const char test7[] = "(}";
	if (balanceCheck(test7))
	{
		return false;
	}

	return true;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	setlocale(LC_ALL, "Russian");

	const char string[100]{};

	printf("Введите строку короче 100 символов:\n");
	scanf("%s", &string);

	if (balanceCheck(string))
	{
		printf("Баланс в норме.\n");
	}
	else
	{
		printf("Баланс не в норме.\n");
	}

	return 0;
}