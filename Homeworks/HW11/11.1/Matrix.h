#pragma once
#include "List.h"

//Печатает матрицу 
void printMatrix(int** matrix, int size);

//Создает новую матрицу
int** createMatrix(int size);

//Удаляет матрицу
void deleteMatrix(int** matrix, int size);