#include <string.h>
#include "set.h"

struct SetElement
{
	SetElement* rightChild = nullptr;
	SetElement* leftChild = nullptr;
	int key = 0;
	char string[maxLength]{};
};

struct Set
{
	SetElement* root = nullptr;
};

bool isEmpty(Set* set)
{
	return set->root == nullptr;
}

bool contains(Set* set, int key)
{
	if (isEmpty(set))
	{
		return false;
	}
	SetElement* currentElement = set->root;
	while (currentElement != nullptr)
	{
		if (currentElement->key == key)
		{
			return true;
		}
		else if (currentElement->key < key)
		{
			currentElement = currentElement->rightChild;
		}
		else
		{
			currentElement = currentElement->leftChild;
		}
	}
	return false;
}

Set* createSet()
{
	return new Set;
}

SetElement* searchElement(Set* set, int key, SetElement*& parent)
{
	SetElement* currentElement = set->root;
	if (currentElement->key == key)
	{
		return currentElement;
	}
	while (currentElement != nullptr)
	{
		if (currentElement->key == key)
		{
			return currentElement;
		}
		else if (currentElement->key < key)
		{
			parent = currentElement;
			currentElement = currentElement->rightChild;
		}
		else
		{
			parent = currentElement;
			currentElement = currentElement->leftChild;
		}
	}
	return nullptr;
}

void getValue(Set* set, int key, char* bufferString)
{
	SetElement* parent = nullptr;
	strcpy(bufferString, searchElement(set, key, parent)->string);
}

bool add(Set* set, int key, char* inputString)
{
	if (contains(set, key))
	{
		SetElement* parent = nullptr;
		strcpy(searchElement(set, key, parent)->string, inputString);
		return false;
	}

	if (isEmpty(set))
	{
		set->root = new SetElement{ nullptr, nullptr, key };
		strcpy(set->root->string, inputString);
		return true;
	}

	SetElement* currentElement = set->root;
	while (true)
	{
		if (key > currentElement->key)
		{
			if (currentElement->rightChild == nullptr)
			{
				currentElement->rightChild = new SetElement{ nullptr, nullptr, key };
				strcpy(currentElement->rightChild->string, inputString);
				return true;
			}
			currentElement = currentElement->rightChild;
		}
		else
		{
			if (currentElement->leftChild == nullptr)
			{
				currentElement->leftChild = new SetElement{ nullptr, nullptr, key };
				strcpy(currentElement->leftChild->string, inputString);
				return true;
			}
			currentElement = currentElement->leftChild;
		}
	}
	return false;
}

SetElement* searchOfNewElement(SetElement* element)
{
	SetElement* currentElement = element->rightChild;
	while (currentElement->leftChild != nullptr)
	{
		currentElement = currentElement->leftChild;
	}
	return currentElement;
}

void setChild(SetElement* parent, SetElement* currentChild, SetElement* newChild)
{
	if (parent->leftChild == currentChild)
	{
		parent->leftChild = newChild;
	}
	else
	{
		parent->rightChild = newChild;
	}
}

bool remove(Set* set, int key)
{
	if (isEmpty(set) || !contains(set, key))
	{
		return false;
	}
	SetElement* parent = nullptr;
	SetElement* element = searchElement(set, key, parent);
	if (element->rightChild != nullptr && element->leftChild != nullptr)
	{
		if (element == set->root)
		{
			set->root = searchOfNewElement(element);
			delete element;
			return true;
		}
		SetElement* newElement = searchOfNewElement(element);
		setChild(parent, element, newElement);
		delete element;
		return true;
	}
	else if (element->rightChild != nullptr)
	{
		if (set->root == element)
		{
			set->root = element->rightChild;
			delete element;
			return true;
		}
		setChild(parent, element, element->rightChild);
		delete element;
		return true;
	}
	else if (element->leftChild != nullptr)
	{
		if (set->root == element)
		{
			set->root = element->leftChild;
			delete element;
			return true;
		}
		setChild(parent, element, element->leftChild);
		delete element;
		return true;
	}
	else
	{
		if (set->root == element)
		{
			delete element;
			set->root = nullptr;
			return true;
		}
		setChild(parent, element, nullptr);
		delete element;
		return true;
	}
}

bool substitute(Set* set, int key, char* string)
{
	if (!contains(set, key))
	{
		return false;
	}
	else
	{
		SetElement* parent = nullptr;
		SetElement* element = searchElement(set, key, parent);
		strcpy(element->string, string);
		return true;
	}
}

bool deleteSet(Set* set)
{
	while (!isEmpty(set))
	{
		remove(set, set->root->key);
	}
	delete set;
	return true;
}













