#pragma once

//Дерево разбора арифметического выражения
struct CountingTree;

//Находит результат выражения, разложенного в дереве (оно должно быть корректным)
int counting(CountingTree* tree);

//Выводит на консоль дерево 
void printTree(CountingTree* tree);

//Создает новое дерево
CountingTree* createTree();

//Удаляет дерево
void deleteTree(CountingTree* tree);

//Строит дерево по арифметическому выражению, строка должны быть корректным арифметическим выражением с целыми числами
void buildTree(CountingTree* tree, char* string);
