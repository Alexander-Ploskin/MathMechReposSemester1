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
