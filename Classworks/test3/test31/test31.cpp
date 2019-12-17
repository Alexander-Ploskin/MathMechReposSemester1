#include <stdio.h>
#include "list.h"

int main()
{
	List* list = createList();
	int buffer = -1;
	while (buffer != 0)
	{
		scanf("%d", &buffer);
		if (!isContains(list, buffer))
		{
			push(list, buffer);
		}
	}
	printList(list);
	deleteList(list);
	return 0;
}