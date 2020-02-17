#include <string.h>
#include "Backet.h"

const int maxSize = 100;

struct BacketElement
{
	char value[maxSize]{};
	BacketElement* next;
};

struct Backet
{
	BacketElement* head = nullptr;
};

Backet* createBacket()
{
	return new Backet;
}

void addToBacket(Backet* backet, char* input)
{
	BacketElement* currentElement = backet->head;

	if (currentElement == nullptr)
	{
		backet->head = new BacketElement;
		strcpy(backet->head->value, input);
		return;
	}

	while (currentElement->next != nullptr)
	{
		currentElement = currentElement->next;
	}
	currentElement->next = new BacketElement;
	strcpy(currentElement->next->value, input);
}

bool deleteElementFromBacket(char* string, Backet* backet)
{
	if (!containsInBacket(string, backet))
	{
		return false;
	}

	BacketElement* currentElement = backet->head;
	if (strcmp(string, currentElement->value))
	{
		backet->head = currentElement->next;
		delete currentElement;
		return true;
	}

	while (strcmp(currentElement->next->value, string) != 0)
	{
		currentElement = currentElement->next;
	}

	BacketElement* help = currentElement->next;
	currentElement->next = help->next;
	delete help;
	return true;
}

void deleteBacket(Backet* backet)
{
	while (backet->head != nullptr)
	{
		BacketElement* help = backet->head;
		backet->head = backet->head->next;
		delete help;
	}
}

bool containsInBacket(char* string, Backet* backet)
{
	if (backet->head == nullptr)
	{
		return false;
	}

	BacketElement* currentElement = backet->head;
	while (currentElement != nullptr)
	{
		if (strcmp(currentElement->value, string) == 0)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
	return false;
}











