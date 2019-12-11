#include "WorkWithTables.h"
#include <stdio.h>

int** createTable(int lengthOfStrings, int lengthOfColumns)
{
	int** table = new int* [lengthOfStrings] {};
	for (int i = 0; i < lengthOfStrings; ++i)
	{
		table[i] = new int[lengthOfColumns] {};
	}
	return table;
}

void printTable(int** table, int lengthOfStrings, int lengthOfColumns)
{
	for (int i = 0; i < lengthOfColumns; ++i)
	{
		for (int j = 0; j < lengthOfStrings; ++j)
		{
			printf("%d ", table[j][i]);
		}
		printf("\n");
	}
}

void readTableFromFile(FILE* filePtr, int** table, int lengthOfStrings, int lengthOfColumns, char* header)
{
	int i = 0;
	while (i < lengthOfStrings)
	{
		char buffer = ' ';
		fscanf(filePtr, "%c", &buffer);
		if (buffer == ' ' || buffer == '\n')
		{
			continue;
		}
		header[i] = buffer;
		i++;
	}

	int j = 0;
	while (j < lengthOfColumns)
	{
		int buffer = 0;
		fscanf(filePtr, "%d", &buffer);
		int k = 0;
		while (k < lengthOfStrings)
		{
			fscanf(filePtr, "%d", &buffer);
			if (buffer == 32)
			{
				continue;
			}
			table[k][j] = buffer;
			k++;
		}
		j++;
	}
}

void deleteTable(int** table, char* header, int lengthOfStrings)
{
	for (int i = 0; i < lengthOfStrings; ++i)
	{
		delete[] table[i];
	}
	delete[] table;
	delete[] header;
}

int index(char* array, int size, char symbol)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (array[i] == symbol)
		{
			return i;
		}
	}
	return size - 1;
}