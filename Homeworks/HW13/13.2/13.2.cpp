#include <stdio.h>
#include <string.h>
#include "WorkWithTables.h"

const int maxLength = 10000;

void deleteTrash(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	i--;
	while (string[i] == ' ' || string[i] == '\n')
	{
		string[i] = '\0';
		i--;
	}
}

char* highlightComments(FILE* filePtr, int** fsmTable, char* header, int sizeOfHeader)
{
	char bufferString[maxLength]{};
	int i = 0;
	int currentState = 0;
	while (!feof(filePtr))
	{
		char symbol = fgetc(filePtr);
		int indexOfSymbol = index(header, sizeOfHeader, symbol);
		if (currentState == 3 && fsmTable[indexOfSymbol][currentState] == 0)
		{
			bufferString[i] = '/';
			i++;
		}
		if (currentState == 1 && fsmTable[indexOfSymbol][currentState] == 2)
		{
			bufferString[i] = '/';
			i++;
		}
		currentState = fsmTable[indexOfSymbol][currentState];
		if (currentState == 2 || currentState == 3)
		{
			bufferString[i] = symbol;
			i++;
		}
	}
	return bufferString;
}

bool test(int** fsmTable, char* header, int lengthOfStrings)
{
	FILE* filePtr1 = fopen("test1.txt", "r");
	char* buffer1 = highlightComments(filePtr1, fsmTable, header, lengthOfStrings);
	fclose(filePtr1);
	deleteTrash(buffer1);
	bool test1 = strcmp(buffer1, "/*comment***/") == 0;
	
	FILE* filePtr2 = fopen("test2.txt", "r");
	char* buffer2 = highlightComments(filePtr2, fsmTable, header, lengthOfStrings);
	fclose(filePtr2);
	deleteTrash(buffer2);
	bool test2 = strcmp(buffer2, "/**/") == 0;

	FILE* filePtr3 = fopen("test3.txt", "r");
	char* buffer3 = highlightComments(filePtr3, fsmTable, header, lengthOfStrings);
	fclose(filePtr3);
	deleteTrash(buffer3);
	bool test3 = strcmp(buffer3, "/*/*/") == 0;

	return test1 && test2 && test3;
}

int main()
{
	FILE* fsmPtr = fopen("FSM.txt", "r");

	int lengthOfStrings = 0;
	int lengthOfColumns = 0;
	fscanf(fsmPtr, "%d", &lengthOfStrings);
	fscanf(fsmPtr, "%d", &lengthOfColumns);

	char* header = new char[lengthOfStrings]{};
	int** fsmTable = createTable(lengthOfStrings, lengthOfColumns);
	readTableFromFile(fsmPtr, fsmTable, lengthOfStrings, lengthOfColumns, header);

	fclose(fsmPtr);

	if (!test(fsmTable, header, lengthOfStrings))
	{
		deleteTable(fsmTable, header, lengthOfStrings);
		return 1;
	}

	FILE* filePtr = fopen("input.txt", "r");
	char* buffer = highlightComments(filePtr, fsmTable, header, lengthOfStrings);
	fclose(filePtr);

	deleteTable(fsmTable, header, lengthOfStrings);

	printf("%s", buffer);

	return 0;
}