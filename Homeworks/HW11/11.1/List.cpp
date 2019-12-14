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

void addToList(List* list, int value)
{
	list->head = new ListElement{ value, list->head };
}

int popFromList(List* list)
{
	if (isEmpty(list))
	{
		return -1;
	}
	return list->head->value;
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
		printf("%d ", currentElement->value);
		currentElement = currentElement->next;
	}

	printf("\n");
}