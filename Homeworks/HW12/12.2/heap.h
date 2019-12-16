#pragma once

//Тип данных куча вершин графа
struct Heap;

//Добавление вершины в кучу
void add(Heap* heap, int vertex, int distance, int adjacentVertex);

//Возвращает из кучи ближайшую вершину
int popNearestVertex(Heap* heap, int& adjacentVertex);

//Создает кучу
Heap* createHeap();

//Удаляет кучу
void deleteHeap(Heap* heap);

//Проверяет пустоту кучи
bool isEmptyHeap(Heap* heap);