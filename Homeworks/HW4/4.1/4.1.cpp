#include <stdio.h>
#include <locale.h>

const int sizeOfNumber = sizeof(int)*8;  //могут храниться числа типа longint

void printNumber(int* array)
{
	int i = 0;
	while (array[i] == 0 && i < sizeOfNumber)
	{
		++i;
	}
	for (; i < sizeOfNumber; ++i)
	{
		printf("%d", array[i]);
	}
}

void addition(int* binaryArray1, int* binaryArray2, int* binarySum)
{
	int overflow = 0;
	for (int i = sizeOfNumber - 1; i >= 0; --i)
	{
		binarySum[i] = (binaryArray1[i] + binaryArray2[i] + overflow) % 2;
		overflow = (binaryArray1[i] + binaryArray2[i] + overflow) / 2;
	}
}

void binaryConversion(int* binaryArray, int number)
{
	int mask = 1;
	for (int i = sizeOfNumber - 1; i >= 0; --i)
	{
		if (number & mask)
		{
			binaryArray[i] = 1;
		}
		else
		{
			binaryArray[i] = 0;
		}

		mask = mask << 1;
	}

}

int decimalConversion(int* binaryArray)
{
	int counter = 0;
	int two = 1;
	for (int i = sizeOfNumber - 1; i >= 0; --i)
	{
		counter += two * binaryArray[i];
		two *= 2;
	}

	return counter;
}

bool testOfBinaryConversion(int number)
{
	int* binaryArray = new int[sizeOfNumber] {};
	binaryConversion(binaryArray, number);
	if (decimalConversion(binaryArray) != number)
	{
		printf("Ошибка при переводе в двоичное представление!\n");
		delete[] binaryArray;
		return false;
	}
	delete[] binaryArray;
	return true;
}

bool testOfDecimalConversion(int* binaryArray, int number)   
{
	if (decimalConversion(binaryArray) != number)
	{
		return false;
	}
	return true;
}

bool testOfAddition(int* binaryArray1, int* binaryArray2, int realSum)
{
	int* binarySum = new int[sizeOfNumber] {};
	addition(binaryArray1, binaryArray2, binarySum);
	if (decimalConversion(binarySum) != realSum)
	{
		printf("Ошибка при сложении двоичных чисел\n");
		delete[] binarySum;
		return false;
	}
	delete[] binarySum;
	return true;
}

bool test()
{
	int testNumber1 = -100;
	int testNumber2 = 0;
	int testNumber3 = 10000;

	int* realBinaryArray1 = new int[sizeOfNumber] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0};
	int* realBinaryArray2 = new int[sizeOfNumber] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int* realBinaryArray3 = new int[sizeOfNumber] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0};

	if (!testOfDecimalConversion(realBinaryArray1, testNumber1) || !testOfDecimalConversion(realBinaryArray2, testNumber2) || !testOfDecimalConversion(realBinaryArray3, testNumber3))
	{
		printf("Ошибка при переводе в десятичное представление\n");
		delete[] realBinaryArray1;
		delete[] realBinaryArray2;
		delete[] realBinaryArray3;
		return false;
	}

	if (!testOfBinaryConversion(testNumber1) || !testOfBinaryConversion(testNumber2) || !testOfBinaryConversion(testNumber3))
	{
		printf("Ошибка при переводе в двоичное представление\n");
		delete[] realBinaryArray1;
		delete[] realBinaryArray2;
		delete[] realBinaryArray3;
		return false;
	}

	if (!testOfAddition(realBinaryArray2, realBinaryArray1, -100) || !testOfAddition(realBinaryArray3, realBinaryArray1, 9900))
	{
		printf("Ошибка при сложении двоичных чисел\n");
		delete[] realBinaryArray1;
		delete[] realBinaryArray2;
		delete[] realBinaryArray3;
		return false;
	}

	delete[] realBinaryArray1;
	delete[] realBinaryArray2;
	delete[] realBinaryArray3;

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	if (!test())
	{
		return -1;
	}

	int number1 = 0;
	printf("Введите первое число: \n");
	scanf("%d", &number1);

	int number2 = 0;
	printf("Введите второе число: \n");
	scanf("%d", &number2);

	int* binaryArray1 = new int[sizeOfNumber]{};
	int* binaryArray2 = new int[sizeOfNumber]{};

	binaryConversion(binaryArray1, number1);
	binaryConversion(binaryArray2, number2);

	printf("Первое число: ");
	printNumber(binaryArray1);

	printf("\nВторое число: ");
	printNumber(binaryArray2);

	int* binarySum = new int[sizeOfNumber];
	addition(binaryArray1, binaryArray2, binarySum);
	printf("\nСумма двух чисел в двоичном виде: ");
	printNumber(binarySum);

	delete[] binaryArray1;
	delete[] binaryArray2;

	printf("\nСумма двух чисел в десятичном виде: %d", decimalConversion(binarySum));
	delete[] binarySum;

	return 0;
}










