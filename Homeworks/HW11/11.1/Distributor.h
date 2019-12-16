#pragma once
#include "List.h"

//Возвращает массив списков городов, которыми владеет каждое государство
List** distribution(int** adjacencyMatrix, int* capitals, int numberOfTowns, int numberOfStates);