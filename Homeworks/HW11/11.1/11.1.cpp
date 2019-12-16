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
	return distribution(adjacencyMatrix, capitals, numberOfTowns, numberOfStates);
	deleteMatrix(adjacencyMatrix, numberOfTowns);
	delete[] capitals;
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

	List* rightDistribution1[2]{};
	int array11[] = { 1, 2, 4, 5 };
	int array12[] = { 3 };
	rightDistribution1[0] = createListByArray(array11, 4);
	rightDistribution1[1] = createListByArray(array12, 1);
	bool test1 = arrayOfListscmp(list1, rightDistribution1, 2, 2);

	List* rightDistribution2[2]{};
	int array21[] = { 1 };
	int array22[] = { 2 };
	rightDistribution2[0] = createListByArray(array21, 1);
	rightDistribution2[1] = createListByArray(array22, 1);
	bool test2 = arrayOfListscmp(list2, rightDistribution2, 2, 2);

	List* rightDistribution3[2]{};
	int array31[] = { 1, 2, 6 ,7 };
	int array32[] = { 3, 4, 5 };
	rightDistribution3[0] = createListByArray(array31, 4);
	rightDistribution3[1] = createListByArray(array32, 3);
	bool test3 = arrayOfListscmp(list3, rightDistribution3, 2, 2);

	List* rightDistribution4[1]{};
	int array4[] = { 1 };
	rightDistribution4[0] = createListByArray(array4, 1);
	bool test4 = arrayOfListscmp(list4, rightDistribution4, 1, 1);

	deleteListsOfTheArray(rightDistribution1, 2);
	deleteListsOfTheArray(rightDistribution2, 2);
	deleteListsOfTheArray(rightDistribution3, 2);
	deleteListsOfTheArray(rightDistribution4, 1);
	deleteArrayOfLists(list1, 2);
	deleteArrayOfLists(list2, 2);
	deleteArrayOfLists(list3, 2);
	deleteArrayOfLists(list4, 1);


	fclose(filePtr1);
	fclose(filePtr2);
	fclose(filePtr3);
	fclose(filePtr4);

	return test1 && test2 && test3 && test4;
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