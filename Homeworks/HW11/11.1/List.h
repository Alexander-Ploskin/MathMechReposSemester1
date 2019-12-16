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

//Создает массив списков
List** createArrayOfLists(int numberOfLists);

//Удаляет массив списков
void deleteArrayOfLists(List** listOfLists, int numberOfLists);

//Удаляет элемент из списка, возвращает false, если удалить ничего не удалось
bool removeFromList(List* list, int value);

//Проверяет пустоту списка
bool isEmpty(List* list);

//Создает список по массиву
List* createListByArray(int* array, int sizeOfArray);

//Сравнивает два массива списков
bool arrayOfListscmp(List** array1, List** array2, int sizeOfArray1, int sizeOfArray2);

//Удаляет все списки в массиве списков
void deleteListsOfTheArray(List** arrayOfLists, int numberOfLists);