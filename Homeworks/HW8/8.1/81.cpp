#include <stdio.h>
#include "set.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
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
			char* string = nullptr;
			scanf("%s", &string);
			if (contains(set, key))
			{
				substitute(set, key, string);
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
			printf("%s\n", getValue(set, key));
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
		}
		case 0:
		{
		
			break;
		}
		default:
			printf("Введите номер существующей команды\n");
			break;
		}
	}

	char string[] = { "Пиво" };
	add(set, 13, string);

	return 0;
}








