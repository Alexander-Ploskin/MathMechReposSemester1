#include <stdio.h>
#include <stdlib.h>

int selectionLeft(int* array, int r, int l)
{
	while (r > l)
	{
		if (array[l] >= array[0])
		{
			return l;
		}
		else
		{
			l++;
		}
	}
}

int selectionRight(int* array, int r, int l)
{
	while (r > l)
	{
		if (array[r] < array[0])
		{
			return r;
		}
		else
		{
			r--;
		}
	}
}

void processingArray(int* array, int arraySize)
{
	int r = arraySize - 1;
	int l = 1;
	while (r > l)
	{
		r = selectionRight(array, r, l);
		l = selectionLeft(array, r, l);
		if (r > l)
		{
			int t = array[r];
			array[r] = array[l];
			array[l] = t;
		}
		r--;
		l++;
	}
}

int main()
{
	const int arraySize = 10;
	int array[arraySize]{ 0 };
	for (int i = 0; i < arraySize; ++i)
	{
		array[i] = rand() % 15;
	}

	processingArray(array, arraySize);

	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d ", array[i]);
	}

	return 0;
}