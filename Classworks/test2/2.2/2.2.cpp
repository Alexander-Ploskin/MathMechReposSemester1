#include <stdio.h>
#include "List.h"

bool test()
{
	List* list1 = createList();

	FILE* file1Ptr = fopen("test1.txt", "r");
	while (!feof(file1Ptr))
	{
		char buffer[maxLength]{};
		fgets(buffer, maxLength, file1Ptr);
		add(list1, buffer);
	}

	clearList(list1);
	bool test1 = checkRight(list1);
	deleteList(list1);
	fclose(file1Ptr);

	List* list2 = createList();

	FILE* file2Ptr = fopen("test2.txt", "r");
	while (!feof(file2Ptr))
	{
		char buffer[maxLength]{};
		fgets(buffer, maxLength, file2Ptr);
		add(list2, buffer);
	}

	clearList(list2);
	bool test2 = checkRight(list2);
	deleteList(list2);
	fclose(file2Ptr);

	List* list3 = createList();

	FILE* file3Ptr = fopen("test3.txt", "r");
	while (!feof(file3Ptr))
	{
		char buffer[maxLength]{};
		fgets(buffer, maxLength, file3Ptr);
		add(list1, buffer);
	}
	
	clearList(list3);
	bool test3 = checkRight(list3);
	deleteList(list3);
	fclose(file3Ptr);

	return test1 && test2 && test3;
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
		char buffer[maxLength]{};
		fgets(buffer, maxLength, filePtr);
		add(list, buffer);
	}

	fclose(filePtr);

	clearList(list);

	printList(list);

	deleteList(list);

	return 0;
}