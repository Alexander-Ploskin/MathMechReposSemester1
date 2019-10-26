#include <locale.h>
#include <stdio.h>
#include "list.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	List* list = createList();

	printf("Введите положительное количество воинов\n");
	int n = 0;
	scanf("%d", &n);

	printf("Введите период считалки\n");
	int m = 0;
	scanf("%d", &m);

	for (int i = 1; i <= n; i++)
	{
		push(list, i);
	}
	printList(list);

	printf("Выживет воин под номером %d\n", counting(list, m));

}