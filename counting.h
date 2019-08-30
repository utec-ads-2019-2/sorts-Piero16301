#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <vector>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            int maximo = *max_element(elements, elements + size);
            int minimo = *min_element(elements, elements + size);
            int rango = maximo - minimo + 1;
            vector <int> cuenta(rango), salida(size);
            for (int i = 0; i < size; ++i)
                cuenta[elements[i] - minimo]++;
            for (int j = 1; j < cuenta.size(); ++j)
                cuenta[j] += cuenta[j - 1];
            for (int k = size - 1; k >= 0; --k) {
                salida[cuenta[elements[k] - minimo]] = elements[k];
                cuenta[elements[k] - minimo]--;
            }
            for (int l = 0; l < size; ++l)
                elements[l] = salida[l];
        }

        inline string name() override { return "CountingSort"; }
};

#endif