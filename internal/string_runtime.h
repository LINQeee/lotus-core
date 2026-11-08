#ifndef LOTUS_INTERNAL_STRING_H
#define LOTUS_INTERNAL_STRING_H

#include <stdbool.h>

#include "../lotus.h"

void _stringRetain(LotusString *str);
void _stringRelease(LotusString *str);
bool _stringEquals(const LotusString *left, const LotusString *right);
LotusString *_concat(LotusString *left, LotusString *right);

#endif
