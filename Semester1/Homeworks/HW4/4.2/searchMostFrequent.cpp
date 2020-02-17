#include "searchMostFrequent.h"

int searchMostFrequent(int* array, int arraySize)
{
	int record = 0;
	int recordNumber = 0;
	int current = 1;
	for (int i = 0; i < arraySize; ++i)
	{
		if (array[i] == array[i + 1] || i == arraySize)
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
	return recordNumber;
}