#pragma once

struct List;

List* createList();

void deleteList(List* list);

void add(List* list, int value);

void printList(List* list);

