#pragma once

//Тип данных словарь 
struct Set;

//Проверяет, пуст ли словарь
bool isEmpty(Set* set);

//Проверяет, содержится ли запись с таким ключом в словаре
bool contains(Set* set, int key);

//Создает новый словарь
Set* createSet();

//Выдает запись из словаря по данному ключу
char* getValue(Set* set, int key);

//Добавляет новую запись в словарь
bool add(Set* set, int key, char* string);

//Удаляет запись с таким ключом из словаря
bool remove(Set* set, int key);

//Заменяет строку в записи с таким ключом на новую
bool substitute(Set* set, int key, char* string);

//Удаляет словарь
bool deleteSet(Set* set);