#pragma once

//Тип данных список
struct List;

//Создает новый список
List* createList();

//Удаляет список
void deleteList(List* list);

//Добавляет в список новый элемент
void add(List* list, int value);

//Создает новый список, разворачивая старый
List* reverse(List* listToReverse);

//Печатает список
void printList(List* list);

//Сравнивает два списка
bool listcmp(List* list1, List* list2);

//Заполняет список по строке
void fillList(char* string, List* list);
