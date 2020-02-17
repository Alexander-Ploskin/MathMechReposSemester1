#pragma once

//Тип данных список
struct Backet;

//Создает список
Backet* createBacket();

//Удаляет список
void deleteBacket(Backet* backet);

//Добавляет в список новый элемент
void addToBacket(Backet* backet ,char* input);

//Удалить элемент из списка
bool deleteElementFromBacket(char* string, Backet* backet);

//Проверяет, содержится ли в списке такая строка
bool containsInBacket(char* string, Backet* backet);

