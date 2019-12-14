#pragma once

//Тип данных множество вершин графа
struct Set;

//Проверяет, пусто ли множество
bool isEmpty(Set* set);

//Создает новое множество
Set* createSet();

//Добавляет новую вершину в множество
bool add(Set* set, int distance, int vertex);

//Удаляет вершину из множества
bool remove(Set* set, int distance, int vertex);

//Удаляет множество
bool deleteSet(Set* set);

//Возвращает ближайшую вершину
int nearestVertex(Set* set);