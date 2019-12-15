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
void addVertex(ListOfVertexes* list, int distance, int vertex);

//Удаляет вершину из списка
void removeVertex(ListOfVertexes* list, int vertex);

//Возвращает ближайшую вершину
int nearestVertex(ListOfVertexes* list);

//Создает массив списков
ListOfVertexes** createArrayOfLists(int numberOfLists);

//Удаляет массив списков
void deleteArrayOfLists(ListOfVertexes** array, int numberOfLists);