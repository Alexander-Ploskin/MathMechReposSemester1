#include <stdio.h>
#include <string.h>
#include "List.h"

struct ListElement
{
	ListElement* next = nullptr;
	char value[maxLength]{};
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

void add(List* list, Type value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement;
		strcpy(list->head->value, value);
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		if (strcmp(currentElement->next->value, value) > 0)
		{
			currentElement->next = new ListElement{ currentElement->next };
			strcpy(currentElement->next->value, value);
			return;
		}
		currentElement = currentElement->next;
	}
	currentElement->next = new ListElement;
	strcpy(currentElement->next->value, value);
}

bool contains(List* list, Type value)
{
	if (isEmpty(list))
	{
		return false;
	}
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (strcmp(currentElement->value, value) == 0)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
	return false;
}

void printListToFile(List* list, FILE* filePtr)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* currentElement = list->head;

	while (currentElement != nullptr)
	{
		fprintf(filePtr, "%s", currentElement->value);
		currentElement = currentElement->next;
	}
}