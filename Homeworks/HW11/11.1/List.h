#pragma once

//Тип данных список
struct List;

//Создает список
List* createList();

//Удаляет список
void deleteList(List* list);

//Добавляет в начало списка новое значение
void addToList(List* list, int value);

//Возвращает последнее добавленное значение
int popFromList(List* list);

//Печатает список
void printList(List* list);

//Удаляет список
void deleteList(List* list);

//Сравнивает два списка
bool listcmp(List* list1, List* list2);

//Создает список по массиву
List* createListByArray(int* array, int arraySize);

//Создает массив списков
List** createArrayOfLists(int numberOfLists);

//Удаляет массив списков
void deleteArrayOfLists(List** listOfLists, int numberOfLists);