#include <stdio.h>
#include "Matrix.h"
#include "Prim.h"

bool test()
{
	FILE* filePtrTest1 = fopen("test1.txt", "r");
	FILE* filePtrTrue1 = fopen("trueTree1.txt", "r");
	int numberOfVertexes1 = 0;
	fscanf(filePtrTest1, "%d", &numberOfVertexes1);
	int** adjacencyMatrixTest1 = createMatrix(numberOfVertexes1);
	readMatrixFromFile(adjacencyMatrixTest1, numberOfVertexes1, filePtrTest1);
	adjacencyMatrixTest1 = createMinimumSpanningTree(adjacencyMatrixTest1, numberOfVertexes1);

	fscanf(filePtrTrue1, "%d", &numberOfVertexes1);
	int** adjacencyMatrixTrue1 = createMatrix(numberOfVertexes1);
	readMatrixFromFile(adjacencyMatrixTrue1, numberOfVertexes1, filePtrTrue1);

	fclose(filePtrTest1);
	fclose(filePtrTrue1);

	bool test1 = matrixcmp(adjacencyMatrixTest1, adjacencyMatrixTrue1, numberOfVertexes1, numberOfVertexes1);
	deleteMatrix(adjacencyMatrixTest1, numberOfVertexes1);
	deleteMatrix(adjacencyMatrixTrue1, numberOfVertexes1);

	return test1;
}

int main()
{
	if (!test())
	{
		return 1;
	}
	FILE* filePtr = fopen("input.txt", "r");

	int numberOfVertexes = 0;
	fscanf(filePtr, "%d", &numberOfVertexes);
	int** adjacencyMatrix = createMatrix(numberOfVertexes);
	readMatrixFromFile(adjacencyMatrix, numberOfVertexes, filePtr);
	fclose(filePtr);

	int** minimumSpenningTree = createMinimumSpanningTree(adjacencyMatrix, numberOfVertexes);
	printMatrix(minimumSpenningTree, numberOfVertexes);
	deleteMatrix(adjacencyMatrix, numberOfVertexes);
	deleteMatrix(minimumSpenningTree, numberOfVertexes);

	return 0;
}