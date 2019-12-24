#pragma once

//Максимальное число элементов в куче
const int maxNumberOfElements = 1000;

//Тип данных очередь с приоритетами
struct PriorityQueue;

//Создать очередь
PriorityQueue* createQueue();

//Удаляет очередь
void deleteQueue(PriorityQueue* queue);

//Добавляет в очередь новый элемент
void enqueue(PriorityQueue* queue, int value, int key);

//Извлекает из очереди элемент с наивысшим приоритетом
int dequeue(PriorityQueue* queue);

//Проверяет пустоту очереди
bool isEmptyQueue(PriorityQueue* queue);