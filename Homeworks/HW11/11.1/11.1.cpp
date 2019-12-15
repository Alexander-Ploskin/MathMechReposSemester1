#include <stdio.h>
#include "Matrix.h"
#include "List.h"
#include "Distributor.h"

void readInputFromFile(int**& adjacencyMatrix, int*& capitals, int& numberOfTowns, int& numberOfStates, FILE* filePtr)
{
	int numberOfRoads = 0;
	fscanf(filePtr, "%d", &numberOfTowns);
	fscanf(filePtr, "%d", &numberOfRoads);
	adjacencyMatrix = createMatrix(numberOfTowns);
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

	numberOfStates = 0;
	fscanf(filePtr, "%d", &numberOfStates);
	capitals = new int[numberOfStates] {}; //Массив столиц
	for (int i = 0; i < numberOfStates; ++i)
	{
		fscanf(filePtr, "%d", &capitals[i]);
	}
}

List** createDistribution(FILE* filePtr)
{
	int numberOfTowns = 0;
	int numberOfStates = 0;
	int* capitals = nullptr;
	int** adjacencyMatrix = nullptr;
	readInputFromFile(adjacencyMatrix, capitals, numberOfTowns, numberOfStates, filePtr);
	deleteMatrix(adjacencyMatrix, numberOfTowns);
	delete[] capitals;
	return distribution(adjacencyMatrix, capitals, numberOfTowns, numberOfStates);
}

bool test()
{
	FILE* filePtr1 = fopen("test1.txt", "r");
	FILE* filePtr2 = fopen("test2.txt", "r");
	FILE* filePtr3 = fopen("test3.txt", "r");
	FILE* filePtr4 = fopen("test4.txt", "r");

	List** list1 = createDistribution(filePtr1);
	List** list2 = createDistribution(filePtr2);
	List** list3 = createDistribution(filePtr3);
	List** list4 = createDistribution(filePtr4);

	


	deleteListOfLists(list1, 2);
	deleteListOfLists(list2, );
	deleteListOfLists(list3, );
	deleteListOfLists(list4, );

	fclose(filePtr1);
	fclose(filePtr2);
	fclose(filePtr3);
	fclose(filePtr4);

	return true;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	FILE* filePtr = fopen("input.txt", "r");
	int numberOfTowns = 0;
	int numberOfStates = 0;
	int* capitals = nullptr;
	int** adjacencyMatrix = nullptr;
	readInputFromFile(adjacencyMatrix, capitals, numberOfTowns, numberOfStates, filePtr);
	fclose(filePtr);

	List** resultOfDistribution = distribution(adjacencyMatrix, capitals, numberOfTowns, numberOfStates);

	for (int i = 0; i < numberOfStates; ++i)
	{
		printf("State %d ocupies towns: ", capitals[i]);
		printList(resultOfDistribution[i]);
	}

	deleteArrayOfLists(resultOfDistribution, numberOfStates);
	deleteMatrix(adjacencyMatrix, numberOfTowns);

	return 0;
}