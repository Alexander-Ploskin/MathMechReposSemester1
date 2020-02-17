#pragma once

//Количество хэшей
const int hashSize = 100;

//Максимальный размер строк
const int maxSize = 100;

//АТД словарь
struct Set;

//Создает словарь
Set* createSet();

//Удаляет словарь
void deleteSet(Set* set);

//Добавляет строку в словарь
void add(Set* set, char* string);

//Проверяет принадлежность строки словарю
bool contains(Set* set, char* string);

//Удаляет строку из словаря
bool deleteElement(Set* set, char* string);