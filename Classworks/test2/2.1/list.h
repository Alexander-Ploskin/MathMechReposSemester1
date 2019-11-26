#pragma once

//Тип данных список
struct List;

//Проверяет пустоту списка
bool isEmpty(List* list);

//Создает список
List* createList();

//Удаляет список
void deleteList(List* list);

//Проверяет, есть ли значение в списке
bool contains(List* list, int value);

//Добавляет в список новое значение
void add(List* list, int value);

//Возвращает длину списка
int length(List* list);

//Печатает список
void printList(List* list);

//Возвращает список с наибольшей возрастающей подпоследовательностью
List* increasingList(List* list);

//Проверяет, равны ли списки
bool compareOfLists(List* list1, List* list2);