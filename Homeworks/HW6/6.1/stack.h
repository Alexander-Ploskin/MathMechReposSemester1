#pragma once

// Тип данных стек 
struct Stack;

// Добавляет новый элемент в стек
void push(int value, Stack* stack);

// Снимает значение с головы стека
int pop(Stack* stack);

// Проверяет пустоту стека
bool isEmpty(Stack* stack);

// Удаляет стек
void deleteStack(Stack* stack);

// Создает стек
Stack* createStack();

//Выдает значение с головы стека
int checkHead(Stack* stack);