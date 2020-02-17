#include <stdio.h>
#include <string.h>
#include "List.h"

struct ListElement
{
	char value[maxLength]{};
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

void add(List* list, char* value)
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
		currentElement = currentElement->next;
	}
	currentElement->next = new ListElement;
	strcpy(currentElement->next->value, value);
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

void printList(List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		printf("%s", currentElement->value);
		currentElement = currentElement->next;
	}
	printf("\n");
}

bool containsOther(List* list, ListElement* element)
{
	if (isEmpty(list))
	{
		return false;
	}
	ListElement* currentElement = list->head;

	while (currentElement != nullptr)
	{
		if (strcmp(currentElement->value, element->value) == 0 && element != currentElement)
		{
			return true;
		}
	}

	return false;
}

void deleteElement(ListElement* element, List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != element)
	{
		currentElement = currentElement->next;
	}
	ListElement* help = currentElement->next->next;
	delete currentElement->next;
	currentElement->next = help;
}

void deleteCopies(ListElement* listElement, List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* currentElement = list->head;

	while (currentElement != nullptr)
	{
		ListElement* help = currentElement->next;
		if (currentElement != listElement && strcmp(currentElement->value, listElement->value) == 0)
		{
			deleteElement(currentElement, list);
		}
		currentElement = help;
	}
}

void clearList(List* list)
{
	if (isEmpty(list))
	{
		return;
	}

	ListElement* currentElement = list->head;

	while (currentElement != nullptr)
	{
		deleteCopies(currentElement, list);
		currentElement = currentElement->next;
	}
}

bool checkRight(List* list)
{
	if (isEmpty(list))
	{
		return true;
	}
	ListElement* currentElement = list->head;

	while (currentElement != nullptr)
	{
		if (containsOther(list, currentElement))
		{
			return false;
		}
		currentElement = currentElement->next;
	}
	return true;
}