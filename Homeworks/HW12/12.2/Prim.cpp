#include "Prim.h"
#include "Matrix.h"
#include "ListOfVertexes.h"

int** createMinimumSpenningTree(int** adjacencyMatrix, int size)
{
	if (size == 0)
	{
		return {0};
	}

	int** newAdjacencyMatrix = createMatrix(size);
	bool* used = new bool[size] {};
	int numberOfUsedVertexes = 1;
	ListOfVertexes* listOfAdjacentVertexes = createListOfVertexes();
	int lastAddedVertex = 0;

	while (numberOfUsedVertexes <= size)
	{
		for (int i = 0; i < size; ++i)
		{
			if (adjacencyMatrix[lastAddedVertex][i] > 0)
			{
				addVertex(listOfAdjacentVertexes, adjacencyMatrix[lastAddedVertex][i], i, lastAddedVertex);
			}
		}

		int newVertex = 0; //Поиск новой вершины (если не можем найти, то заканчиваем алгоритм)
		int adjacentVertex = 0;
		while (true)
		{
			if (isEmpty(listOfAdjacentVertexes))
			{
				delete[] used;
				deleteListOfVertexes(listOfAdjacentVertexes);
				return newAdjacencyMatrix;
			}
			newVertex = nearestVertex(listOfAdjacentVertexes, adjacentVertex);
			removeVertex(listOfAdjacentVertexes, newVertex);
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
	deleteListOfVertexes(listOfAdjacentVertexes);

	return newAdjacencyMatrix;
}