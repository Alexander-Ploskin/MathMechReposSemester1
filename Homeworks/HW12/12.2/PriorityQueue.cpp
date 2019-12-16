#include "PriorityQueue.h"

struct QueueElement
{
	int value = 0;
	int key = 0;
	int additionalValue = 0;
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

void shiftDown(PriorityQueue* queue, int index)
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

void shiftUp(PriorityQueue* queue, int index)
{
	while (queue->array[index]->key < queue->array[(index - 1) / 2]->key)
	{
		swap(queue, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

void addToQueue(PriorityQueue* queue, int value, int key, int additionalValue)
{
	queue->sizeOfQueue++;
	queue->array[queue->sizeOfQueue - 1] = new QueueElement{ value, key, additionalValue };
	shiftUp(queue, queue->sizeOfQueue - 1);
}

int extractMin(PriorityQueue* queue, int& bufferOfAdditionalValue)
{
	int result = queue->array[0]->value;
	bufferOfAdditionalValue = queue->array[0]->additionalValue;
	queue->array[0] = queue->array[queue->sizeOfQueue - 1];
	queue->sizeOfQueue--;
	shiftDown(queue, 0);
	return result;
}