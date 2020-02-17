#include <stdio.h>
#include "Matrix.h"

int** createMatrix(int sizeOfColumn, int sizeOfString)
{
	int** matrix = new int* [sizeOfString] {};
	for (int i = 0; i < sizeOfString; ++i)
	{
		matrix[i] = new int[sizeOfColumn] {};
	}
	return matrix;
}

void printMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void readMatrixFromFile(int** matrix, int size, FILE* filePtr)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			fscanf(filePtr, "%d", &matrix[i][j]);
		}
	}
}

void deleteMatrix(int** matrix, int sizeOfString)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete matrix;
}