#pragma once
#include <stdio.h>

//Максимальная длина строк
const int maxLength = 100;

//Тип данных значений внутри списка
typedef char* Type;

//Тип данных список
struct List;

//Создает список
List* createList();

//Удаляет список
void deleteList(List* list);

//Добавляет в список новое значение
void add(List* list, Type value);

//Удаялет значение из списка
void remove(List* list, Type value);

//Проверяет наличие значения в списке
bool contains(List* list, Type value);

//Проверяет равенство двух списков
bool listCmp(List* list1, List* list2);

//Заполняет список элементами из массива
void fillListByArray(List* list, Type* array, int sizeOfArray);

//Проверяет пустоту списка
bool isEmpty(List* list);

//Печатает список
void printList(List* list);

//Печатает список в файл
void printListToFile(List* list, FILE* filePtr);