#include  "list.h"
#include <stdio.h>

struct List
{
	ListElement* head = nullptr;
	ListElement* tail = nullptr;
};

struct ListElement
{
	int number;
	ListElement* next;
};

List* createList()
{
	return new List;
}

bool isEmpty(List* list)
{
	return list->tail == nullptr;
}

void push(List* list, int number)
{
	if (isEmpty(list))
	{
		list->tail = new ListElement{ number, nullptr };
		list->head = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		list->head = new ListElement{number, list->head };
		list->tail->next = list->head;
	}
}

void deleteElement(List* list, ListElement* previousElement)
{
	ListElement* help = previousElement->next->next;
	if (previousElement->next == list->head)
	{
		list->head = help;
	}
	else if (previousElement->next == list->tail)
	{
		list->tail = previousElement;
	}
	delete previousElement->next;
	previousElement->next = help;
}

void printList(List* list)
{
	if (!isEmpty(list))
	{
		ListElement* currentElement = list->head;
		while (currentElement != list->tail)
		{
			printf("%d ", currentElement->number);
			currentElement = currentElement->next;
		}
		printf("%d\n", list->tail->number);
	}
}

int counting(List* list, int m)
{
	ListElement* currentElement = list->head;
	while (currentElement->next != currentElement)
	{
		for (int i = 1; i < m; ++i)
		{
			currentElement = currentElement->next;
		}

		deleteElement(list, currentElement);
	}
	int result = currentElement->number;
	delete currentElement;
	delete list;
	return result;
}


