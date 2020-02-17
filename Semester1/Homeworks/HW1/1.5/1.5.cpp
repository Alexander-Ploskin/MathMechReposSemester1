#include <stdio.h>
#include <string.h>

int main()
{
	printf("Enter a string shorter than 100 characters: \n");
	char string[101]{};
	gets_s(string);
	int countOfOpenBrackets = 0;
	int countOfClosedBrackets = 0;
	for (int i = 0; i <= strlen(string); ++i)
	{
		if (string[i] == '(')
		{
			++countOfOpenBrackets;
		}
		if (string[i] == ')')
		{
			++countOfClosedBrackets;
		}
		if (countOfClosedBrackets > countOfOpenBrackets)
		{
			break;
		}
	}
	if (countOfOpenBrackets == countOfClosedBrackets)
	{
		printf("Everything's in order");
	}
	else
	{
		printf("The balance of brackets is broken");
	}
	return 0;
}