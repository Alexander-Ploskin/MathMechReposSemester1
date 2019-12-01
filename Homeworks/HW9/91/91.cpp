#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "set.h"

bool test()
{
	Set* set = createSet();

	char string1[maxLength]{ "1" };
	int key1 = 50;
	add(set, key1, string1);
	char string2[maxLength]{ "2" };
	int key2 = 25;
	add(set, key2, string2);
	char string3[maxLength]{ "3" };
	int key3 = 75;
	add(set, key3, string3);
	char string4[maxLength]{ "4" };
	int key4 = 60;
	add(set, key4, string4);
	char string5[maxLength]{ "5" };
	int key5 = 90;
	add(set, key5, string5);

	bool test1 = contains(set, 75);
	bool test2 = contains(set, 50);
	bool test3 = !contains(set, 10);

	char bufferString1[maxLength]{};
	getValue(set, 60, bufferString1);
	bool test4 = strcmp(bufferString1, string4) == 0;

	remove(set, 90);
	remove(set, 50);

	bool test5 = !contains(set, 90);
	bool test6 = !contains(set, 50);

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
			scanf("%s", &string);
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
