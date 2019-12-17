#include <stdio.h>
#include <string.h>
#include "WorkWithTables.h"

const int maxLength = 10000;

bool stringCompare(char* string1, char* string2)
{
	const int lengthOfString1 = strlen(string1);

	for (int i = 0; i < lengthOfString1; ++i)
	{
		if (string1[i] != string2[i])
		{
			return false;
		}
	}
	return true;
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
			strcat(bufferString, "*/ ");
			i += 3;
		}
		if (currentState == 1 && fsmTable[indexOfSymbol][currentState] == 2)
		{
			bufferString[i] = '/';
			i++;
		}
		currentState = fsmTable[indexOfSymbol][currentState];
		if (currentState == 2)
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
	char comments1[] = {'/','*','c','o','m','m','e','n','t','*','/' ,'\0' };
	bool test1 = stringCompare(buffer1, comments1);
	
	FILE* filePtr2 = fopen("test2.txt", "r");
	char* buffer2 = highlightComments(filePtr2, fsmTable, header, lengthOfStrings);
	fclose(filePtr2);
	char comments2[] = "/**/";
	bool test2 = strcmp(buffer2, comments2) == 0;

	FILE* filePtr3 = fopen("test3.txt", "r");
	char* buffer3 = highlightComments(filePtr3, fsmTable, header, lengthOfStrings);
	fclose(filePtr3);
	char comments3[] = "";
	bool test3 = strcmp(buffer3, comments3) == 0;

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

	printf("%s\n", buffer);

	return 0;
}