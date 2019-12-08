#include <stdio.h>

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

int** createMatrix(int size)
{
	int** matrix = new int* [size] {};
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size] {};
	}
	return matrix;
}

int main()
{
	int numberOfTowns = 0;
	int numberOfRoads = 0;

	FILE* filePtr = fopen("input.txt", "r");

	fscanf(filePtr, "%d", &numberOfTowns);
	fscanf(filePtr, "%d", &numberOfRoads);

	int** adjacencyMatrix = createMatrix(numberOfTowns);
	
	for (int i = 0; i < numberOfRoads; ++i)
	{
		int town1 = 0;
		int town2 = 0;
		int distance = 0;

		fscanf(filePtr, "%d", &town1);
		fscanf(filePtr, "%d", &town2);
		fscanf(filePtr, "%d", &distance);

		adjacencyMatrix[town1 - 1][town2 - 1] = distance;
		adjacencyMatrix[town2 - 1][town1 - 1] = distance;
	}

	int numberOfStates = 0;
	fscanf(filePtr, "%d", &numberOfStates);
	int* capitals = new int[numberOfStates] {};
	for (int i = 0; i < numberOfStates; ++i)
	{
		fscanf(filePtr, "%d", &capitals[i]);
	}

	fclose(filePtr);

	return 0;
}




















