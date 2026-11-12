#ifndef LOTUS_INTERNAL_ARRAY_H
#define LOTUS_INTERNAL_ARRAY_H
#include <stdint.h>
#include "../lotus.h"

typedef struct LotusArray LotusArray;
LOTUS_EXPORT LotusArray *_arrayCreate(int32_t length, int32_t elementType);
LOTUS_EXPORT void *_arrayAt(LotusArray *array, int32_t index);
LOTUS_EXPORT int32_t _arrayLength(const LotusArray *array);
LOTUS_EXPORT void _arrayRetain(LotusArray *array);
LOTUS_EXPORT void _arrayRelease(LotusArray *array);
#endif
