#include "heap.h"

struct HeapElement
{
	int vertex = 0;
	int distance = 0;
	int adjacentVertex = 0;
};

struct Heap
{
	HeapElement** array = nullptr;
	int sizeOfHeap = 0;
};

void swap(Heap* heap, int indexOfElement1, int indexOfElement2)
{
	HeapElement* temp = heap->array[indexOfElement1];
	heap->array[indexOfElement1] = heap->array[indexOfElement2];
	heap->array[indexOfElement2] = temp;
}

bool isEmptyHeap(HeapElement** heap)
{
	return heap[0] == 0;
}

void heapify(Heap* heap, int index)
{

}

void add(Heap* heap, int vertex, int distance, int adjacentVertex)
{
	heap->array[heap->sizeOfHeap] = new HeapElement{ vertex, distance, adjacentVertex };
}

//Возвращает из кучи ближайшую вершину
int popNearestVertex(Heap* heap, int& adjacentVertex);

HeapElement** createHeap(int sizeOfHeap)
{
	HeapElement** result = new HeapElement * [sizeOfHeap] {};
}

//Удаляет кучу
void deleteHeap(Heap* heap);