#include <stdio.h>
#include "List.h"

void distribution(List*& adjacencyList, List*& listOfOccupiedTowns)
{
	const int numberOfTowns = sizeof(adjacencyList) / sizeof(List * *);
	const int numberOfStates = sizeof(listOfOccupiedTowns) / sizeof(List * *);

	while (true)
	{
		bool endOfDistribution = true;

		for (int i = 0; i < numberOfStates; ++i)
		{
			int nearestTown = 0;
			int minDistance = maxDistance;
			int currentNearestTown = SearchOfNearestTown(listOfOccupiedTowns[i], minDistance);
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

	List** adjacencyList = new List * [numberOfTowns] {};

	for (int i = 0; i < numberOfTowns; ++i)
	{
		adjacencyList[i] = createList();
	}

	for (int i = 0; i < numberOfRoads; ++i)
	{
		int numberOfVertex1 = 0;
		int numberOfVertex2 = 0;
		int distance = 0;

		fscanf(filePtr, "%d", &numberOfVertex1);
		fscanf(filePtr, "%d", numberOfVertex2);
		fscanf(filePtr, "%d", &distance);

		addToList(adjacencyList[numberOfVertex1], numberOfVertex2, distance);
		addToList(adjacencyList[numberOfVertex2], numberOfVertex1, distance);
	}
	
	int numberOfStates = 0;
	fscanf(filePtr, "%d", &numberOfStates);

	List** listOfOccupiedTowns = new List * [numberOfStates] {};

	for (int i = 0; i < numberOfStates; ++i)
	{
		listOfOccupiedTowns[i] = createList();
		addToList(listOfOccupiedTowns[i], i + 1, 0);
	}

	return 0;
}