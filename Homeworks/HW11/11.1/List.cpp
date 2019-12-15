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

List* createListByArray(int* array, int arraySize)
{
	List* result = createList();

	for (int i = 0; i < arraySize; ++i)
	{
		addToList(result, array[i]);
	}

	return result;
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

void deleteArrayOfLists(List** listOfLists, int numberOfLists)
{
	for (int i = 0; i < numberOfLists; ++i)
	{
		deleteList(listOfLists[i]);
	}
	delete listOfLists;
}

bool arrayOfListsCmp(List** listOfLists1, List** listOfLists2, int sizeOfArray1, int sizeOfArray2)
{
	if (sizeOfArray1 != sizeOfArray2)
	{
		return false;
	}
	for (int i = 0; i < sizeOfArray1; ++i)
	{
		for (int j = 0; j < sizeOfArray2; ++j)
		{
			if (!listcmp(listOfLists1[i], listOfLists2[j]))
			{
				return false;
			}
		}
	}

	return true;
}

List** createListOfListsByArray(int** array, int* sizeOfArrays, int sizeOfSizeOfArrays)
{
	for (int i = 0; i < sizeOfSizeOfArrays; ++i)
	{
		for (int j = )
	}
}