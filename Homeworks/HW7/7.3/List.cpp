#include <stdio.h>
#include <string.h>
#include "List.h"

struct ListElement
{
	TypeOfValue mainValue[maxLength]{};
	TypeOfValue additionalValue[maxLength]{};
	ListElement* next = nullptr;
	ListElement* previous = nullptr;
};

struct List
{
	ListElement* head = nullptr;
	ListElement* tail = nullptr;
	int listSize = 0;
};

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

List* createList()
{
	return new List;
}

void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		ListElement* temp = list->head->next;
		delete list->head;
		list->head = temp;
		list->head->previous = nullptr;
	}
	delete list;
}

void printList(List* list, bool mainFirst)
{
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (mainFirst)
		{
			printf("%s- %s\n", currentElement->mainValue, currentElement->additionalValue);
		}
		else
		{
			printf("%s- %s\n", currentElement->additionalValue, currentElement->mainValue);
		}
		currentElement = currentElement->next;
	}
}

void push(List* list, TypeOfValue* mainValue, TypeOfValue* additionalValue)
{
	if (isEmpty(list))
	{
		list->head = new ListElement;
		list->tail = list->head;
		strcpy(list->head->mainValue, mainValue);
		strcpy(list->head->additionalValue, additionalValue);
		list->listSize++;
		return;
	}
	list->head->previous = new ListElement;
	list->head->previous->next = list->head;
	list->head = list->head->previous;
	strcpy(list->head->mainValue, mainValue);
	strcpy(list->head->additionalValue, additionalValue);
	list->listSize++;
}

void popFromTail(List* list, TypeOfValue* mainValueBuffer, TypeOfValue* additionalValueBuffer)
{
	if (list->head == list->tail)
	{
		strcpy(mainValueBuffer, list->tail->mainValue);
		strcpy(additionalValueBuffer, list->tail->additionalValue);
		delete list->head;
		list->head = nullptr;
		list->tail = nullptr;
		list->listSize = 0;
		return;
	}
	strcpy(mainValueBuffer, list->tail->mainValue);
	strcpy(additionalValueBuffer, list->tail->additionalValue);
	ListElement* temp = list->tail->previous;
	delete list->tail;
	list->tail = temp;
	list->tail->next = nullptr;
	list->listSize--;
}

bool isLarger(List* list1, List* list2)
{
	return list1->tail->mainValue > list2->tail->mainValue;
}

int whatSize(List* list)
{
	return list->listSize;
}

void pushFromListToNewList(List* list, List* newList)
{
	char mainValueInList[maxLength]{};
	char additionalValueInList[maxLength]{};
	popFromTail(list, mainValueInList, additionalValueInList);
	push(newList, mainValueInList, additionalValueInList);
}

void transfer(List* list, List* newList, int howMuch)
{
	for (int i = 1; i <= howMuch; ++i)
	{
		char mainValueOfTail[maxLength]{};
		char additionalValueOfTail[maxLength]{};
		popFromTail(list, mainValueOfTail, additionalValueOfTail);
		push(newList, mainValueOfTail, additionalValueOfTail);
	}
}





