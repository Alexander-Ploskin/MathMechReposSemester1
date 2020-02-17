#pragma once

//Тип данных словарь 
struct Set;

//Проверяет, пуст ли словарь
bool isEmpty(Set* set);

//Проверяет, содержится ли запись с таким ключом в словаре
bool contains(Set* set, int key);

//Создает новый словарь
Set* createSet();

//Добавляет новую запись в словарь
bool add(Set* set, int key, int input);

//Удаляет запись с таким ключом из словаря
bool remove(Set* set, int key);

//Удаляет словарь
bool deleteSet(Set* set);

//Проверяет сбалансированность дерева
bool balanced(Set* set);

//Возвращает значение вершины с минимальным ключом и удаляет ее
int getMininumInSetAndRemove(Set* set, int& adjacentVertex);