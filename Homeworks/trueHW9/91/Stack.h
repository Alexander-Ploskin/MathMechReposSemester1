#pragma once

//Тип данных стек
struct Stack;

//Создает новый стек
Stack* createStack();

//Добавляет в стек новую запись
void push(Stack* stack, SetElement*& value);

//Снимает значение с головы стека
SetElement* pop(Stack* stack);

//Удаляет стек
void deleteStack(Stack* stack);

