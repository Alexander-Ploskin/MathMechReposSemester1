#include <stdio.h>
#include "Distributor.h"
#include "List.h"
#include "set.h"
#include "Matrix.h"

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

	Set** setOfAdjacencyVertexes = new Set * [numberOfStates] {};
	for (int i = 0; i < numberOfStates; ++i)
	{
		setOfAdjacencyVertexes[i] = createSet();
	}

	bool continueDistribution = true;

	while (continueDistribution)
	{
		continueDistribution = false;

		for (int i = 0; i < numberOfStates; ++i) //Шаг алгоритма для каждой столицы
		{
			int lastAddedTown = popFromList(result[i]);
			Set* currentSet = setOfAdjacencyVertexes[i];
			for (int j = 0; j < numberOfTowns; ++j) //Обновление множества смежных вершин
			{
				if (adjacencyMatrix[lastAddedTown - 1][j] > 0 && !occupied[j])
				{
					add(currentSet, adjacencyMatrix[lastAddedTown - 1][j], j + 1);
				}
			}
			int nearestTown = nearestVertex(currentSet);
			while (occupied[nearestTown - 1] && !isEmpty(currentSet))
			{
				remove(currentSet, adjacencyMatrix[lastAddedTown - 1][nearestTown - 1]);
				nearestTown = nearestVertex(currentSet);
			}
			if (isEmpty(setOfAdjacencyVertexes[i]))
			{
				break;
			}
			addToList(result[i], nearestTown);
			remove(currentSet, adjacencyMatrix[lastAddedTown - 1][nearestTown - 1]);
			occupied[nearestTown - 1] = true;
			continueDistribution = true;
		}
	}

	delete[] occupied;
	for (int i = 0; i < numberOfStates; ++i)
	{
		deleteSet(setOfAdjacencyVertexes[i]);
	}
	delete setOfAdjacencyVertexes;
	return result;
}