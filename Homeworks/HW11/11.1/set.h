#pragma once

//Тип данных множество вершин графа
struct Set;

//Проверяет, пуст0 ли множество
bool isEmpty(Set* set);

//Создает новое множество
Set* createSet();

//Добавляет новую вершину в множество
bool add(Set* set, int distance, int vertex);

//Удаляет запись с таким ключом из словаря
bool remove(Set* set, int distance);

//Удаляет множество
bool deleteSet(Set* set);

//Возвращает ближайшую вершину
int nearestVertex(Set* set);