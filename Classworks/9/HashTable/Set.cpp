#include "Set.h"
#include "Backet.h"

struct BacketElement
{
	char value[maxSize]{};
};

struct Backet
{
	BacketElement* head = nullptr;
};

struct Set
{
	Backet* array[hashSize]{};
};

int hashFunction(char* string)
{
	int i = 0;
	int result = 0;
	while (i < maxSize)
	{
		result = ((result + string[i]) + hashSize) % hashSize;
		++i;
	}
	return result;
}

Set* createSet()
{
	Set* set =  new Set;
	for (int i = 0; i < hashSize; ++i)
	{
		set->array[i] = nullptr;
	}
	return set;
}

void add(Set* set, char* string)
{
	const int hash = hashFunction(string);
	set->array[hash] = createBacket();
	addToBacket(set->array[hash], string);
}

bool contains(Set* set, char* string)
{
	const int hash = hashFunction(string);
	if (set->array[hash] == nullptr)
	{
		return false;
	}
	return containsInBacket(string, set->array[hash]);
}

bool deleteElement(Set* set, char* string)
{
	if (!contains(set, string))
	{
		return false;
	}
	deleteElementFromBacket(string, set->array[hashFunction(string)]);
	return false;
}

void deleteSet(Set* set)
{
	for (int i = 0; i < hashSize; ++i)
	{
		deleteBacket(set->array[i]);
	}
	delete set;
}













