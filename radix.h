#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}

        int getMaximo() {
            int maximo = elements[0];
            for (int i = 1; i < size; ++i)
                if (elements[i] > maximo)
                    maximo = elements[i];
            return maximo;
        }

        void countingSort(int exponente) {
            int salida[size];
            int i, cuenta[10] = {0};
            for (i = 0; i < size; ++i)
                cuenta[(elements[i] / exponente) % 10]++;
            for (i = 1; i < 10; ++i)
                cuenta[i] += cuenta[i - 1];
            for (i = size - 1; i >= 0; i--) {
                salida[cuenta[(elements[i] / exponente) % 10] - 1] = elements[i];
                cuenta[(elements[i] / exponente) % 10]--;
            }
            for (i = 0; i < size; ++i)
                elements[i] = salida[i];
        }

        void execute() override {
            int maximo =  getMaximo();
            for (int exponente = 1; maximo / exponente > 0; exponente *= 10)
                countingSort(exponente);
        }

        inline string name() override { return "RadixSort"; }
};

#endif