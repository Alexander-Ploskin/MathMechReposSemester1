#pragma once

struct OpenBracket
{
	char bracket;
	OpenBracket* next;
};

//Проверяет, пуст ли стек
bool isEmpty(OpenBracket* head);

//Удаляет элемент стека
void deleteStackElement(OpenBracket** head);

//Снимает значение с головы стека
const char pop(OpenBracket** head);

//Добавляет элемент в стек
void push(char value, OpenBracket** head);