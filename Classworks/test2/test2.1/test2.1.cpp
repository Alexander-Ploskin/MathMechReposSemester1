#include <stdio.h>
#include "List.h"

bool test()
{
	int test1Array[] = { 1, 2, 3, 2, 1 };
	int test2Array[] = { 1, 2, 3, 4, 2, 1 };
	int test3Array[] = { 1 };
	List* list1 = createList();
	List* list2 = createList();
	List* list3 = createList();
	createListByArray(list1, test1Array, 5);
	createListByArray(list2, test2Array, 6);
	createListByArray(list3, test3Array, 1);

	bool test1 = isSymmetric(list1);
	bool test2 = !isSymmetric(list2);
	bool test3 = isSymmetric(list3);

	deleteList(list1);
	deleteList(list2);
	deleteList(list3);

	return test1 && test2 && test3;
}

int main()
{
	if (!test())
	{
		return 1;
	}
	List* list = createList();
	FILE* filePtr = fopen("input.txt", "r");
	while (!feof(filePtr))
	{
		int buffer = 0;
		fscanf(filePtr, "%d", &buffer);
		add(list, buffer);
	}
	if (isSymmetric(list))
	{
		printf("Symmetric\n");
	}
	else
	{
		printf("Not symmetric\n");
	}
	fclose(filePtr);
	deleteList(list);
}