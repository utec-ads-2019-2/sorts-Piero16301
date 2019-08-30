#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        static void swap(int *x, int *y) {
            int temporal = *x;
            *x = *y;
            *y = temporal;
        }

        void execute() override {
            int indiceMinimo;
            for (int i = 0; i < size - 1; ++i) {
                indiceMinimo = i;
                for (int j = i + 1; j < size; ++j)
                    if (elements[j] < elements[indiceMinimo])
                        indiceMinimo = j;
                swap(&elements[indiceMinimo], &elements[i]);
            }
        }

        inline string name() override { return "SelectSort"; }
};

#endif