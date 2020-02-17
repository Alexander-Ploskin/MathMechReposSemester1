#pragma once

//Максимальная длина строк
const int maxLength = 100;

//Тип данных список
struct List;

//Создает новый список
List* createList();

//Удаляет список
void deleteList(List* list);

//Добавляет в список новый элемент
void add(List* list, char* value);

//Печатает список
void printList(List*list);

//Проверяет уникальность всех элементов списка
bool checkRight(List* list);

//Создает новый очищенный список
void clearList(List* list);