#include <stdio.h>
#include "Analyzer.h"

bool test()
{
	char test1String[] = "17B10-mm";
	char test2String[] = "17B11-mm";
	char test3String[] = "17B1-mm";
	char test4String[] = "17B10-m";
	char test5String[] = "1B10-mm";
	char test6String[] = "17N10-mm";
	char test7String[] = "ireug93875";

	bool test1 = isNumberOfGroup(test1String);
	bool test2 = !isNumberOfGroup(test2String);
	bool test3 = isNumberOfGroup(test3String);
	bool test4 = !isNumberOfGroup(test4String);
	bool test5 = !isNumberOfGroup(test5String);
	bool test6 = !isNumberOfGroup(test6String);
	bool test7 = !isNumberOfGroup(test7String);

	return test1 && test2 && test3 && test4 && test5 && test6 && test7;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	printf("Enter the string shorter the 10 symbols:\n");

	char buffer[maxLength]{};
	scanf("%s", &buffer);

	if (isNumberOfGroup(buffer))
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Incorrect!\n");
	}

	return 0;
}