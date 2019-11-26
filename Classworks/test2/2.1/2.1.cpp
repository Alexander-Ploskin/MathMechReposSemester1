#include <stdio.h>
#include <locale.h>
#include "list.h"

bool test()
{
	List* testList = createList();

	List* testList1 = increasingList(testList);

	bool test1 = testList1 == nullptr;

	add(testList, 1);
	add(testList, 2);
	add(testList, 4);
	add(testList, 5);

	int trueOutput1[] = { 1, 2, 4, 5 };
	List* testList2 = createList();
	for (int i = 0; i < 4; ++i)
	{
		add(testList2, trueOutput1[i]);
	}
	bool test2 = compareOfLists(testList2, increasingList(testList));
	delete testList1;
	deleteList(testList2);

	deleteList(testList);
	testList = createList();
	add(testList, 5);
	add(testList, 4);
	add(testList, 2);
	add(testList, 1);
	int trueOutput2[] = { 1 };
	List* testList3 = createList();
	add(testList3, 5);
	bool test3 = compareOfLists(testList3, increasingList(testList));
	deleteList(testList3);

	return test1 && test2 && test3;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	FILE* filePtr = fopen("input.txt", "r");

	List* inputList = createList();

	while (!feof(filePtr))
	{
		int buffer = 0;
		fscanf(filePtr, "%d", &buffer);
		add(inputList, buffer);
	}

	fclose(filePtr);

	List* outputList = increasingList(inputList);
	printList(outputList);
	deleteList(inputList);
	deleteList(outputList);

	return 0;
}
