#include <string.h>
#include <stdio.h>
#include "List.h"

struct ListElement
{
	char value[maxLength]{};
	int amount = 1;
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

bool contains(List* list, char* value)
{
	ListElement* currentElement = list->head;
	while (true)
	{
		if (currentElement == nullptr)
		{
			return false;
		}
		if (strcmp(currentElement->value, value) == 0)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
}

void addToList(List* list, char* value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement;
		strcpy(list->head->value, value);
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr && strcmp(value, currentElement->next->value) != 0)
	{
		currentElement = currentElement->next;
	}
	if (currentElement->next == nullptr)
	{
		currentElement->next = new ListElement;
		strcpy(currentElement->next->value, value);
		return;
	}
	currentElement->next->amount++;
}

void removeFromList(List* list, char* value)
{
	if (isEmpty(list))
	{
		return;
	}
	if (strcmp(list->head->value, value) == 0)
	{
		if (list->head->amount > 1)
		{
			list->head->amount--;
			return;
		}
		delete list->head;
		list->head = nullptr;
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr && strcmp(currentElement->next->value, value) != 0)
	{
		currentElement = currentElement->next;
	}
	if (currentElement->next != nullptr)
	{
		if (currentElement->next->amount > 1)
		{
			currentElement->next->amount--;
			return;
		}
		ListElement* help = currentElement->next;
		currentElement->next = currentElement->next->next;
		delete help;
		return;
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
		printf("%s - %d", currentElement->value, currentElement->amount);
	}
}

int pop(List* list, char* buffer)
{
	if (isEmpty(list))
	{
		return 0;
	}
	if (list->head->next == nullptr)
	{
		int result = list->head->amount;
		strcpy(buffer, list->head->value);
		delete list->head;
		list->head = nullptr;
		return result;
	}
	ListElement* help = list->head->next;
	strcpy(buffer, list->head->value);
	int result = list->head->amount;
	delete list->head;
	list->head = help;
	return result;
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


