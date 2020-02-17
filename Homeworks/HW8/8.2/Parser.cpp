#include <string.h>
#include <stdio.h>
#include "Parser.h"

struct TreeElement
{
	const char value;
	TreeElement* leftChild = nullptr;
	TreeElement* rightChild = nullptr;
	TreeElement* parent = nullptr;
};

struct Parser
{
	TreeElement* root = nullptr;
};

Parser* createParser()
{
	return new Parser;
}

void deleteParser(Parser* parser)
{
	delete parser->root;
	delete parser;
}

bool isEmpty(Parser* parser)
{
	return parser->root == nullptr;
}

bool isOperator(const char token)
{
	return token == '+' || token == '-' || token == '*' || token == '/';
}

bool ignoreToken(const char token)
{
	return token == '(' || token == ' ' || token == ')';
}

TreeElement* add(TreeElement* currentElement, const char token)
{
	if (ignoreToken(token))
	{
		return currentElement;
	}
	if (currentElement->leftChild == nullptr)
	{
		currentElement->leftChild = new TreeElement{ token, nullptr, nullptr, currentElement };
		if (isOperator(token))
		{
			return currentElement->leftChild;
		}
	}
	else if (currentElement->rightChild == nullptr)
	{
		currentElement->rightChild = new TreeElement{ token, nullptr, nullptr, currentElement };
		if (isOperator(token))
		{
			return currentElement->rightChild;
		}
	}
	else
	{
		add(currentElement->parent, token);
	}
}

void initializationOfTheTree(Parser* parser, char* input)
{
	parser->root = new TreeElement{ input[0] };
	TreeElement* currentElement = parser->root;

	const int lengthOfString = strlen(input);
	for (int i = 1; i < lengthOfString; ++i)
	{
		const char token = input[i];
		add(currentElement, input[i]);
	}
}

void printTree(TreeElement* element)
{
	printf("%c ", element->value);
	if (element->leftChild != nullptr)
	{
		printTree(element->leftChild);
	}
	if (element->rightChild != nullptr)
	{
		printTree(element->rightChild);
	}
}

int counting(char* input)
{
	Parser* parser = createParser();

	initializationOfTheTree(parser, input);

	printTree(parser->root);

	return 0;
}





