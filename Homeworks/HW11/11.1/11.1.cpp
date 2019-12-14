#include <stdio.h>
#include "Matrix.h"
#include "List.h"
#include "Distributor.h"

int main()
{
	int numberOfTowns = 0;
	int numberOfRoads = 0;

	FILE* filePtr = fopen("input.txt", "r");

	fscanf(filePtr, "%d", &numberOfTowns);
	fscanf(filePtr, "%d", &numberOfRoads);

	int** adjacencyMatrix = createMatrix(numberOfTowns); //Матрица смежности для данного графа
	
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
	int* capitals = new int[numberOfStates] {}; //Массив столиц
	for (int i = 0; i < numberOfStates; ++i)
	{
		fscanf(filePtr, "%d", &capitals[i]);
	}

	fclose(filePtr);

	List** resultOfDistribution = distribution(adjacencyMatrix, capitals, numberOfTowns, numberOfStates);

	for (int i = 0; i < numberOfStates; ++i)
	{
		printf("State %d ocupies towns:", capitals[i]);
		printList(resultOfDistribution[i]);
	}

	deleteListOfLists(resultOfDistribution, numberOfStates);
	deleteMatrix(adjacencyMatrix, numberOfTowns);

	return 0;
}