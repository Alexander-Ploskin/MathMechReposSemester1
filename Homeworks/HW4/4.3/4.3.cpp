#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
#include <locale.h>

struct record
{
	char name[20]{};
	char phoneNumber[10]{};
};

void addRecord(struct record phonebook[100], int numberOfRecord)
{
	printf("Введите имя:\n");
	scanf("%s", &phonebook->name);
	printf("Введите номер:\n");
	scanf("%s", &phonebook);
}

void printPhonebook(struct record phonebook[100], int numberOfRecord)
{
	for (int i = 0; i < numberOfRecord; ++i)
	{
		printf("%d")
	}
}

int searchNumber(struct record phonebook, int numberOfRecord)
{

}

int searchName(struct record phonebook, int numberOfRecord)
{

}

int saveAllRecords()
{

=======
#include <stdlib.h>
#include <locale.h>

struct Record
{
	char name[20]{};
	char phoneNumber[20]{};
};

int readRecordsFromTheFile(Record* phoneBook, char const* fileName)
{
	FILE* filePtr = fopen(fileName, "r");
	int counter = 0;
	if (!filePtr)
	{
		printf("Файл не найден");
	}
	else
	{
		while (fscanf(filePtr, "%s", phoneBook[counter].name) != EOF)
		{
			const int nameLength = strlen(phoneBook[counter].name);
			fscanf(filePtr, "%s", phoneBook[counter].phoneNumber);
			counter++;
		}
	}
	fclose(filePtr);
	return counter;
}

void addRecord(Record* phoneBook, int numberOfRecord)
{
	printf("Введите имя: \n");
	scanf("%s", phoneBook[numberOfRecord].name);
	printf("Введите номер (Пример: 89050493782):\n");
	scanf("%s", phoneBook[numberOfRecord].phoneNumber);
	numberOfRecord++;
}

void printAllRecords(Record* phoneBook, int numberOfRecord)
{
	if (numberOfRecord == 0)
	{
		printf("В книге нет ни одной записи\n");
	}
	else
	{
		for (int i = 0; i < numberOfRecord; ++i)
		{
			printf("%s  %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
		}
	}
}

bool findPhoneNumber(Record* phoneBook, int numberOfRecord, char* usersName)
{
	for (int i = 0; i < numberOfRecord; ++i)
	{
		if (strcmp(usersName, phoneBook[i].name) == 0)
		{
			printf("%s\n", phoneBook[i].phoneNumber);
			return true;
		}
	}
	return false;
}

bool findName(Record* phoneBook, int numberOfRecord, char* usersPhoneNumber)
{
	for (int i = 0; i < numberOfRecord; ++i)
	{
		if (strcmp(usersPhoneNumber, phoneBook[i].phoneNumber) == 0)
		{
			printf("%s\n", phoneBook[i].name);
			return true;
		}
	}
	return false;
}

void saveAllRecords(Record* phoneBook, int numberOfNoSavedRecords)
{
	if (numberOfNoSavedRecords == 0)
	{
		printf("Нет ни одной несохраненной записи\n");
	}
	else
	{
		FILE* filePtr = fopen("phonebook.txt", "w");
		for (int i = 0; i < numberOfNoSavedRecords; ++i)
		{
			fprintf(filePtr, "%s %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
		}
	}
}

bool test()
{
	Record testBook[5];

	int numberOfTestRecords = readRecordsFromTheFile(testBook, "test.txt");
	char realName[] = "Слон";
	printf("%s", realName);
	printf("%s", testBook[0].name);
	if (numberOfTestRecords != 5 || strcmp(testBook[0].name, realName) != 0)
	{
		printf("Ошибка при чтении файла");
		return false;
	}
	return true;
>>>>>>> easy4.1
}

int main()
{
<<<<<<< HEAD
	setlocale(LC_ALL, "Russian");
=======
	system("chcp 1251>nul");

	if (!test())
	{
		return 1;
	}
>>>>>>> easy4.1

	printf("Добро пожаловать в телефонный справочник.\n");
	printf("0 - выйти\n");
	printf("1 - добавить запись (имя и телефон)\n");
	printf("2 - распечатать все имеющиеся записи\n");
	printf("3 - найти телефон по имени\n");
	printf("4 - найти имя по телефону\n");
	printf("5 - сохранить текущие данные в файл\n");

	const int maxNumberOfRecords = 100;
<<<<<<< HEAD
	struct record phoneBook[maxNumberOfRecords];
	int numberOfRecord = 0;
=======
	Record phoneBook[maxNumberOfRecords];
	int numberOfRecords = readRecordsFromTheFile(phoneBook, "phonebook.txt");
>>>>>>> easy4.1

	int choice = -1;
	while (choice != 0)
	{
		printf("Для продолжения работы введите номер команды:\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
<<<<<<< HEAD
			if (numberOfRecord < maxNumberOfRecords)
			{
				addRecord(phoneBook, numberOfRecord);
				numberOfRecord++;
=======
			if (numberOfRecords < maxNumberOfRecords)
			{
				addRecord(phoneBook, numberOfRecords);
				numberOfRecords++;
>>>>>>> easy4.1
			}
			else
			{
				printf("Вы превысили допустимое количество записей!");
			}
<<<<<<< HEAD
			puts(phoneBook[numberOfRecord - 1].name);
			puts(phoneBook[numberOfRecord - 1].phoneNumber);
=======
>>>>>>> easy4.1
			break;
		}
		case 2:
		{
<<<<<<< HEAD
			printPhonebook
=======
			printAllRecords(phoneBook, numberOfRecords);
>>>>>>> easy4.1
			break;
		}
		case 3:
		{
<<<<<<< HEAD
			searchNumber(phoneBook, numberOfRecord);
=======
			printf("Введите имя: \n");
			char usersName[20]{};
			scanf("%s", &usersName);
			if (!findPhoneNumber(phoneBook, numberOfRecords, usersName))
			{
				printf("Номера по такому имени нет в телефонной книге!\n");
			}
>>>>>>> easy4.1
			break;
		}
		case 4:
		{
<<<<<<< HEAD
			searchName
=======
			printf("Введите номер:\n");
			char usersPhoneNumber[20]{};
			scanf("%s", &usersPhoneNumber);
			if (!findName(phoneBook, numberOfRecords, usersPhoneNumber))
			{
				printf("Имени по такому номеру в телефонной книге не найдено!\n");
			}
>>>>>>> easy4.1
			break;
		}
		case 5:
		{
<<<<<<< HEAD
			saveAllRecords
			break;
		}
		default:
			printf("Номер команды - число от 1 до 5!\n");
			break;
=======
			saveAllRecords(phoneBook, numberOfRecords);
			printf("Записи сохранены в файле\n");
			break;
		}
		default:
			if (choice != 0)
			{
				printf("Введите номер существующей команды!");
			}
>>>>>>> easy4.1
		}
	}

	printf("Спасибо за использование телефонного справочника!");
	return 0;
}
