
#include <stdio.h>

//Функция нахождения чисел Фибоначчи итеративно
int iterativeFib(int n)
{
	int numbersInMemory[3]{};
	numbersInMemory[0] = 1;
	numbersInMemory[1] = 1;
	for (int i = 2, t = 0; i <= n; ++i)
	{
		numbersInMemory[2] = numbersInMemory[0] + numbersInMemory[1];
		numbersInMemory[0] = numbersInMemory[1];
		numbersInMemory[1] = numbersInMemory[2];
	}
	return numbersInMemory[2];
}


//Функция нахождения чисел Фибоначчи рекурсивно
int recFib(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return recFib(n - 1) + recFib(n - 2);
	}
}

/*
Рекурсивный алгоритм нашел 37-е число за несколько секунд, 50-е ищу до сих пор.
Что касается итеративного, 37-е нашлось быстро, а вот 50-е, кажется, вызвало ошибку переполнения.
*/
int main()
{
	printf("Enter the number of the desired number: \n");
	int number = 0;
	scanf("%d", &number);
	printf("Fibonacci number under this number: %d", iterativeFib(number));
	return 0;
}