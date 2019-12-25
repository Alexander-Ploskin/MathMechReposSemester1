#include <string.h>
#include <stdio.h>
#include "List.h"

struct ListElement
{
	int value = 0;
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

void addToList(List* list, int value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value };
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		currentElement = currentElement->next;
	}
	currentElement->next = new ListElement{ value };
}

void printList(List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		printf("%d\n", currentElement->value);
		currentElement = currentElement->next;
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

void writeListToFile(List* list, FILE* filePtr)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		fprintf(filePtr, "%d ", currentElement->value);
		currentElement = currentElement->next;
	}
	fprintf(filePtr, "%d", currentElement->value);
}




