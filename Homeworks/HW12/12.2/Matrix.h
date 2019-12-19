#include <stdio.h>
#pragma once

//Печатает матрицу
void printMatrix(int** matrix, int size);

//Создает новую матрицу
int** createMatrix(int size);

//Считывает матрицу из файла
void readMatrixFromFile(int** matrix, int size, FILE* filePtr);

//Удаляет матрицу
void deleteMatrix(int** matrix, int size);

//Сравнивает две матрицы
bool matrixcmp(int** matrix1, int** matrix2, int size1, int size2);