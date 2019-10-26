#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "stack.h"


void printString(char* string)
{
	for (int i = 0; i < 100; ++i)
	{
		if (string[i + 1] == '$')
		{
			printf("%c", string[i]);
		}
		if (string[i] != '$' && string[i + 1] != '$')
		{
			printf("%c ", string[i]);
		}
	}
}

bool isOperator1(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isOperator2(char symbol)
{
	return symbol == '*' || symbol == '/';
}

bool isNumber(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool shuntingYard(char* input, char* output)
{
	Stack* stack = createStack();

	const int length = strlen(input);

	if (length == 0)
	{
		return false;
	}

	int j = 0;

	for (int i = 0; i < length; ++i)
	{	

		if (isNumber(input[i]))
		{
			output[j] = input[i]; 
			j++;

			if (isNumber(input[i + 1]))
			{
				output[j] = '$';
				j++;
			}
		}

		if (input[i] == '+' || input[i] == '-')
		{
			while (!isEmpty(stack) && isOperator1(checkHead(stack)))
			{
				output[j] = pop(stack);
				j++;
			}
			push(input[i], stack);
		}

		if (input[i] == '*' || input[i] == '/')
		{
			if (j == 0)
			{
				deleteStack(stack);
				return false;
			}
			while (!isEmpty(stack) && isOperator2(checkHead(stack)))
			{
				output[j] = pop(stack);
				j++;
			}
			push(input[i], stack);
		}

		if (input[i] == '(')
		{
			push(input[i], stack);
		}

		if (input[i] == ')')
		{
			while (!isEmpty(stack) && checkHead(stack) != '(')
			{
				output[j] = pop(stack);
				j++;
				if (isEmpty(stack))
				{
					return false;
				}
			}
			pop(stack);
		}
	}

	while (!isEmpty(stack))
	{
		if (checkHead(stack) == '(')
		{
			deleteStack(stack);
			return false;
		}
		output[j] = pop(stack);
		j++;
	}

	deleteStack(stack);
	return true;
}

bool test()
{
	char testInput1[] = { "(1 + 1) * 2" };
	char testOutput1[100]{};
	shuntingYard(testInput1, testOutput1);
	if (strcmp(testOutput1, "11+2*") != 0)
	{
		return false;
	}

	char testInput2[] = { "((1+1)*2" };
	char testOutput2[100]{};
	if (shuntingYard(testInput2, testOutput2))
	{
		return false;
	}

	char testInput3[] = { "(1+1)*2)" };
	char testOutput3[100]{};
	if (shuntingYard(testInput3, testOutput3))
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

	char input[100]{};
	printf("Введите выражение в инфиксной форме:\n");
	scanf("%[^\n]%*c", &input);
	
	char output[100]{};
	if (shuntingYard(input, output))
	{
		printString(output);
	}
	else
	{
		printf("Некорректный ввод");
	}

	return 0;
}