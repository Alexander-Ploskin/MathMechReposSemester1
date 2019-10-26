#include <stdio.h>

int main()

{
	int sums[28]{};
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9;j++)
			for (int k = 0; k <= 9; k++)
				sums[i + j + k]++;
	int result = 0;
	for (int i = 0; i <= 27; i++)
		result = result + sums[i] * sums[i];
	printf("There are %d lucky tickets", result);
	return 0;
}