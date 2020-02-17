#include <stdio.h>
#include "Set.h"


int main()
{
	Set* set = createSet();

	char string1[maxSize] = "Александр10";
	char string2[maxSize] = "Александр01";
	char string3[maxSize] = "НеАлександр";
	char string4[maxSize] = "Еще один не александр";
	char string5[maxSize] = "Александр";

	add(set, string1);
	add(set, string2);
	add(set, string4);
	add(set, string5);

	if (contains(set, string1))
	{
		printf("1");
	}
	if (!contains(set, string3))
	{
		printf("1");
	}
	if (contains(set, string2))
	{
		printf("1");
	}
	deleteSet(set);

	return 0;
}