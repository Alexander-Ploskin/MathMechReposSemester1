#include <stdio.h>
#include "List.h"

void distribution(int* adjencyMatrix, int* states, int numberOfTowns, int numberOfStates)
{
	bool** occupiedByState = new bool* [numberOfTowns] {};
	for (int i = 0; i < numberOfTowns; ++i)
	{
		occupiedByState[i] = new bool[numberOfTowns] {};
	}
	bool* occupied = new bool[numberOfTowns];

	List** listsOfBoundaryTowns = new List * [numberOfStates];
	for (int i = 0; i < numberOfStates; ++i)
	{
		listsOfBoundaryTowns[i] = createList();
	}

	bool endOfDistribution = false;
	while (!endOfDistribution)
	{
		endOfDistribution = true;
		for (int i = 0; i < numberOfStates; ++i)
		{
			for (int i = 0; i < numberOfStates; ++i)
			{
				if (!occupied[i] && adjencyMatrix[states[i]][i] != 0)
				{

				}
			}
		}
	}
}

int main()
{
	FILE* filePtr = fopen("input.txt", "r");

	int numberOfTowns = 0;
	int numberOfRoads = 0;

	fscanf(filePtr, "%d", &numberOfTowns);
	fscanf(filePtr, "%d", &numberOfRoads);

	printf("%d - %d\n", numberOfTowns, numberOfRoads);

	int** adjacencyMatrix = new int*[numberOfTowns] {};
	for (int i = 0; i < numberOfTowns; ++i)
	{
		adjacencyMatrix[i] = new int[numberOfTowns] {};
	}

	for (int i = 0; i < numberOfRoads; ++i)
	{
		int firstVertex = 0;
		int secondVertex = 0;
		int distance = 0;
		fscanf(filePtr, "%d", &firstVertex);
		fscanf(filePtr, "%d", &secondVertex);
		fscanf(filePtr, "%d", &distance);
		adjacencyMatrix[firstVertex - 1][secondVertex - 1] = distance;
		adjacencyMatrix[secondVertex - 1][firstVertex - 1] = distance;
	}

	int numberOfStates = 0;
	fscanf(filePtr, "%d", &numberOfStates);

	int* states = new int[numberOfStates];

	for (int i = 0; i < numberOfStates; ++i)
	{
		fscanf(filePtr, "%d", &states[i]);
		printf("%d\n", states[i]);
	}

	fclose(filePtr);

	for (int i = 0; i < numberOfTowns; ++i)
	{
		for (int j = 0; j < numberOfTowns; ++j)
		{
			printf("%d ", adjacencyMatrix[i][j]);
		}
		printf("\n");
	}

	printf("%d", sizeof(states) / sizeof(int) * 2);

	return 0;
}