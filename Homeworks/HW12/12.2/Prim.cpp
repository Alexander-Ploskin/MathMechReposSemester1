#include "Prim.h"
#include "Matrix.h"
#include "PriorityQueue.h"

int** createMinimumSpanningTree(int** adjacencyMatrix, int size)
{
	if (size == 0)
	{
		return {0};
	}

	int** newAdjacencyMatrix = createMatrix(size);
	bool* used = new bool[size] {};
	int numberOfUsedVertexes = 1;
	PriorityQueue* adjacentVertexes = createQueue();
	int lastAddedVertex = 0;

	while (numberOfUsedVertexes <= size)
	{
		for (int i = 0; i < size; ++i)
		{
			if (adjacencyMatrix[lastAddedVertex][i] > 0)
			{
				addToQueue(adjacentVertexes, i, adjacencyMatrix[lastAddedVertex][i], lastAddedVertex);
			}
		}

		int newVertex = 0; //Поиск новой вершины (если не можем найти, то заканчиваем алгоритм)
		int adjacentVertex = 0;
		while (true)
		{
			if (isEmptyQueue(adjacentVertexes))
			{
				delete[] used;
				deleteQueue(adjacentVertexes);
				return newAdjacencyMatrix;
			}
			newVertex = extractMin(adjacentVertexes, adjacentVertex);
			if (!used[newVertex])
			{
				break;
			}
		}

		used[newVertex] = true; //Добавление новой вершины в дерево
		lastAddedVertex = newVertex;
		newAdjacencyMatrix[newVertex][adjacentVertex] = adjacencyMatrix[newVertex][adjacentVertex];
		newAdjacencyMatrix[adjacentVertex][newVertex] = adjacencyMatrix[adjacentVertex][newVertex];
		numberOfUsedVertexes++;
	}

	delete[] used;
	deleteQueue(adjacentVertexes);
	return newAdjacencyMatrix;
}