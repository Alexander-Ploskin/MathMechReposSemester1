#include  "list.h"
#include <stdio.h>

struct List
{
	ListElement* head = nullptr;
	ListElement* root = nullptr;
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
	return list->root == nullptr;
}

void push(List* list, int number)
{
	if (isEmpty(list))
	{
		list->root = new ListElement{ number, nullptr };
		list->head = list->root;
		list->root->next = list->head;
	}
	else
	{
		list->head = new ListElement{number, list->head };
		list->root->next = list->head;
	}
}

void deleteElement(List* list, ListElement* previousElement)
{
	ListElement* help = previousElement->next->next;
	if (previousElement->next == list->head)
	{
		list->head = help;
	}
	else if (previousElement->next == list->root)
	{
		list->root = previousElement;
	}
	delete previousElement->next;
	previousElement->next = help;
}

void printList(List* list)
{
	if (!isEmpty(list))
	{
		ListElement* currentElement = list->head;
		while (currentElement != list->root)
		{
			printf("%d ", currentElement->number);
			currentElement = currentElement->next;
		}
		printf("%d\n", list->root->number);
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


