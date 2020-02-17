#include "List.h"

struct ListElement
{
	int numberOfVertex;
	int distance;
	ListElement* next = nullptr;
};

struct List
{
	ListElement* head = nullptr;
};

List* createList()
{
	return new List;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

bool contains(List* list, int value)
{
	ListElement* currentElement = list->head;
	while (true)
	{
		if (currentElement == nullptr)
		{
			return false;
		}
		if (currentElement->numberOfVertex == value)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
}

void addToList(List* list, int vertex, int distance)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{vertex, distance};
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		currentElement = currentElement->next;
	}
	currentElement->next = new ListElement{ vertex, distance };
}

void removeFromList(List* list, int vertex)
{
	if (isEmpty(list))
	{
		return;
	}
	if (list->head->numberOfVertex == vertex)
	{
		delete list->head;
		list->head = nullptr;
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr && currentElement->next->numberOfVertex != vertex)
	{
		currentElement = currentElement->next;
	}
	if (currentElement->next != nullptr)
	{
		ListElement* help = currentElement->next;
		currentElement->next = currentElement->next->next;
		delete help;
		return;
	}
}

void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		ListElement* help = list->head->next;
		delete list->head;
		list->head = help;
	}
	delete list;
}

int SearchOfNearestTown(List* list, int& distanceBuffer)
{
	int nearestVertex = 0;
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (currentElement->distance < distanceBuffer)
		{
			distanceBuffer = currentElement->distance;
			nearestVertex = currentElement->numberOfVertex;
		}
		currentElement = currentElement->next;
	}
	return nearestVertex;
}