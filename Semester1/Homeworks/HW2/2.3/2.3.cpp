#include <stdio.h>


void countingSort(int* array, int arraySize)
{
	int minimum = 0;
	int maximum = 0;
	for (int i = 0; i < arraySize; ++i)
	{
		if (array[i] > maximum)
		{
			maximum = array[i];
		}
		if (array[i] < minimum)
		{
			minimum = array[i];
		}
	}

	int  range = maximum - minimum;
	int* counterArray = new int[range + 1]{ 0 };
	for (int i = 0; i < arraySize; ++i)
	{
		counterArray[array[i] - minimum]++;
	}

	for (int i = 0, j = 0; i <= range; ++i)
	{
		for (; counterArray[i] > 0; --counterArray[i])
		{
			array[j] = i + minimum;
			j++;
		}
	}

	delete[] counterArray;
}


void bubbleSort(int* array, int arraySize)
{
	for (int i = 0; i <= arraySize - 2; ++i)
	{
		for (int j = i + 1; j < arraySize; ++j)
		{
			if (array[j] < array[i])
			{
				int t = array[j];
				array[j] = array[i];
				array[i] = t;
			}
		}
	}
}


int main()
{
	printf("Enter the array size: \n");
	int arraySize = 0;
	scanf("%d", &arraySize);
	int* array = new int[arraySize];

	printf("Fill the array: \n");
	for (int i = 0; i < arraySize; ++i)
	{
		scanf("%d", &array[i]);
	}

	countingSort(array, arraySize);

	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d ", array[i]);
	}
	delete[] array;
	return 0;
}