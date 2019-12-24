#include "PriorityQueue.h"

const int initialSizeOfQueue = 2;

struct QueueElement
{
	int value = 0;
	int key = 0;
};

struct PriorityQueue
{
	QueueElement** array = new QueueElement* [initialSizeOfQueue]{};
	int numberOfElements = 0;
	int sizeOfQueue = initialSizeOfQueue;
};

PriorityQueue* createQueue()
{
	return new PriorityQueue;
}

void deleteQueue(PriorityQueue* queue)
{
	for (int i = 0; i < queue->numberOfElements; ++i)
	{
		delete queue->array[i];
	}
	delete[] queue->array;
	delete queue;
}

bool isEmptyQueue(PriorityQueue* queue)
{
	return queue->numberOfElements == 0;
}

void swap(PriorityQueue* queue, int index1, int index2)
{
	if (index1 == index2)
	{
		return;
	}
	QueueElement* temp = queue->array[index1];
	queue->array[index1] = queue->array[index2];
	queue->array[index2] = temp;
}

void siftDown(PriorityQueue* queue, int index)
{
	while (2 * index + 1 < queue->numberOfElements)
	{
		int indexOfRightChild = 2 * index + 1;
		int indexOfLeftChild = 2 * index + 2;
		int j = indexOfLeftChild;
		if (indexOfRightChild < queue->numberOfElements && queue->array[indexOfRightChild]->key >= queue->array[indexOfLeftChild]->key)
		{
			j = indexOfRightChild;
		}
		if (queue->array[index]->key >= queue->array[j]->key)
		{
			break;
		}
		swap(queue, index, j);
		index = j;
	}
}

void siftUp(PriorityQueue* queue, int index)
{
	while (queue->array[index]->key > queue->array[(index - 1) / 2]->key)
	{
		swap(queue, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

void resize(PriorityQueue* queue)
{
	QueueElement** newArray = new QueueElement * [queue->sizeOfQueue * 2];
	for (int i = 0; i < queue->numberOfElements; ++i)
	{
		newArray[i] = queue->array[i];
	}
	queue->sizeOfQueue *= 2;
	delete[] queue->array;
	queue->array = newArray;
}

void enqueue(PriorityQueue* queue, int value, int key)
{
	queue->numberOfElements++;
	queue->array[queue->numberOfElements - 1] = new QueueElement{ value, key };
	siftUp(queue, queue->numberOfElements - 1);
	if (queue->numberOfElements / queue->sizeOfQueue >= 0.9)
	{
		resize(queue);
	}
}

int dequeue(PriorityQueue* queue)
{
	if (isEmptyQueue(queue))
	{
		return -1;
	}
	int result = queue->array[0]->value;
	delete queue->array[0];
	queue->array[0] = queue->array[queue->numberOfElements - 1];
	queue->numberOfElements--;
	siftDown(queue, 0);
	return result;
}