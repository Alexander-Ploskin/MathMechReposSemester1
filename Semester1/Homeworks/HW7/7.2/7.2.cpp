#include <locale.h>
#include <stdio.h>
#include "list.h"

bool test()
{
	bool test1 = counting(5, 8, false) == 5;
	
	bool test2 = counting(10, 1, false) == 1;

	bool test3 = counting(100, 100, false) == 78;

	return test1 && test2 && test3;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	setlocale(LC_ALL, "Russian");


	printf("Введите количество воинов (натуральное число):\n");
	int n = 0;
	scanf("%d", &n);

	printf("Введите период считалки(натуральное число):\n");
	int m = 0;
	scanf("%d", &m);

	printf("Выживет воин под номером %d\n", counting(m, n, true));

}