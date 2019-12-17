#include <stdio.h>
#include "List.h"

bool compareFileWithArray(FILE* filePtr, int* array, int arraySize)
{
	int i = 0;
	while (!feof(filePtr))
	{
		if (i == arraySize)
		{
			return false;
		}
		int buffer = 0;
		fscanf(filePtr, "%d", &buffer);
		if (array[i] != buffer)
		{
			return false;
		}
	}
	return true;
}

void createNewFile(FILE* inputPtr, int a, int b, FILE* outputPtr)
{
	List* listOfLessNumbers = createList();
	List* listOfDomesticNumbers = createList();
	List* listOfLargeNumbers = createList();
	while (!feof(inputPtr))
	{
		int buffer = 0;
		fscanf(inputPtr, "%d", &buffer);
		if (buffer < a)
		{
			addToList(listOfLessNumbers, buffer);
		}
		else if (buffer <= b && buffer >= a)
		{
			addToList(listOfDomesticNumbers, buffer);
		}
		else if (buffer > b)
		{
			addToList(listOfLargeNumbers, buffer);
		}
	}
	fclose(inputPtr);

	writeListToFile(listOfLessNumbers, outputPtr);
	writeListToFile(listOfDomesticNumbers, outputPtr);
	writeListToFile(listOfLargeNumbers, outputPtr);

	deleteList(listOfLessNumbers);
	deleteList(listOfDomesticNumbers);
	deleteList(listOfLargeNumbers);
}

bool test()
{
	FILE* inputPtr = fopen("input.txt", "r");

	FILE* outputPtr = fopen("testOutput.txt", "w");
	int testArray[11]{ -1, -7, -3, 4, 5, 0, 2, 4, 8, 9, 10 };
	createNewFile(inputPtr, 0, 7, outputPtr);

	bool test = compareFileWithArray(outputPtr, testArray, 11);
	fclose(inputPtr);
	fclose(outputPtr);
	return test;
}

int main()
{
	if (!test())
	{
		return 1;
	}
	printf("Enter the borders:\n");
	int a = 0;
	int b = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	FILE* filePtr1 = fopen("input.txt", "r");
	FILE* filePtr2 = fopen("output.txt", "w");
	
	createNewFile(filePtr1, a, b, filePtr2);

	fclose(filePtr1);
	fclose(filePtr2);

	return 0;
}