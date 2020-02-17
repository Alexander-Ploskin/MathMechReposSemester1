#pragma once

//Максимальная длина строк
const int maxLength = 100;

//Тип данных список
struct List;

//Создет новый список
List* createList();

//Проверяет пустоту списка
bool isEmpty(List* list);

//Проверяет, есть ли такая строка в списке
bool contains(List* list, char* value);

//Добавляет в список новое значение
void addToList(List* list, char* value);

//Удаляет значение из списка
void removeFromList(List* list, char* value);

//Печатает список
void printList(List* list);

//Снимает значение с головы списка
int pop(List* list, char* buffer);

//Удаляет список
void deleteList(List* list);