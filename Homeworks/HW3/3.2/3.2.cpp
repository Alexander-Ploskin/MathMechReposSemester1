#include <stdio.h>
#include <stdlib.h>

bool isArraySorted(int* array, int low, int high)
{
	const int arraySize = high - low + 1;
	if (arraySize > 1)
	{
		for (int i = low + 1; i <= high; ++i)
		{
			if (array[i] < array[i - 1])
			{
				return false;
			}
		}
	}

	return true;
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
	const int pivot = selectionPivot(array, low, high);
	int l = low;
	int r = high;

	while (l < r)
	{
		if (array[l] < pivot)
		{
			++l;
		}
		else if (array[r] >= pivot)
		{
			--r;
		}
		else
		{
			swap(array, l, r);
		}
	}

	if (l == low)
	{
		l = low + 1;
	}

	return l;
}

void qsort(int* array, int low, int high)
{
	if (high - low > 0)
	{
		const int border = partition(array, low, high);
		qsort(array, low, border - 1);
		qsort(array, border, high);
	}
}

bool doesContain(int* array, int number, int low, int high)
{
	while (high >= low)
	{
		const int mid = (high + low) / 2;
		if (array[mid] == number)
		{
			return true;
		}
		if (array[mid] < number)
		{
			low = mid + 1;
		}
		if (array[mid] > number)
		{
			high = mid - 1;
		}
	}

	return false;
}

bool test()
{
	int test1array[10]{ -1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	qsort(test1array, 0, 9);
	if (!doesContain(test1array, -1, 0, 9) || !doesContain(test1array, 10, 0, 9))
	{
		printf("Test1 failed\n");
		return false;
	}

	int test2array[5]{ 1, 1, 1, 1, 1 };
	qsort(test2array, 0, 4);
	if (!doesContain(test2array, 1, 0, 4) || doesContain(test2array, rand(), 0, 4))
	{
		printf("Test2 failed\n");
		return false;
	}

	int* test3array = new int[0];
	qsort(test3array, 0, 0);
	if (doesContain(test3array, rand(), 0, 0))
	{
		printf("Test3 failed");
		delete[] test3array;
		return false;
	}
	delete[] test3array;

	int* test4array = new int[10000]{};
	for (int i = 0; i < 10000; ++i)
	{
		test4array[i] = -i;
	}
	qsort(test4array, 0, 9999);
	if (!doesContain(test4array, -200, 0, 9999))
	{
		printf("Test4 failed\n");
		delete[] test4array;
		return false;
	}
	delete[] test4array;

	int test5array[10]{ -1, -2, 123, 44, -1000000, 34, 100000, 0, 2, -1 };
	qsort(test5array, 0, 9);
	if (!isArraySorted(test5array, 0, 9))
	{
		printf("Test5 failed\n");
		return false;
	}

	return true;
}

int main()
{
	if (!test())
	{
		return -1;
	}
	printf("Enter n: \n");
	int arraySize = 0;
	scanf("%d", &arraySize);

	printf("Enter k: \n");
	int countOfNumbers = 0;
	scanf("%d", &countOfNumbers);

	int* array = new int[arraySize];
	for (int i = 0; i < arraySize; ++i)
	{
		array[i] = rand();
	}

	qsort(array, 0, arraySize - 1);
	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	for (int i = 0; i < countOfNumbers; ++i)
	{
		int number = rand();
		if (doesContain(array, number, 0, arraySize - 1))
		{
			printf("%d contains in the array\n", number);
		}
		else
		{
			printf("%d doesn't contain in the array\n", number);
		}
	}

	delete[] array;

	return 0;
}