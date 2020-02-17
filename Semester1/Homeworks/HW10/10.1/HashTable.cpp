#include <stdio.h>
#include "HashTable.h"
#include "List.h"

struct HashTable
{
	int hashSize;
	float loadFactor;
	List** hashArray = new List*[hashSize];
};

HashTable* createTable()
{
	HashTable* newTable = new HashTable{ 20, 0.0 };
	for (int i = 0; i < newTable->hashSize; ++i)
	{
		newTable->hashArray[i] = createList();
	}
	return newTable;
}

void deleteTable(HashTable* table)
{
	for (int i = 0; i < table->hashSize; ++i)
	{
		deleteList(table->hashArray[i]);
	}
	delete table;
}

int hashFunction(HashTable* table, char* string)
{
	int result = 0;
	for (int i = 0; i < maxLength; ++i)
	{
		result = ((result + string[i]) + table->hashSize) % table->hashSize;
	}
	return result;
}

HashTable* resize(HashTable* table)
{
	HashTable* newTable = new HashTable{ table->hashSize * 2, 0.0 };
	delete newTable->hashArray;
	newTable->hashArray = new List * [newTable->hashSize];
	for (int i = 0; i < newTable->hashSize; ++i)
	{
		newTable->hashArray[i] = createList();
	}

	for (int i = 0; i < table->hashSize; ++i)
	{
		while (!isEmpty(table->hashArray[i]))
		{
			char buffer[maxLength]{};
			int amount = pop(table->hashArray[i], buffer);
			newTable = addToTable(newTable, buffer, amount);
		}
	}
	deleteTable(table);
	return newTable;
}

HashTable* addToTable(HashTable* table, char* value, int amount)
{
	if (!containsInTable(table, value))
	{
		table->loadFactor += 1.0 / table->hashSize;
	}
	addToList(table->hashArray[hashFunction(table, value)], value, amount);
	if (table->loadFactor > 0.7)
	{
		return resize(table);
	}
	return table;
}

bool containsInTable(HashTable* table, char* value)
{
	return contains(table->hashArray[hashFunction(table, value)], value);
}

void removeFromeTable(HashTable* table, char* value)
{
	if (!containsInTable(table, value))
	{
		return;
	}
	removeFromList(table->hashArray[hashFunction(table, value)], value);
}

void printTable(HashTable* table)
{
	for (int i = 0; i < table->hashSize; ++i)
	{
		printList(table->hashArray[i]);
	}
	float sumOfListLengths = 0.0;
	int maxLengthOfList = 0;
	int counterOfNotEmptyLists = 0;
	for (int i = 0; i < table->hashSize; ++i)
	{
		const int length = lengthOfList(table->hashArray[i]);
		if (length > maxLengthOfList)
		{
			maxLengthOfList = length;
		}
		sumOfListLengths += length;
		if (length != 0)
		{
			counterOfNotEmptyLists++;
		}
	}

	printf("Load factor = %f\n", table->loadFactor);
	printf("Maximum length of list = %d\n", maxLengthOfList);
	printf("Medium length of list = %f\n", sumOfListLengths / counterOfNotEmptyLists);
}




