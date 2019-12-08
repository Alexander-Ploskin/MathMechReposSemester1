#include <stdio.h>
#include "List.h"

struct ListElement
{
	int value = 0;
	ListElement* next;
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
}

void add(List* list, int value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value };
		return;
	}
	list->head = new ListElement{ value, list->head };
}

void printList(List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		printf("%d ", currentElement->value);
		currentElement = currentElement->next;
	}
}
