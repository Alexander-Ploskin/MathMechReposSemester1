#include "Stack.h"
#include "set.h"

struct StackElement
{
	SetElement* value;
	StackElement* next = nullptr;
};

struct Stack
{
	StackElement* head = nullptr;
};

Stack* createStack()
{
	return new Stack;
}

void push(Stack* stack, SetElement*& value)
{
	stack->head = new StackElement{ value, stack->head };
}

SetElement* pop(Stack* stack)
{
	if (stack->head == nullptr)
	{
		return 0;
	}
	SetElement* result = stack->head->value;
	StackElement* help = stack->head;
	stack->head = stack->head->next;
	delete stack->head;
}

void deleteStack(Stack* stack)
{
	while (stack->head != nullptr)
	{
		pop(stack);
	}
}