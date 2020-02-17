#include <stdio.h>
#include <string.h>

int main()
{
	printf("Enter a string shorter than 100 characters: \n");
	char string[101]{};
	gets_s(string);
	printf("Enter a substring shorter than 100 characters: \n");
	char substring[101]{};
	gets_s(substring);
	int counter = 0;
	const int lengthOfString = strlen(string);
	const int lengthOfSubString = strlen(substring);
	for (int i = 0; i <= lengthOfString - lengthOfSubString; ++i)
	{
		int j = i;
		for (; j <= i + lengthOfSubString - 1; ++j)
			if (string[j] != substring[j - i])
			{
				break;
			}
		if (j == i + lengthOfSubString)
		{
			counter += 1;
		}
	}
	printf("Substring is included in the string %d times", counter);
	return 0;
}