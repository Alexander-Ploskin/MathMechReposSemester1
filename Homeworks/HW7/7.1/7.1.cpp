#include <stdio.h>
#include <locale.h>
#include "list.h"

bool test()
{
	List* testList = createList();

	push(testList, 5);
	push(testList, 4);
	push(testList, 50);
	push(testList, -100);

	bool test1 = isSorted(testList);
	bool test2 = isContains(testList, 4);
	deleteElement(testList, 4);
	bool test3 = isContains(testList, 4);

	deleteList(testList);

	return test1 && test2 && !test3;
}

int main()
{
	if (!test())
	{
		return 1;
	}
	setlocale(LC_ALL, "Russian");

	int choice = -1;
	List* list = createList();

	printf("Номера команд:\n");
	printf("0 – выйти\n");
	printf("1 – добавить значение в сортированный список\n");
	printf("2 – удалить значение из списка\n");
	printf("3 – распечатать список\n");

	while (choice != 0)
	{
		printf("Для продолжение работы введите номер команды\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			printf("Введите значение:\n");
			int input = 0;
			scanf("%d", &input);
			push(list, input);
			break;
		}
		case 2:
		{
			printf("Введите значение, которое нужно удалить:\n");
			int input = 0;
			scanf("%d", &input);
			deleteElement(list, input);
			break;
		}
		case 3:
		{
			printList(list);
			break;
		}
		case 0:
		{
			deleteList(list);
			break;
		}
		default: 
			printf("Введите номер существующей команды\n");
			continue;
		}
	}

	return 0;
}