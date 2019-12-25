#pragma once
#include <stdio.h>

//Тип данных список
struct List;

//Создет новый список
List* createList();

void addToList(List* list, int value);

//Проверяет пустоту списка
bool isEmpty(List* list);

//Печатает список
void printList(List* list);

//Удаляет список
void deleteList(List* list);

//Переписывает список в файл
void writeListToFile(List* list, FILE* filePtr);