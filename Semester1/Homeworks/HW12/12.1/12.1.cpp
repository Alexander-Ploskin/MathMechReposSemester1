#include <stdio.h>
#include "KMP.h"

const int maxSizeOfSubstring = 20;
const int maxSizeOfString = 10000;

bool test()
{
	char string1[] = { "abcabeabcabcabd" };
	char substing1[] = { "abcabd" };
	bool test1 = findIndexOfFirstOccurence(string1, substing1) == 9;

	char string2[] = { "abcbda" };
	char substring2[] = { "j" };
	bool test2 = findIndexOfFirstOccurence(string2, substring2) < 0;

	char string3[] = { "abcha" };
	char substring3[] = { "abcha" };
	bool test3 = findIndexOfFirstOccurence(string3, substring3) == 0;

	char string4[] = { "" };
	char substring4[] = { "" };
	bool test4 = findIndexOfFirstOccurence(string4, substring4) < 0;

	char string5[] = { "f" };
	char substring5[] = { "false" };
	bool test5 = findIndexOfFirstOccurence(string5, substring5) < 0;

	return test1 && test2 && test3 && test4 && test5;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	FILE* filePtr = fopen("input.txt", "r");

	char substring[maxSizeOfSubstring]{};
	printf("Enter the substring\n");
	scanf("%s", &substring);

	char string[maxSizeOfString]{};
	int i = 0;
	while (!feof(filePtr))
	{
		fscanf(filePtr, "%c", &string[i]);
		i++;
	}

	fclose(filePtr);

	const int firstIndex = findIndexOfFirstOccurence(string, substring);

	if (firstIndex < 0)
	{
		printf("The substring doesn't occur in the string\n");
	}
	else
	{
		printf("The first time a substring occurs in %d index of the string\n", firstIndex);
	}

	return 0;
}