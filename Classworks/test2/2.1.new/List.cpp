#include <stdio.h>
#include <string.h>
#include "List.h"

struct ListElement
{
	int value = 0;
	ListElement* next = nullptr;
	ListElement* previous = nullptr;
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

void add(List* list, int value)
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
	currentElement->next = new ListElement{ value, nullptr, currentElement };
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
		printf("%d ", currentElement->value);
		currentElement = currentElement->next;
	}
	printf("\n");
}

ListElement* lastElement(List* list)
{
	if (isEmpty(list))
	{
		return nullptr;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		currentElement = currentElement->next;
	}
	return currentElement;
}

List* reverse(List* listToReverse)
{
	if (isEmpty(listToReverse))
	{
		return nullptr;
	}
	List* result = createList();

	ListElement* currentElement = lastElement(listToReverse);

	while (currentElement != nullptr)
	{
		add(result, currentElement->value);
		currentElement = currentElement->previous;
	}

	return result;
}

void fillList(char* string, List* list)
{
	ListElement* currentElement = list->head;

	int i = 0;

	while (i < strlen(string))
	{
		if (string[i] != ' ')
		{
			add(list, string[i] - 48);
		}
		i++;
	}
}

bool listcmp(List* list1, List* list2)
{
	ListElement* currentElement1 = list1->head;
	ListElement* currentElement2 = list2->head;

	while (currentElement1 != nullptr)
	{
		if (currentElement2 == nullptr)
		{
			return false;
		}
		if (currentElement1->value != currentElement2->value)
		{
			return false;
		}
		currentElement1 = currentElement1->next;
		currentElement2 = currentElement2->next;
	}

	if (currentElement2 != nullptr)
	{
		return false;
	}

	return true;
}