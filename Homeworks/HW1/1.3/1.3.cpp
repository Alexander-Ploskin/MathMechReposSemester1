#include <iostream>

int main()
{
	int array[10]{ 1,2,3,4,5,6,7,8,9,10 };
	printf("Enter the border: \n");
	int border;
	scanf_s("%d", &border);
	for (int i = 0; i <= border / 2; i++)
	{
		int t;
		t = array[i];
		array[i] = array[border - i];
		array[border - i] = t;
	}
	for (int i = border + 1; i <= (border + 1 + 9) / 2; i++)
	{
		int p;
		p = array[i];
		array[i] = array[10 - i + border];
		array[10 - i + border] = p;
	}
	for (int i = 0; i <= 4; i++)
	{
		int q;
		q = array[i];
		array[i] = array[9 - i];
		array[9 - i] = q;
	}
	printf("New array: \n");
	for (int s = 0; s <= 9; s++)
		printf(" %d ", array[s]);
	return 0;
}