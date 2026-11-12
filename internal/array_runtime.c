#include "../lotus.h"
#include "array_runtime.h"
#include "string_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct LotusArray {
    size_t references;
    int32_t length;
    LotusType elementType;
    union {
        uint64_t bits;
        LotusString *string;
    } data[];
};

LotusArray *_arrayCreate(int32_t length, int32_t elementType) {
    if (length < 0 || (size_t)length > (SIZE_MAX - sizeof(LotusArray)) / sizeof(uint64_t)) {
        fprintf(stderr, "Array size must be nonnegative and fit in memory\n");
        exit(1);
    }
    size_t bytes = sizeof(LotusArray) + (size_t)length * sizeof(uint64_t);
    LotusArray *array = malloc(bytes);
    if (!array) {
        fprintf(stderr, "Cannot allocate array of length %d\n", length);
        exit(1);
    }
    memset(array, 0, bytes);
    array->references = 1;
    array->length = length;
    array->elementType = elementType;
    if (elementType == LOTUS_STRING) {
        static LotusString empty = {0, "", 0};
        for (int32_t i = 0; i < length; i++) array->data[i].string = &empty;
    }
    return array;
}

void *_arrayAt(LotusArray *array, int32_t index) {
    if (index < 0 || index >= array->length) {
        fprintf(stderr, "Array index %d out of bounds for length %d\n", index, array->length);
        exit(1);
    }
    return &array->data[index];
}

int32_t _arrayLength(const LotusArray *array) {
    return array->length;
}
void _arrayRetain(LotusArray *array) {
    array->references++;
}
void _arrayRelease(LotusArray *array) {
    if (--array->references) return;
    if (array->elementType == LOTUS_STRING)
        for (int32_t i = 0; i < array->length; i++) _stringRelease(array->data[i].string);
    free(array);
}
