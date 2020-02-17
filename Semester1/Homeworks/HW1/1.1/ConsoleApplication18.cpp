#include <stdio.h>

int main()
{
	int x;
	printf("Enter X from keybord : ");
	scanf_s("%d", &x);
	int SquareOfX = x * x;
	printf("Result of x4+x3+x2+x+1: %d\n", SquareOfX * (SquareOfX + x) + SquareOfX + x + 1);
	return 0;
}