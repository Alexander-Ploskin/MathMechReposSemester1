#include <stdio.h>
#include "List.h"

int main()
{
	FILE* inputFilePtr = fopen("input.txt", "r");
	List* list = createList();

	char buffer[maxLength]{};
	while (!feof(inputFilePtr))
	{
		fgets(buffer, maxLength, inputFilePtr);
		if (!contains(list, buffer))
		{
			add(list, buffer);
		}
	}

	fclose(inputFilePtr);

	FILE* outputFilePtr = fopen("output.txt", "w");
	printListToFile(list, outputFilePtr);
	fclose(outputFilePtr);

	deleteList(list);

	return 0;
}