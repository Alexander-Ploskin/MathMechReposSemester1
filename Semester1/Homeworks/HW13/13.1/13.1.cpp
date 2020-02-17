#include <stdio.h>
#include "analyzer.h"

const int maxLength = 100;

bool test()
{
	char string1[] = "123.4";
	bool test1 = isNumber(string1);

	char string2[] = "134.45E+27";
	bool test2 = isNumber(string2);

	char string3[] = "123.234.E-434s";
	bool test3 = !isNumber(string3);

	char string4[] = "";
	bool test4 = !isNumber(string4);

	char string5[] = "notNumber";
	bool test5 = !isNumber(string5);

	char string6[] = "--1";
	bool test6 = !isNumber(string6);

	char string7[] = "123.E";
	bool test7 = !isNumber(string7);

	return test1 && test2 && test3 && test4 && test5 && test6 && test7;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	printf("Enter the string:\n");
	char buffer[maxLength]{};
	scanf("%s", &buffer);
	if (isNumber(buffer))
	{
		printf("String is number\n");
	}
	else
	{
		printf("String is not number\n");
	}

	return 0;
}