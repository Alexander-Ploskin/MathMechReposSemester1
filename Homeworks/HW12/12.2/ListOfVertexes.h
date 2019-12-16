#pragma once

//Максимальное расстояние до вершин
const int maxDistance = 10000;

//Тип данных список вершин
struct ListOfVertexes;

//Создает новый список вершин
ListOfVertexes* createListOfVertexes();

//Удаляет список вершин
void deleteListOfVertexes(ListOfVertexes* list);

//Добавляет новую вершину
void addVertex(ListOfVertexes* list, int distance, int vertex, int adjacentVertex);

//Удаляет вершину из списка
void removeVertex(ListOfVertexes* list, int vertex);

//Возвращает ближайшую вершину
int nearestVertex(ListOfVertexes* list, int& adjacentVertex);

//Проверяет пустоту списка
bool isEmpty(ListOfVertexes* list);

//Создает массив списков
ListOfVertexes** createArrayOfListsOfVertexes(int numberOfLists);

//Удаляет массив списков
void deleteArrayOfListsOfVertexes(ListOfVertexes** array, int numberOfLists);