#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "set.h"

bool test()
{
	Set* set = createSet();

	char string1[] = "A";
	char string2[] = "B";
	char string3[] = "C";
	char string4[] = "D";
	char string5[] = "E";
	char string6[] = "F";
	char string7[] = "G";
	char string8[] = "H";
	char string9[] = "I";
	char string10[] = "J";
	char string11[] = "K";

	add(set, 10, string1);
	add(set, 20, string2);
	add(set, 30, string3);
	add(set, 9, string4);
	add(set, 8, string5);
	add(set, 35, string6);
	add(set, 37, string7);
	add(set, 33, string8);
	add(set, 34, string9);
	add(set, 6, string10);
	add(set, 7, string11);

	bool test1 = contains(set, 37);
	bool test2 = contains(set, 10);

	remove(set, 20);
	remove(set, 33);
	remove(set, 10);

	bool test3 = !contains(set, 20);
	bool test4 = !contains(set, 33);
	bool test5 = !contains(set, 10);

	bool test6 = balanced(set);

	deleteSet(set);

	return test1 && test2 && test3 && test4 && test5 && test6;
}

int main()
{
	if (!test())
	{
		return 1;
	}
	setlocale(LC_ALL, "Russian");

	int choice = -1;

	printf("Команды:\n");
	printf("1 - Добавить значение по заданному ключу в словарь\n");
	printf("2 - Получить значение по заданному ключу из словаря\n");
	printf("3 - Проверить наличие заданного ключа в словаре\n");
	printf("4 - Удалить заданный ключ и связанное с ним значение из словаря\n");

	Set* set = createSet();

	while (choice != 0)
	{
		printf("Для продолжения введите номер команды\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			printf("Введите ключ:\n");
			int key = 0;
			scanf("%d", &key);
			printf("Введите строку:\n");
			char string[maxLength]{};
			scanf("%s", string);
			if (contains(set, key))
			{
				setNewValue(set, key, string);
			}
			else
			{
				add(set, key, string);
			}
			break;
		}
		case 2:
		{
			printf("Введите ключ\n");
			int key = 0;
			scanf("%d", &key);
			if (!contains(set, key))
			{
				printf("Записи с таким ключом нет в словаре\n");
				break;
			}
			char bufferString[maxLength]{};
			getValue(set, key, bufferString);
			printf("%s\n", bufferString);
			break;

		}
		case 3:
		{
			printf("Введите ключ\n");
			int key = 0;
			scanf("%d", &key);
			if (!isEmpty(set) && contains(set, key))
			{
				printf("В словаре есть такой ключ\n");
			}
			else
			{
				printf("Такого ключа в словаре нет\n");
			}
			break;
		}
		case 4:
		{
			printf("Введите ключ\n");
			int key = 0;
			scanf("%d", &key);
			if (remove(set, key))
			{
				printf("Ключ и связанное с ним значение удалены из словаря\n");
			}
			else
			{
				printf("Удалить элемент не удалось\n");
			}
			break;
		}
		case 0:
		{
			deleteSet(set);
			break;
		}
		default:
			printf("Введите номер существующей команды\n");
			break;
		}
	}

	return 0;
}