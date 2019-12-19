#include <stdio.h>
#include "Matrix.h"

int** createMatrix(int size)
{
	int** matrix = new int* [size] {};
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size] {};
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

void deleteMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

bool matrixcmp(int** matrix1, int** matrix2, int size1, int size2)
{
	if (size1 != size2)
	{
		return false;
	}
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size1; ++j)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}