#include "stack.h"

void push(char value, OpenBracket** head)
{
	OpenBracket* newBracket = new OpenBracket{ value, *head };
	*head = newBracket;
}

const char pop(OpenBracket** head)
{
	char headValue = (*head)->bracket;
	OpenBracket* newHead = (*head)->next;
	delete* head;
	*head = newHead;
	return headValue;
}

void deleteStackElement(OpenBracket** head)
{
	OpenBracket* help = (*head)->next;
	delete* head;
	*head = help;
}

bool isEmpty(OpenBracket* head)
{
	return head == nullptr;
}