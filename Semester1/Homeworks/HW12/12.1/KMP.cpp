#include <stdio.h>
#include "KMP.h"

int findOfMaxRightIndex(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		++i;
	}
	return i - 1;
}

void prefixFunction(char* string, int piArray[], const int maxRightIndexOfString)
{
	piArray[0] = 0;
	int i = 1;
	int j = 0;

	while (i <= maxRightIndexOfString)
	{
		if (string[i] == string[j])
		{
			piArray[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0)
		{
			piArray[i] = 0;
			i++;
		}
		else
		{
			j = piArray[j - 1];
		}
	}
}

int findIndexOfFirstOccurence(char* string, char* substring)
{
	const int maxRightIndexOfString = findOfMaxRightIndex(string);
	const int maxRightIndexOfSubstring = findOfMaxRightIndex(substring);
	if (maxRightIndexOfString < 0 || maxRightIndexOfSubstring < 0)
	{
		return -1;
	}
	if (maxRightIndexOfSubstring > maxRightIndexOfString)
	{
		return -1;
	}

	int* piArray = new int[maxRightIndexOfSubstring + 1] {};

	prefixFunction(substring, piArray, maxRightIndexOfSubstring);

	int l = 0;
	int k = 0;

	while (k <= maxRightIndexOfString)
	{
		if (string[k] == substring[l])
		{
			if (l == maxRightIndexOfSubstring)
			{
				delete[] piArray;
				return k - maxRightIndexOfSubstring;
			}
			k++;
			l++;
		}
		else
		{
			if (l == 0)
			{
				k++;
			}
			else
			{
				l = piArray[l - 1];
			}
		}
	}

	delete[] piArray;
	return -1;
}