#include "set.h"
#include <string.h>

struct SetElement
{
	SetElement* rightChild = nullptr;
	SetElement* leftChild = nullptr;
	SetElement* parent = nullptr;
	int key = 0;
	char string[maxLength]{};
	int balance = 0;
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

void simpleLeftRotation(SetElement* grandParent, SetElement* parent, SetElement* element)
{
	parent->rightChild = element->leftChild;
	parent->rightChild->parent = parent;
	parent->parent = element;
	if (grandParent != nullptr)
	{
		setChild(grandParent, parent, element);
	}
	element->parent = grandParent;
}

void simpleRightRotation(SetElement* grandParent, SetElement* parent, SetElement* element)
{
	parent->leftChild = element->rightChild;
	parent->leftChild->parent = parent;
	parent->parent = element;
	if (grandParent != nullptr)
	{
		setChild(grandParent, parent, element);
	}
	element->parent = grandParent;
}

void doubleLeftRotation(SetElement* grandParent, SetElement* parent, SetElement* element)
{
	parent->leftChild = element->rightChild;
	parent->leftChild->parent = parent;
	element->rightChild = parent;
	parent->parent = element;

	grandParent->rightChild = element->leftChild;
	grandParent->rightChild->parent = grandParent;
	element->leftChild = grandParent;
	grandParent->parent = element;

	if (grandParent->parent != nullptr)
	{
		setChild(grandParent->parent, grandParent, element);
	}
	element->parent = grandParent->parent;
}

void doubleRightRotation(SetElement* grandParent, SetElement* parent, SetElement* element)
{
	parent->rightChild = element->leftChild;
	parent->rightChild->parent = parent;
	element->leftChild = parent;
	parent->parent = element;

	grandParent->leftChild = element->rightChild;
	grandParent->leftChild->parent = grandParent;
	element->rightChild = grandParent;
	grandParent->parent = element;

	if (grandParent->parent != nullptr)
	{
		setChild(grandParent->parent, grandParent, element);
	}
	element->parent = grandParent->parent;
}

void rotation(SetElement* element, SetElement* child, SetElement* grandChild)
{
	if (element->balance == -2)
	{
		if (child->balance == 1)
		{
			doubleLeftRotation(element, child, grandChild);
			if (grandChild->balance == 1)
			{
				element->balance = 0;
				child->balance = -1;
				grandChild->balance = 0;
			}
			else if (grandChild->balance == 0)
			{
				element->balance = 1;
				child->balance = 0;
				grandChild->balance = 0;
			}
			else
			{
				element->balance = 0;
				child->balance = 0;
				grandChild->balance = 0;
			}
			return;
		}
		simpleLeftRotation(element->parent, element, child);
		if (child->balance == 0)
		{
			element->balance = 0;
			child->balance = 0;
		}
		else
		{
			element->balance = -1;
			child->balance = 1;
		}
		return;
	}

	if (child->balance == -1)
	{
		doubleRightRotation(element, child, grandChild);
		if (grandChild->balance == 1)
		{
			element->balance = 0;
			child->balance = 1;
			grandChild->balance = 0;
		}
		else if (grandChild->balance == 0)
		{
			element->balance = -1;
			child->balance = 0;
			grandChild->balance = 0;
		}
		else
		{
			element->balance = 0;
			child->balance = 0;
			grandChild->balance = 0;
		}
		return;
	}
	simpleRightRotation(element->parent, element, child);
	if (child->balance == 0)
	{
		element->balance = 0;
		child->balance = 0;
	}
	else
	{
		element->balance = 1;
		child->balance = -1;
	}
}

void balance(SetElement* element, bool add)
{
	SetElement* currentGrandchild = nullptr;
	SetElement* currentChild = element;
	SetElement* currentParent = element->parent;

	while (currentParent != nullptr)
	{
		if (currentParent->leftChild == currentChild)
		{
			if (add)
			{
				currentParent->balance++;
			}
			else
			{
				currentParent->balance--;
			}
		}
		else
		{
			if (add)
			{
				currentParent->balance--;
			}
			else
			{
				currentParent->balance++;
			}
		}

		if (currentParent->balance == 0)
		{
			return;
		}
		else if (currentParent->balance == 1 || currentParent->balance == -1)
		{
			currentGrandchild = currentChild;
			currentChild = currentParent;
			currentParent = currentParent->parent;
		}
		else
		{
			rotation(currentParent, currentChild, currentGrandchild);
		}
	}
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
		set->root = new SetElement{ nullptr, nullptr, nullptr, key };
		strcpy(set->root->string, inputString);
		return true;
	}

	SetElement* currentElement = set->root;
	while (true)
	{
		if (currentElement->key < key)
		{
			if (currentElement->rightChild == nullptr)
			{
				currentElement->rightChild = new SetElement{ nullptr, nullptr, currentElement, key };
				strcpy(currentElement->rightChild->string, inputString);
				balance(currentElement->rightChild, true);
				return true;
			}
			currentElement = currentElement->rightChild;
		}
		else
		{
			if (currentElement->leftChild == nullptr)
			{
				currentElement->leftChild = new SetElement{ nullptr, nullptr, currentElement, key };
				strcpy(currentElement->leftChild->string, inputString);
				balance(currentElement->leftChild, true);
				return true;
			}
			currentElement = currentElement->leftChild;
		}
	}
}

SetElement* searchOfNewElement(SetElement* element, SetElement*& parent)
{
	SetElement* currentElement = element->leftChild;
	while (currentElement->rightChild != nullptr)
	{
		parent = currentElement;
		currentElement = currentElement->rightChild;
	}
	return currentElement;
}

bool remove(Set* set, int key)
{
	if (isEmpty(set) || !contains(set, key))
	{
		return false;
	}
	SetElement* parent = nullptr;
	SetElement* element = searchElement(set, key, parent);
	if (element->leftChild != nullptr && element->rightChild != nullptr)
	{
		SetElement* parentOfNewElement = element;
		SetElement* newElement = searchOfNewElement(element, parentOfNewElement);
		element->key = newElement->key;
		strcpy(element->string, newElement->string);
		setChild(parentOfNewElement, newElement, nullptr);
		balance(newElement, false);
		delete newElement;
		return true;
	}
	if (element->leftChild != nullptr)
	{
		if (element == set->root)
		{
			set->root = element->leftChild;
			delete element;
			return true;
		}
		setChild(parent, element, element->leftChild);
		balance(element, false);
		delete element;
		return true;
	}
	if (element->rightChild != nullptr)
	{
		if (element == set->root)
		{
			set->root = element->rightChild;
			delete element;
			return true;
		}
		setChild(parent, element, element->rightChild);
		balance(element, false);
		delete element;
		return true;
	}
	if (element == set->root)
	{
		set->root = nullptr;
		delete element;
		return true;
	}
	setChild(parent, element, nullptr);
	balance(element, false);
	delete element;
	return true;
}

bool setNewValue(Set* set, int key, char* string)
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


