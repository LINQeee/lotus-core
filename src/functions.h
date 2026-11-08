#ifndef LOTUS_FUNCTIONS_H
#define LOTUS_FUNCTIONS_H

#include <stdbool.h>

#include "../lotus.h"

void print(int count, ...);
LotusString *input(void);
bool toBool(LotusValue value);
int toInt(LotusString *str);
int randomNum(int min, int max);

#endif
