#include <string.h>
#include <stdio.h>
#include "Parser.h"

struct Node
{
	const char value;
	Node* parent = nullptr;
	Node* rightChild = nullptr;
	Node* leftChild = nullptr;
};

struct CountingTree
{
	Node* root = nullptr;
};

CountingTree* createTree()
{
	return new CountingTree;
}

bool isEmpty(CountingTree* tree)
{
	return tree->root == nullptr;
}

bool isFull(Node* node)
{
	return node->leftChild != nullptr && node->rightChild != nullptr;
}

void addNewNode(CountingTree* tree, Node* parent, const char token)
{
	if (isEmpty(tree))
	{
		tree->root = new Node{ token };
	}
	else if (parent->leftChild == nullptr)
	{
		parent->leftChild = new Node{ token, parent };
	}
	else
	{
		parent->rightChild = new Node{ token, parent };
	}
}

Node* moveToChild(Node* parent, const char childToken)
{
	if (parent->leftChild->value == childToken)
	{
		return parent->leftChild;
	}
	if (parent->rightChild->value == childToken)
	{
		return parent->rightChild;
	}
	return parent;
}

bool isOperator(const char token)
{
	return token == '+' || token == '-' || token == '*' || token == '/';
}

bool isNumber(const char token)
{
	return token >= '0' && token <= '9';
}

void buildTree(CountingTree* tree, char* string)
{
	const int length = strlen(string);
	Node* currentNode = nullptr;

	int i = 0;
	while (!isOperator(string[i]))
	{
		if (i >= length)
		{
			return;
		}
		i++;
	}
	addNewNode(tree, currentNode, string[i]);
	i++;
	currentNode = tree->root;

	while (i < length)
	{
		const char token = string[i];
		i++;

		if (!isNumber(token) && !isOperator(token))
		{
			continue;
		}

		addNewNode(tree, currentNode, token);

		if (isOperator(token))
		{
			currentNode = moveToChild(currentNode, token);
		}

		if (isFull(currentNode))
		{
			currentNode = currentNode->parent;
		}
	}
}

int countingSubtree(Node* node)
{
	const char token = node->value;

	if (!isOperator(token))
	{
		return 0;
	}

	int number1 = 0;
	int number2 = 0;
	if (isNumber(node->leftChild->value))
	{
		number1 = node->leftChild->value - 48;
	}
	else
	{
		number1 = countingSubtree(node->leftChild);
	}

	if (isNumber(node->rightChild->value))
	{
		number2 = node->rightChild->value - 48;
	}
	else
	{
		number2 = countingSubtree(node->rightChild);
	}

	if (token == '+')
	{
		return number1 + number2;
	}
	if (token == '-')
	{
		return number1 - number2;
	}
	if (token == '*')
	{
		return number1 * number2;
	}
	if (token == '/')
	{
		return number1 / number2;
	}
}

int counting(CountingTree* tree)
{
	if (isEmpty(tree))
	{
		return 0;
	}
	return countingSubtree(tree->root);
}

void printSubtree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	printf("%c ", node->value);
	printSubtree(node->leftChild);
	printSubtree(node->rightChild);
}

void printTree(CountingTree* tree)
{
	printSubtree(tree->root);
	printf("\n");
}

void deleteSubtree(Node* node)
{
	if (node == nullptr)
	{
		delete node;
		return;
	}
	deleteSubtree(node->leftChild);
	deleteSubtree(node->rightChild);
	delete node;
}

void deleteTree(CountingTree* tree)
{
	deleteSubtree(tree->root);
}




