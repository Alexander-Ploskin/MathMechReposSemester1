#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "List.h"
#include "MergeSort.h"

bool test()
{
	List* list = createList();

	FILE* filePtr = fopen("test.txt", "r");

	while (!feof(filePtr))
	{
		char name[maxLength]{};
		char phoneNumber[maxLength]{};
		fscanf(filePtr, "%[^-]%*c%*c", name);
		fscanf(filePtr, "%[^\n]%*c", phoneNumber);
		push(list, name, phoneNumber);
	}
	fclose(filePtr);

	list = mergeSort(list);

	bool result = isSorted(list);

	deleteList(list);

	return result;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	setlocale(LC_ALL, "Russian");

	printf("Если вы хотите отсортировать записи по имени, нажмите 1\n");
	printf("Если вы хотите отсортировать записи по номеру телефона, нажмите 2\n");
	int choice = 0;
	while (choice != 1 && choice != 2)
	{
		scanf("%d", &choice);
		if (choice != 1 && choice != 2)
		{
			printf("Введите 1 или 2\n");
		}
	}

	List* list = createList();

	FILE* filePtr = fopen("input.txt", "r");

	while (!feof(filePtr))
	{
		char name[maxLength]{};
		char phoneNumber[maxLength]{};
		fscanf(filePtr, "%[^-]%*c%*c", name);
		fscanf(filePtr, "%[^\n]%*c", phoneNumber);
		if (choice == 1)
		{
			push(list, name, phoneNumber);
		}
		else
		{
			push(list, phoneNumber, name);
		}
	}
	fclose(filePtr);

	list = mergeSort(list);

	printList(list, choice == 1);

	deleteList(list);

	return 0;
}