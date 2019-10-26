#include <stdio.h>
#include "list.h"

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

List* createList()
{
	return new List;
}

ListElement* searchPositionNotInHead(List* list, int searchValue)
{
	ListElement* currentPosition = list->head;
	ListElement* lastPosition = nullptr;
	while (currentPosition != nullptr && currentPosition->value != searchValue)
	{
		lastPosition = currentPosition;
		currentPosition = currentPosition->next;
	}
	if (currentPosition == nullptr)
	{
		return nullptr;
	}
	return lastPosition;
}

bool checkHead(List* list, int searchValue)
{
	return list->head->value == searchValue;
}

void printList(List* list)
{
	ListElement* currentElement = list->head;
	if (isEmpty(list))
	{
		printf("Пустой список\n");
	}
	while (currentElement != nullptr)
	{
		printf("%d ", currentElement->value);
		currentElement = currentElement->next;
	}
	printf("\n");
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

void push(List* list, int value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr };
	}
	else
	{
		ListElement* currentPosition = list->head;
		ListElement* lastPosition = nullptr;
		while (currentPosition != nullptr && value > currentPosition->value)
		{
			lastPosition = currentPosition;
			currentPosition = currentPosition->next;
		}
		if (lastPosition == nullptr)
		{
			list->head = new ListElement{ value, currentPosition };
		}
		else
		{
			lastPosition->next = new ListElement{ value, currentPosition };
		}
	}
}

void deleteElement(List* list, int value)
{
	if (isEmpty(list))
	{
		printf("Удаление из пустого списка\n");
	}
	else
	{
		if (checkHead(list, value))
		{
			ListElement* help = list->head->next;
			delete list->head;
			list->head = help;
		}
		else
		{
			ListElement* lastElement = searchPositionNotInHead(list, value);
			if (lastElement != nullptr)
			{
				ListElement* help = lastElement->next->next;
				delete lastElement->next;
				lastElement->next = help;
			}
		}
	}
}

bool isSorted(List* list)
{
	if (isEmpty(list))
	{
		return true;
	}
	ListElement* currentElement = list->head;
	int lastValue = list->head->value;
	while (currentElement != nullptr)
	{
		if (currentElement->value < lastValue)
		{
			return false;
		}
		lastValue = currentElement->value;
		currentElement = currentElement->next;
	}
	return true;
}

bool isContains(List* list, int searchValue)
{
	if (isEmpty(list))
	{
		return false;
	}
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (currentElement->value == searchValue)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
	return false;
}