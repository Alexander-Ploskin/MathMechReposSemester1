#include "PriorityQueue.h"

struct QueueElement
{
	int value = 0;
	int key = 0;
};

struct PriorityQueue
{
	QueueElement* array[maxNumberOfElements]{};
	int sizeOfQueue = 0;
};

PriorityQueue* createQueue()
{
	return new PriorityQueue;
}

void deleteQueue(PriorityQueue* queue)
{
	for (int i = 0; i < queue->sizeOfQueue; ++i)
	{
		delete queue->array[i];
	}
	delete[] queue->array;
}

bool isEmptyQueue(PriorityQueue* queue)
{
	return queue->sizeOfQueue == 0;
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
	while (2 * index + 1 < queue->sizeOfQueue)
	{
		int indexOfRightChild = 2 * index + 1;
		int indexOfLeftChild = 2 * index + 2;
		int j = indexOfLeftChild;
		if (indexOfRightChild < queue->sizeOfQueue && queue->array[indexOfRightChild]->key <= queue->array[indexOfLeftChild]->key)
		{
			j = indexOfRightChild;
		}
		if (queue->array[index]->key <= queue->array[j]->key)
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

void enqueue(PriorityQueue* queue, int value, int key)
{
	queue->sizeOfQueue++;
	queue->array[queue->sizeOfQueue - 1] = new QueueElement{ value, key};
	siftUp(queue, queue->sizeOfQueue - 1);
}

int dequeue(PriorityQueue* queue)
{
	if (isEmptyQueue(queue))
	{
		return -1;
	}
	int result = queue->array[0]->value;
	delete queue->array[0];
	queue->array[0] = queue->array[queue->sizeOfQueue - 1];
	queue->sizeOfQueue--;
	siftDown(queue, 0);
	return result;
}