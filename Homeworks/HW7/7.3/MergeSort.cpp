#include "MergeSort.h"
#include "List.h"

void clearList(List* listToClean, List* newList)
{
	while (!isEmpty(listToClean))
	{
		pushFromListToNewList(listToClean, newList);
	}
}

List* merge(List* list1, List* list2)
{
	List* newList = createList();

	while (!isEmpty(list1) && !isEmpty(list2))
	{
		if (isLarger(list1, list2))
		{
			pushFromListToNewList(list1, newList);
		}
		else
		{
			pushFromListToNewList(list2, newList);
		}
	}

	if (!isEmpty(list1))
	{
		clearList(list1, newList);
	}

	if (!isEmpty(list2))
	{
		clearList(list2, newList);
	}

	deleteList(list1);
	deleteList(list2);

	return newList;
}

List* mergeSort(List* list)
{
	const int listSize = whatSize(list);
	if (listSize <= 1)
	{
		return list;
	}
	int mid = listSize / 2;

	List* lowList = createList();
	transfer(list, lowList, mid);
	List* highList = createList();
	transfer(list, highList, listSize - mid);

	lowList = mergeSort(lowList);
	highList = mergeSort(highList);

	deleteList(list);

	return merge(lowList, highList);
}






