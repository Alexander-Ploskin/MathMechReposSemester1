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
	ListElement* tail = nullptr;
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
		list->tail = list->head;
		return;
	}
	list->head = new ListElement{ value, list->head };
	list->head->next->previous = list->head;
}

void printList(List* list)
{
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		printf("%d ", currentElement->value);
	}
}

void deleteList(List* list)
{
	if (isEmpty(list))
	{
		delete list;
		return;
	}
	while (!isEmpty(list))
	{
		ListElement* help = list->head->next;
		delete list->head;
		list->head = help;
	}
	return;
}

bool isSymmetric(List* list)
{
	if (isEmpty(list))
	{
		return true;
	}
	if (list->head == list->tail)
	{
		return true;
	}
	ListElement* currentElement1 = list->head;
	ListElement* currentElement2 = list->tail;
	while (currentElement1->next != currentElement2)
	{
		if (currentElement1->value != currentElement2->value)
		{
			return false;
		}
		if (currentElement1 == currentElement2)
		{
			return true;
		}
		currentElement1 = currentElement1->next;
		currentElement2 = currentElement2->previous;
	}
	if (currentElement1->value == currentElement2->value)
	{
		return true;
	}
	return false;
}

void createListByArray(List* list, int* array, int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; ++i)
	{
		add(list, array[i]);
	}
}

bool listCmp(List* list1, List* list2)
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