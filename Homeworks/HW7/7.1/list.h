#pragma once

//Тип данных список
struct List;

//Элемент листа
struct ListElement;

//Проверка пустоты списка
bool isEmpty(List* list);

//Создает новый список
List* createList();

//Ищет элемент списка, в котором хранится указатель на нужный элемент, кроме головы списка
ListElement* searchPositionNotInHead(List* list, int searchValue);

//Печатает список
void printList(List* list);

//Удаляет список
void deleteList(List* list);

//Добавляет новую запись в список
void push(List* list, int value);

//Удаляет запись из списка
void deleteElement(List* list, int value);

//Проверяет отсортированность списка
bool isSorted(List* list);

//Проверяет, есть ли в списке такое значение
bool isContains(List* list, int searchValue);

//Проверяет находится ли значение в голове списка
bool checkHead(List* list, int searchValue);