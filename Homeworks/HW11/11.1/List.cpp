#include <stdio.h>
#include "List.h"

struct ListElement
{
	int value = 0;
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

void addToList(List* list, int value)
{
	list->head = new ListElement{ value, list->head };
}

int popFromList(List* list)
{
	if (isEmpty(list))
	{
		return -1;
	}
	return list->head->value;
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

List** createArrayOfLists(int numberOfLists)
{
	List** result = new List * [numberOfLists] {};
	for (int i = 0; i < numberOfLists; ++i)
	{
		result[i] = createList();
	}

	return result;
}

void deleteArrayOfLists(List** arrayOfLists, int numberOfLists)
{
	for (int i = 0; i < numberOfLists; ++i)
	{
		deleteList(arrayOfLists[i]);
	}
	delete[] arrayOfLists;
}

bool removeFromList(List* list, int value)
{
	if (isEmpty(list))
	{
		return false;
	}
	if (list->head->value == value)
	{
		ListElement* help = list->head;
		list->head = list->head->next;
		delete help;
		return true;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		if (currentElement->next->value == value)
		{
			ListElement* help = currentElement->next->next;
			delete currentElement->next;
			currentElement->next = help;
			return true;
		}
		currentElement = currentElement->next;
	}

	return false;
}

List* createListByArray(int* array, int sizeOfArray)
{
	List* result = createList();
	for (int i = 0; i < sizeOfArray; ++i)
	{
		addToList(result, array[i]);
	}
	return result;
}

bool isEquivalentLists(List* list1, List* list2)
{
	ListElement* currentElement = list1->head;
	while (currentElement != nullptr)
	{
		if (!removeFromList(list2, currentElement->value))
		{
			return false;
		}
		currentElement = currentElement->next;
	}
	return true;
}

bool arrayOfListsCmp(List** array1, List** array2, int sizeOfArray1, int sizeOfArray2)
{
	if (sizeOfArray1 != sizeOfArray2)
	{
		return false;
	}
	for (int i = 0; i < sizeOfArray1; ++i)
	{
		if (!isEquivalentLists(array1[i], array2[i]))
		{
			return false;
		}
	}
	return true;
}

void deleteListsOfTheArray(List** arrayOfLists, int numberOfLists)
{
	for (int i = 0; i < numberOfLists; ++i)
	{
		deleteList(arrayOfLists[i]);
	}
}