#include <stdio.h>
#include "List.h"

bool test()
{
	char string1[] = "1 2 3 4 5";
	char string2[] = " ";
	char string3[] = "5 4 3 2 1";

	List* list1 = createList();
	List* list2 = createList();
	List* list3 = createList();

	fillList(string1, list1);
	fillList(string3, list3);

	bool test1 = reverse(list2) == nullptr;

	bool test2 = listcmp(reverse(list1), list3);

	deleteList(list1);
	deleteList(list2);
	deleteList(list3);

	return test1 && test2;
}

int main()
{
	if (!test())
	{
		return 1;
	}
	FILE* filePtr = fopen("input.txt", "r");

	List* list = createList();

	while (!feof(filePtr))
	{
		int buffer = 0;
		fscanf(filePtr, "%d", &buffer);
		add(list, buffer);
	}

	fclose(filePtr);

	printList(list);

	List* reversedList = reverse(list);

	deleteList(list);

	printList(reversedList);

	deleteList(reversedList);

	return 0;
}