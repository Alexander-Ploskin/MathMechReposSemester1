#include <stdio.h>
#include "WorkWithTables.h"

void printComments(FILE* filePtr, int** FSMTable, char* header, int sizeOfHeader)
{
	int currentStatement = 0;
	while (!feof(filePtr))
	{
		char symbol = fgetc(filePtr);
		int indexOfSymbol = index(header, sizeOfHeader, symbol);
		if (currentStatement == 3 && FSMTable[indexOfSymbol][currentStatement] == 0)
		{
			printf("*/\n");
		}
		if (currentStatement == 1 && FSMTable[indexOfSymbol][currentStatement] == 2)
		{
			printf("/");
		}
		currentStatement = FSMTable[indexOfSymbol][currentStatement];
		if (currentStatement == 2)
		{
			printf("%c", symbol);
		}
	}
}

int main()
{
	FILE* FSMPtr = fopen("FSM.txt", "r");

	int lengthOfStrings = 0;
	int lengthOfColumns = 0;
	fscanf(FSMPtr, "%d", &lengthOfStrings);
	fscanf(FSMPtr, "%d", &lengthOfColumns);

	char* header = new char[lengthOfStrings]{};
	int** FSMTable = createTable(lengthOfStrings, lengthOfColumns);
	readTableFromFile(FSMPtr, FSMTable, lengthOfStrings, lengthOfColumns, header);

	fclose(FSMPtr);

	FILE* filePtr = fopen("input.txt", "r");
	printComments(filePtr, FSMTable, header, lengthOfStrings);
	fclose(filePtr);

	deleteTable(FSMTable, header, lengthOfStrings);

	return 0;
}