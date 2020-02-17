#include "Distributor.h"
#include "List.h"
#include "set.h"

List** distribution(int** adjacencyMatrix, int* capitals, int numberOfTowns, int numberOfStates)
{
	bool* occuped = new bool[numberOfTowns] {}; //Занятые города
	for (int i = 0; i < numberOfStates; ++i) 
	{
		occuped[capitals[i] - 1] = true;  //Считаем столицы занятыми
	}

	bool continueDistribution = true;

	List** result = new List*  [numberOfStates] {};  //Списки городов, занятых каждым государством

	for (int i = 0; i < numberOfStates; ++i)
	{
		result[i] = createList();
		add(result[i], capitals[i] - 1);
	}

	Set** adjacentTowns = new Set * [numberOfStates] {}; //Множество смежных с государством городов
	for (int i = 0; i < numberOfStates; ++i)
	{
		adjacentTowns[i] = createSet();
	}

	while (continueDistribution)
	{
		continueDistribution = false;

		
	}

}