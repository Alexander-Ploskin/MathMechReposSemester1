#include <string.h>
#include "set.h"

struct SetElement
{
	SetElement* rightChild;
	SetElement* leftChild;
	int key;
	char* string;
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

SetElement* searchElement(Set* set, int key)
{
	SetElement* currentElement = set->root;
	while (currentElement != nullptr)
	{
		if (currentElement->key == key)
		{
			return currentElement;
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
	return nullptr;
}

SetElement* searchOfParentOfElement(Set* set, int key)
{
	SetElement* currentElement = set->root;
	SetElement* parent = nullptr;
	while (currentElement != nullptr)
	{
		if (currentElement->key == key)
		{
			return parent;
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

bool isLeaf(SetElement* element)
{
	return element->rightChild == nullptr || element->leftChild == nullptr;
}

bool add(Set* set, int key, char* string)
{
	if (contains(set, key))
	{
		searchElement(set, key)->string = string;
		return false;
	}

	if (isEmpty(set))
	{
		set->root = new SetElement{ nullptr, nullptr, key, string };
		return true;
	}

	SetElement* currentElement = set->root;
	while (!isLeaf(currentElement))
	{
		if (currentElement->key < key)
		{
			if (currentElement->rightChild == nullptr)
			{
				currentElement->rightChild = new SetElement{ nullptr,nullptr,key,string };
				return true;
			}
			currentElement = currentElement->rightChild;
		}
		else
		{
			if (currentElement->leftChild == nullptr)
			{
				currentElement->leftChild = new SetElement{ nullptr,nullptr,key,string };
				return true;
			}
			currentElement = currentElement->leftChild;
		}
	}
	
	if (currentElement->key < key)
	{
		currentElement->rightChild = new SetElement{ nullptr,nullptr,key,string };
	}
	else
	{
		currentElement->leftChild = new SetElement{ nullptr,nullptr,key,string };
	}
	return true;
}

SetElement* searchOfNewElement(SetElement* element, SetElement*& parent)
{
	SetElement* currentElement = element->rightChild;
	while (currentElement->leftChild != nullptr)
	{
		parent = currentElement;
		currentElement = currentElement->leftChild;
	}
	return currentElement;
}

bool remove(Set* set, int key)
{
	if (isEmpty(set) || !contains(set, key))
	{
		return false;
	}
	SetElement* element = searchElement(set, key);
	if (element->rightChild != nullptr && element->leftChild != nullptr)
	{
		SetElement* parent = nullptr;
		SetElement* newElement = searchOfNewElement(element, parent);
		element->key = newElement->key;
		element->string = newElement->string;
		if (parent->rightChild == newElement)
		{
			parent->rightChild = nullptr;
		}
		else
		{
			parent->leftChild = nullptr;
		}
		delete newElement;
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
		else
		{
			SetElement* parent = searchOfParentOfElement(set, key);
			if (parent->rightChild == element)
			{
				parent->rightChild = element->rightChild;
			}
			else
			{
				parent->leftChild = element->rightChild;
			}
			delete element;
			return true;
		}
	}
	else if (element->leftChild != nullptr)
	{
		if (set->root == element)
		{
			set->root = element->leftChild;
			delete element;
			return true;
		}
		else
		{
			SetElement* parent = searchOfParentOfElement(set, key);
			if (parent->rightChild == element)
			{
				parent->rightChild = element->leftChild;
			}
			else
			{
				parent->leftChild = element->leftChild;
			}
			delete element;
			return true;
		}
	}
	else
	{
		SetElement* parent = searchOfParentOfElement(set, key);
		if (parent->rightChild == element)
		{
			parent->rightChild = nullptr;
		}
		else
		{
			parent->leftChild = nullptr;
		}
		delete element;
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

void splay(Set* set)
{

}

