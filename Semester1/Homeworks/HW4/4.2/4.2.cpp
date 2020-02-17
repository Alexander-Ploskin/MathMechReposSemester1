#include <stdio.h>
#include <stdlib.h>
#include "shellSort.h"
#include "searchMostFrequent.h"

bool testCheck(int* array, int arraySize, int realMostFrequent)
{
	if (arraySize == 0)
	{
		return true;
	}
	shellSort(array, arraySize);


	return realMostFrequent == searchMostFrequent(array, arraySize);
}

bool test()
{
	int testArray1[6]{ 1, 2, 2, 3, 3, 3 };
	if (!testCheck(testArray1, 6, 3))
	{
		printf("Test1 failed");
		return false;
	}

	int testArray2[6]{ 3, 3, 3, 2, 2, 1 };
	if (!testCheck(testArray2, 6, 3))
	{
		printf("Test2 failed");
		return false;
	}

	int testArray3[6]{ 1, 1, 1, 1, 1, 1 };
	if (!testCheck(testArray3, 6, 1))
	{
		printf("Test3 failed");
		return false;
	}

	int testArray4[1]{ 1 };
	if (!testCheck(testArray4, 1, 1))
	{
		printf("Test4 failed");
		return false;
	}

	int* testArray5 = new int[0];
	if (!testCheck(testArray5, 0, 0))
	{
		printf("Test5 failed");
		return false;
	}
	delete[] testArray5;

	return true;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	FILE* filePtr = fopen("array.txt", "r");
	int array[1001]{};
	int arraySize = 0;
	while (fscanf(filePtr, "%d", &array[arraySize]) != EOF)
	{
		arraySize++;
	}

	if (arraySize == 0)
	{
		printf("Fill the array!");
		return 1;
	}

	shellSort(array, arraySize);

	printf("Original array: \n");
	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d ", array[i]);
	}

	printf("\n Most frequent number is %d", searchMostFrequent(array, arraySize));

	fclose(filePtr);

	return 0;
}

