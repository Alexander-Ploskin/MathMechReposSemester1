#include "shellSort.h"

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