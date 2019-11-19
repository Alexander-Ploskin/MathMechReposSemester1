#include <stdio.h>
#include <ctype.h>
#include "HashTable.h"

const int maxLength = 100;

bool isPunctuationMark(char symbol)
{
	return symbol == ',' || symbol == '.' || symbol == '!' || symbol == '?' || symbol == '(' || symbol == ')' || symbol == ':';
}

bool test()
{
	FILE* filePtr = fopen("test.txt", "r");

	HashTable* table = createTable();

	while (!feof(filePtr))
	{
		char word[maxLength]{};
		fscanf(filePtr, "%s", word);
		char cleanWord[maxLength]{};
		int i = 0;
		int j = 0;
		while (word[i] != '\0')
		{
			word[i] = tolower(word[i]);
			if (!isPunctuationMark(word[i]))
			{
				cleanWord[j] = word[i];
				j++;
			}
			i++;
		}
		table = addToTable(table, cleanWord, 1);
	}

	fclose(filePtr);

	char string1[] = "basic";
	char string2[] = "something";
	bool test1 = containsInTable(table, string1);

	removeFromeTable(table, string1);
	bool test2 = containsInTable(table, string1);

	bool test3 = containsInTable(table, string2);

	deleteTable(table);

	return true;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	FILE* filePtr = fopen("input.txt", "r");

	HashTable* table = createTable();
	
	while (!feof(filePtr))
	{
		char word[maxLength]{};
		fscanf(filePtr, "%s", word);
		char cleanWord[maxLength]{};
		int i = 0;
		int j = 0;
		while (word[i] != '\0')
		{
			word[i] = tolower(word[i]);
			if (!isPunctuationMark(word[i]))
			{
				cleanWord[j] = word[i];
				j++;
			}
			i++;
		}
		table = addToTable(table, cleanWord, 1);
	}

	fclose(filePtr);

	printTable(table);

	deleteTable(table);

	return 0;
}