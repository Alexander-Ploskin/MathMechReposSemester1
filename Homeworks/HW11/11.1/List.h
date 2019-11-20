#pragma once

//Тип данных список
struct List;

//Создет новый список
List* createList();

//Проверяет пустоту списка
bool isEmpty(List* list);

//Проверяет, есть ли такая вершина в списке
bool contains(List* list, int vertex);

//Добавляет в список новое значение
void addToList(List* list, int vertex, int distance);

//Удаляет значение из списка
void removeFromList(List* list, int vertex);

//Удаляет список
void deleteList(List* list);