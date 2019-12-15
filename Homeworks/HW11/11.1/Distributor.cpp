#include <stdio.h>
#include "Distributor.h"
#include "List.h"
#include "Matrix.h"
#include "ListOfVertexes.h"

void updateListOfAdjacentVertexes(int** adjacencyMatrix, bool* occupied, ListOfVertexes* list, int newVertex, int numberOfTowns)
{
	for (int j = 0; j < numberOfTowns; ++j) //Обновление множества смежных вершин
	{
		if (adjacencyMatrix[newVertex - 1][j] > 0 && !occupied[j])
		{
			addVertex(list, adjacencyMatrix[newVertex - 1][j], j + 1);
		}
	}
}

List** distribution(int** adjacencyMatrix, int* capitals, int numberOfTowns, int numberOfStates)
{
	bool* occupied = new bool[numberOfTowns] {}; //Битовая маска оккупированных городов
	for (int i = 0; i < numberOfStates; ++i)
	{
		occupied[capitals[i] - 1] = true;
	}

	List** result = createListOfLists(numberOfStates); //Результат распределения
	for (int i = 0; i < numberOfStates; ++i)
	{
		addToList(result[i], capitals[i]);
	}

	ListOfVertexes** listOfAdjacentVertexes = createArrayOfLists(numberOfStates);//Список смежных вершин для каждой столицы

	bool continueDistribution = true;

	while (continueDistribution)
	{
		continueDistribution = false;
		for (int i = 0; i < numberOfStates; ++i) //Шаг алгоритма для каждой столицы
		{
			int lastAddedTown = popFromList(result[i]);
			ListOfVertexes* currentList = listOfAdjacentVertexes[i];
			updateListOfAdjacentVertexes(adjacencyMatrix, occupied, currentList, lastAddedTown, numberOfTowns);
			int nearestTown = nearestVertex(currentList);
			removeVertex(currentList, nearestTown);
			while (occupied[nearestTown - 1] && nearestTown > 0)
			{
				nearestTown = nearestVertex(currentList);
				removeVertex(currentList, nearestTown);
			}
			if (nearestTown > 0)
			{
				addToList(result[i], nearestTown);
				occupied[nearestTown - 1] = true;
				continueDistribution = true;
			}
		}
	}

	delete[] occupied;
	deleteArrayOfLists(listOfAdjacentVertexes, numberOfStates);
	return result;
}