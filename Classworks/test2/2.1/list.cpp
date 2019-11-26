#include <stdio.h>
#include "list.h"

struct ListElement
{
	int value = 0;
	ListElement* next = nullptr;
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

void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		ListElement* help = list->head;
		list->head = list->head->next;
		delete help;
	}
	delete list;
}

bool contains(List* list, int value)
{
	if (isEmpty(list))
	{
		return false;
	}
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (currentElement->value == value)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
	return false;
}

void add(List* list, int value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement;
		list->head->value = value;
		return;
	}
	ListElement* currenElement = list->head;
	while (currenElement->next != nullptr)
	{
		currenElement = currenElement->next;
	}
	currenElement->next = new ListElement;
	currenElement->next->value = value;
}

int length(List* list)
{
	if (isEmpty(list))
	{
		return 0;
	}
	int result = 0;
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		result++;
		currentElement = currentElement->next;
	}
	return result;
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

void ListCopy(List* newList, List* source)
{
	if (isEmpty(source))
	{
		return;
	}
	ListElement* currentElement = source->head;
	while (currentElement != nullptr)
	{
		add(newList, currentElement->value);
		currentElement = currentElement->next;
	}
}

List* increasingList(List* list)
{
	int maxLength = 0;
	List* listOfMaxLength = createList();
	if (isEmpty(list))
	{
		return nullptr;
	}

	List* currentList = createList();
	add(currentList, list->head->value);
	ListElement* currentElement = list->head->next;
	int lastValue = -1;
	while (currentElement != nullptr)
	{
		if (currentElement->value > lastValue)
		{
			add(currentList, currentElement->value);
		}
		else
		{
			const int lengthOfCurrentList = length(currentList);
			if (lengthOfCurrentList > maxLength)
			{
				deleteList(listOfMaxLength);
				listOfMaxLength = createList();
				ListCopy(listOfMaxLength, currentList);
				maxLength = lengthOfCurrentList;
			}
			deleteList(currentList);
			currentList = createList();
		}
		lastValue = currentElement->value;
		currentElement = currentElement->next;
	}
	return listOfMaxLength;
}

bool compareOfLists(List* list1, List* list2)
{
	if (isEmpty(list1) && isEmpty(list2))
	{
		return true;
	}
	if (isEmpty(list1) || isEmpty(list2))
	{
		return false;
	}
	
	while (!isEmpty(list1) && !isEmpty(list2))
	{
		if (list1->head->value != list2->head->value)
		{
			return false;
		}
		ListElement* help1 = list1->head;
		ListElement* help2 = list2->head;

		list1->head = list1->head->next;
		list2->head = list2->head->next;

		delete help1;
		delete help2;
	}
	if (!isEmpty(list1) || !isEmpty(list2))
	{
		return false;
	}
}



