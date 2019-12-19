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
void addToQueue(PriorityQueue* queue, int value, int key, int additionalValue);

//Извлекает из очереди элемент с наименьшим ключом
int extractMin(PriorityQueue* queue, int& bufferOfAdditionalValue);

//Проверяет пустоту очереди
bool isEmptyQueue(PriorityQueue* queue);