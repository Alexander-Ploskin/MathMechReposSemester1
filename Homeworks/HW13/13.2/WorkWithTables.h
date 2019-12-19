#pragma once
#include <stdio.h>

//Создает таблицу
int** createTable(int lengthOfStrings, int lengthOfColumns);

//Печатает таблицу
void printTable(int** table, int lengthOfStrings, int lengthOfColumns);

//Читает таблицу из файла и создает массив, ячейки в котором соответствуют элементам шапки таблицы
void readTableFromFile(FILE* filePtr, int** table, int lengthOfStrings, int lengthOfColumns, char* header);

//Удаляет таблицу
void deleteTable(int** table, char* header, int lengthOfStrings);

//Возвращает индекс, который соответствует элементу из шапки таблицы
int index(char* array, int size, char symbol);