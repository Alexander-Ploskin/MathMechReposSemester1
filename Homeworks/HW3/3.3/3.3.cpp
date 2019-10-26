#include <stdio.h>
#include <stdlib.h>


void shellSort(int* array, int arraySize)
{
	for (int step = arraySize / 2; step > 0; step /= 2)
	{
		for (int i = step; i < arraySize; ++i)
		{
			for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
			{
				int t = array[j];
				array[j] = array[j + step];
				array[j + step] = t;
			}
		}
	}
}

int searchMostFrequent(int* array, int arraySize)
{
	int record = 1;
	int recordNumber = 0;
	int current = 1;
	for (int i = 0; i < arraySize; ++i)
	{
		if (i < arraySize - 1)
		{
			if (array[i] == array[i + 1])
			{
				current++;
			}
			else
			{
				if (current > record)
				{
					record = current;
					recordNumber = array[i];
				}
				current = 1;
			}
		}
		else
		{
			current++;
			if (current > record)
			{
				record = current;
				recordNumber = array[i];
			}
		}
	}
	return recordNumber;
}

int findIndexMaximum(int* array, int arraySize)
{
	int max = array[0];
	int iMax = 0;
	for (int i = 0; i < arraySize; ++i)
	{
		if (array[i] > max)
		{
			iMax = i;
			max = array[i];
		}
	}
	return iMax;
}

int findMaximum(int* array, int arraySize)
{
	int max = array[0];
	for (int i = 0; i < arraySize; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int findMinimum(int* array, int arraySize)
{
	int min = array[0];
	for (int i = 0; i < arraySize; ++i)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

bool testCheck(int* array, int arraySize)
{
	if (arraySize == 0)
	{
		return true;
	}
	shellSort(array, arraySize);

	const int max = findMaximum(array, arraySize);
	const int min = findMinimum(array, arraySize);

	int* counterArray = new int[max - min + 1]{};
	for (int i = 0; i < arraySize; ++i)
	{
		counterArray[array[i] - min]++;    
	}

	int realMostFrequent = findIndexMaximum(counterArray, max - min + 1) + min;
	return realMostFrequent == searchMostFrequent(array, arraySize);
}

bool test()
{
	int testArray1[6]{ 1, 2, 2, 3, 3, 3 };
	if (!testCheck(testArray1, 6))
	{
		printf("Error in test1!\n");
		return false;
	}

	int testArray2[6]{ 3, 3, 3, 2, 2, 1 };
	if (!testCheck(testArray2, 6))
	{
		printf("Error in test2!\n");
		return false;
	}

	int testArray3[6]{ 1, 1, 1, 1, 1, 1 };
	if (!testCheck(testArray3, 6))
	{
		printf("Error in test3!\n");
		return false;
	}

	int testArray4[1]{ 1 };
	if (!testCheck(testArray4, 1))
	{
		printf("Error in test4!\n");
		return false;
	}

	int* testArray5 = new int[0];
	if (!testCheck(testArray5, 0))
	{
		printf("Error in test5!\n");
		delete[] testArray5;
		return false;
	}
	delete[] testArray5;

	int testArray6[6]{ -1, -1, -3, 5, 0, -1 };
	if (!testCheck(testArray6, 6))
	{
		printf("Error in test6!\n");
		return false;
	}

	return true;
}

int main()
{
	if (!test())
	{
		printf("Program doesn't work. Try again!");
		return -1;
	}

	const int arraySize = 20;
	int array[arraySize];
	for (int i = 0; i < arraySize; ++i)
	{
		array[i] = rand() % 20;
	}

	if (arraySize == 0)
	{
		return 0;
	}
	shellSort(array, arraySize);

	printf("Array: \n");
	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("Most frequent number is %d", searchMostFrequent(array, arraySize));

	return 0;
}
