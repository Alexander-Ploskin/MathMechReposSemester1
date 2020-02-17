#include <stdio.h>
#include <locale.h>

void deleteArray(int** array, int lengthOfStrings)
{
	for (int i = 0; i < lengthOfStrings; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
}

int** createArray(int lengthOfStrings, int lengthOfColumns)
{
	int** table = new int*[lengthOfStrings] {};
	for (int i = 0; i < lengthOfStrings; ++i)
	{
		table[i] = new int [lengthOfColumns] {};
	}
	return table;
}

bool isMinInString(int** table, int lengthOfStrings, int indexOfString, int number)
{
	for (int i = 0; i < lengthOfStrings; ++i)
	{
		if (number > table[indexOfString][i])
		{
			return false;
		}
	}
	return true;
}

bool isMinInColumn(int** table, int lengthOfColumns, int indexOfColumn, int number)
{
	for (int i = 0; i < lengthOfColumns; ++i)
	{
		if (number > table[i][indexOfColumn])
		{
			return false;
		}
	}
	return true;
}

void printPoints(int** table, int lengthOfStrings, int lengthOfColumns)
{
	for (int i = 0; i < lengthOfColumns; ++i)
	{
		for (int j = 0; j < lengthOfColumns; ++j)
		{
			if (isMinInColumn(table, lengthOfColumns, j, table[i][j]) && isMinInString(table, lengthOfStrings, i, table[i][j]))
			{
				printf("%d ", table[i][j]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	printf("Введите количество строк и столбцов\n");
	int lengthOfStrings = 0;
	int lengthOfColumns = 0;
	scanf("%d", &lengthOfStrings);
	scanf("%d", &lengthOfColumns);
	int** table = createArray(lengthOfStrings, lengthOfColumns);
	printf("Заполните массив целыми числами\n");
	for (int i = 0; i < lengthOfColumns; ++i)
	{
		for (int j = 0; j < lengthOfStrings; ++j)
		{
			scanf("%d", &table[i][j]);
		}
	}

	printf("Следующие элементы являются седловыми:\n");
	printPoints(table, lengthOfStrings, lengthOfColumns);

	deleteArray(table, lengthOfStrings);

	return 0;
}