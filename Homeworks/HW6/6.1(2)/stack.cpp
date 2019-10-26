#include "stack.h"

struct StackElement
{
	int value;
	StackElement* next;
};

struct  Stack
{
	StackElement* head = nullptr;
};

void push(int value, Stack* stack)
{
	stack->head = new StackElement{ value, stack->head };
}

int pop(Stack* stack)
{
	int headValue = stack->head->value;
	StackElement* help = stack->head->next;
	delete stack->head;
	stack->head = help;
	return headValue;
}

bool isEmpty(Stack* stack)
{
	return stack->head == nullptr;
}

void deleteStack(Stack* stack)
{
	while (!isEmpty(stack))
	{
		pop(stack);
	}
	delete stack;
}

Stack* createStack()
{
	return new Stack;
}

int checkHead(Stack* stack)
{
	return stack->head->value;
}
