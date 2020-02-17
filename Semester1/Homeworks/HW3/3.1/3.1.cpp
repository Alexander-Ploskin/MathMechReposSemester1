#include <stdio.h>
#include <stdlib.h>

bool doesProgramWork(int* array, int arraySize)
{
	if (arraySize < 2)
	{
		return true;
	}
	int i = 1;
	while (array[i] >= array[i - 1])
	{
		++i;
	}

	return i == arraySize;
}

void swap(int* array, int i, int j)
{
	const int t = array[i];
	array[i] = array[j];
	array[j] = t;
}

void insertionSort(int* array, int low, int high)
{
	for (int border = low; border < high; ++border)
	{
		for (int i = border; i >= low; --i)
		{
			if (array[i + 1] < array[i])
			{
				swap(array, i, i + 1);
			}
			else
			{
				break;
			}
		}
	}
}

int selectionPivot(int* array, int low, int high)
{
	int selectionArray[3]{};
	selectionArray[0] = array[low];
	selectionArray[1] = array[(low + high) / 2];
	selectionArray[2] = array[high];

	insertionSort(selectionArray, 0, 2);

	return selectionArray[1];
}


int partition(int* array, int low, int high)
{
	int pivot = selectionPivot(array, low, high);
	int l = low;
	int r = high;

	while (high > low)
	{
		if (array[l] < pivot)
		{
			l++;
		}
		else if (array[r] >= pivot)
		{
			r--;
		}
		else
		{
			swap(array, l, r);
		}
	}
	if (low == l)
	{
		l = low + 1;
	}
	return l;
}


void quicksort(int* array, int low, int high)
{
	if (high - low + 1 > 1)
	{
		if (high - low + 1 > 10)
		{
			if (!doesProgramWork(array, high - low + 1))
			{
				int border = partition(array, low, high);
				quicksort(array, low, border - 1);
				quicksort(array, border, high);
			}
		}
		else
		{
			insertionSort(array, low, high);
		}
	}
}

bool testCheck(int* array, int arraySize)
{
	quicksort(array, -1, arraySize - 1);
	return doesProgramWork(array, arraySize);
}

bool test()
{
	int test1Array[1]{ 1 };
	if (!testCheck(test1Array, sizeof(test1Array) / sizeof(int)))
	{

		printf("Error in test1!\n");
		return false;
	}

	int test2Array[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	if (!testCheck(test2Array, sizeof(test2Array) / sizeof(int)))
	{
		printf("Error in test2!\n");
		return false;
	}

	int test3Array[10]{ -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	if (!testCheck(test3Array, sizeof(test3Array) / sizeof(int)))
	{
		printf("Error in test3!\n");
		return false;
	}

	int test4Array[10000];
	for (int i = 0; i < 10000; ++i)
	{
		test4Array[i] = rand() % 10000;
	}
	if (!testCheck(test4Array, sizeof(test4Array) / sizeof(int)))
	{
		printf("Error in test4!\n");
		return false;
	}

	int test5Array[10]{ 1, 2, 1, 3, 1, 4, 1, 3, 1, 2 };
	if (!testCheck(test5Array, sizeof(test5Array) / sizeof(int)))
	{
		printf("Error in test5!\n");
		return false;
	}

	int* test6Array = new int[0];
	if (!testCheck(test6Array, sizeof(test6Array) / sizeof(int)))
	{
		printf("Error in test6!\n");
		delete[] test6Array;
		return false;
	}
	delete[] test6Array;

	return true;
}

void output(int* array, int arraySize)
{
	printf("\n");
	printf("Sorted array: \n");

	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	if (!test())
	{
		printf("Program doesn't work :( Try again!");
		return -1;
	}

	int arraySize = 0;
	printf("Enter the size of the array: \n");
	scanf("%d", &arraySize);
	printf("Fill the array: \n");
	int* array = new int[arraySize];
	for (int i = 0; i < arraySize; ++i)
	{
		scanf("%d", &array[i]);
	}

	if (arraySize < 2)
	{
		output(array, arraySize);
	}
	else
	{
		quicksort(array, -1, arraySize - 1);
		output(array, arraySize);
	}

	delete[] array;
	return 0;
}
