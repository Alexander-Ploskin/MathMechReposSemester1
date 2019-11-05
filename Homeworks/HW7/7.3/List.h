#pragma once

typedef char TypeOfValue;

//Максимальная длина строк 
const int maxLength = 100;

//Тип данных двусвязанный список
struct List;

//Проверяет пустоту списка
bool isEmpty(List* list);

//Создает новый список
List* createList();

//Удаляет список
void deleteList(List* list);

//Печатает список, ставя на первое место либо main, либо additional в зависимости от выбора пользователя
void printList(List* list, bool mainFirst);

//Добавляет в список новый элемент
void push(List* list, TypeOfValue* mainValue, TypeOfValue* additionalValue);

//Снимает значение из корня списка. Требует в качестве аргумента буфферов для строк
void popFromTail(List* list, TypeOfValue* mainValueBuffer, TypeOfValue* additionalValueBuffer);

//Сравнивает значения в корне двух списков
bool isLarger(List* list1, List* list2);

//Выдает размер списка
int whatSize(List* list);

//Переносит желаемое количество элементов из одного списка в другой
void transfer(List* list, List* newList, int howMuch);

//Переносит элемент из корня одного списка в голову другого
void pushFromListToNewList(List* list, List* newList);