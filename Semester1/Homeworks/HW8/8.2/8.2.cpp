#include <stdio.h>
#include <string.h>
#include "Parser.h"

bool test()
{
	char test1String[] = "(* (+ 1 1) 2)";
	CountingTree* test1Tree = createTree();
	buildTree(test1Tree, test1String);
	bool test1 = counting(test1Tree) == 4;
	deleteTree(test1Tree);

	char test2String[] = "* + 5 7 - 6 3";
	CountingTree* test2Tree = createTree();
	buildTree(test2Tree, test2String);
	bool test2 = counting(test2Tree) == 36;
	deleteTree(test2Tree);

	char test3String[] = " ";
	CountingTree* test3Tree = createTree();
	buildTree(test3Tree, test3String);
	bool test3 = counting(test3Tree) == 0;
	deleteTree(test3Tree);

	char test4String[] = "/ 1 2";
	CountingTree* test4Tree = createTree();
	buildTree(test4Tree, test4String);
	bool test4 = counting(test4Tree) == 0;
	deleteTree(test4Tree);

	char test5String[] = "1";
	CountingTree* test5Tree = createTree();
	buildTree(test5Tree, test5String);
	bool test5 = counting(test5Tree) == 1;
	deleteTree(test5Tree);

	return test1 && test2 && test3 && test4;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	FILE* filePtr = fopen("input.txt", "r");

	char inputString[100]{};
	fscanf(filePtr, "%[^\n]%*c", inputString);

	fclose(filePtr);

	CountingTree* tree = createTree();

	buildTree(tree, inputString);

	printTree(tree);

	printf("%d\n", counting(tree));

	deleteTree(tree);

	return 0;
}