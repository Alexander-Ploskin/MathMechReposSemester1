#pragma once

//Тип данных список
struct List;

//Элемент списка
struct ListElement;

//Добавляет в список новый элемент
void push(List* list, int number);

//Удаляет элемент списка
void deleteElement(List* list, ListElement* previousElement);

//Создает список
List* createList();

//Проверяет пустоту списка
bool isEmpty(List* list);

//Печатает список
void printList(List* list);

//Находит номер выжившего воина
int counting(List* list, int m);

//Удаляет список
void deleteList(List* list);