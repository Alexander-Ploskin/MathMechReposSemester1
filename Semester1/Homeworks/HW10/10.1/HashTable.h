#pragma once

//Тип данных хэш-таблица
struct HashTable;

//Создает новую хэш-таблицу
HashTable* createTable();

//Удаляет хэш-таблицу
void deleteTable(HashTable* table);

//Добавляет в хэш-таблицу новое значение
HashTable* addToTable(HashTable* table, char* value, int amount);

//Проверяет, есть ли значение в таблице
bool containsInTable(HashTable* table, char* value);

//Удаляет значение из таблицы
void removeFromeTable(HashTable* table, char* value);

//Печатает таблицу
void printTable(HashTable* table);

