#pragma once

//Тип данных список
struct List;

//Создает новый список
List* createList();

//Проверяет пустоту списка
bool isEmpty(List* list);

//Добавляет в список новый элемент
void add(List* list, int value);

//Выводит элементы списка на консоль
void printList(List* list);

//Удаляет список
void deleteList(List* list);

//Проверяет симметричность списка
bool isSymmetric(List* list);

//Создает список по массиву
void createListByArray(List* list, int* array, int sizeOfArray);