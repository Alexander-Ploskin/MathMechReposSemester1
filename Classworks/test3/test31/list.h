#pragma once

//Тип данных список
struct List;

//Элемент листа
struct ListElement;

//Проверка пустоты списка
bool isEmpty(List* list);

//Создает новый список
List* createList();

//Печатает список
void printList(List* list);

//Удаляет список
void deleteList(List* list);

//Добавляет новую запись в список
void push(List* list, int value);

//Проверяет, есть ли в списке такое значение
bool isContains(List* list, int searchValue);