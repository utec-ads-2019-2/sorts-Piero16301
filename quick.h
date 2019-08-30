#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        static void swap(int *x, int *y) {
            int temporal = *x;
            *x = *y;
            *y = temporal;
        }

        int particion(int menor, int mayor) {
            int pivote = elements[mayor];
            int indiceMenor = (menor - 1);
            for (int j = menor; j <= mayor - 1; ++j) {
                if (elements[j] < pivote) {
                    indiceMenor++;
                    swap(&elements[indiceMenor], &elements[j]);
                }
            }
            swap(&elements[indiceMenor + 1], &elements[mayor]);
            return (indiceMenor + 1);
        }

        void sort(int menor, int mayor) {
            if (menor < mayor) {
                int indiceParticion = particion(menor, mayor);
                sort(menor, indiceParticion - 1);
                sort(indiceParticion + 1, mayor);
            }
        }

        void execute() override {
            int menor = 0, mayor = size - 1;
            sort(menor, mayor);
        }

        inline string name() override { return "QuickSort"; }
};

#endif