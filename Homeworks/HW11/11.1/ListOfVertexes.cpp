#include "ListOfVertexes.h"

struct ListElement
{
	int vertex = 0;
	int distance = 0;
	ListElement* next = nullptr;
};

struct ListOfVertexes
{
	ListElement* head = nullptr;
};

ListOfVertexes* createListOfVertexes()
{
	return new ListOfVertexes;
}

bool isEmpty(ListOfVertexes* list)
{
	return list->head == nullptr;
}

void deleteListOfVertexes(ListOfVertexes* list)
{
	while (!isEmpty(list))
	{
		ListElement* help = list->head->next;
		delete list->head;
		list->head = help;
	}
	delete list;
}

void addVertex(ListOfVertexes* list, int distance, int vertex)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ vertex, distance, list->head };
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		if (currentElement->vertex == vertex)
		{
			currentElement->distance = distance;
			return;
		}
		currentElement = currentElement->next;
	}
	currentElement->next = new ListElement{ vertex, distance, nullptr };
}

ListElement* findParentOfListElement(ListOfVertexes* list, int vertex)
{
	if (isEmpty(list))
	{
		return nullptr;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		if (currentElement->next->vertex == vertex)
		{
			return currentElement;
		}
		currentElement = currentElement->next;
	}
	return nullptr;
}

void removeVertex(ListOfVertexes* list, int vertex)
{
	if (isEmpty(list))
	{
		return;
	}
	if (list->head->vertex == vertex)
	{
		ListElement* help = list->head->next;
		delete list->head;
		list->head = help;
	}
	ListElement* parent = findParentOfListElement(list, vertex);
	if (parent == nullptr)
	{
		return;
	}
	ListElement* help = parent->next->next;
	delete parent->next;
	parent->next = help;
}

int nearestVertex(ListOfVertexes* list)
{
	if (isEmpty(list))
	{
		return -1;
	}
	int minDistance = maxDistance;
	int nearestVertex = 0;
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (currentElement->distance < minDistance)
		{
			minDistance = currentElement->distance;
			nearestVertex = currentElement->vertex;
		}
		currentElement = currentElement->next;
	}
	return nearestVertex;
}

ListOfVertexes** createArrayOfListsOfVertexes(int numberOfLists)
{
	ListOfVertexes** result = new ListOfVertexes * [numberOfLists] {};
	for (int i = 0; i < numberOfLists; ++i)
	{
		result[i] = createListOfVertexes();
	}

	return result;
}

void deleteArrayOfListsOfVertexes(ListOfVertexes** array, int numberOfLists)
{
	for (int i = 0; i < numberOfLists; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
}