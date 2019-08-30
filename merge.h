#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}

        void merge(int menor, int mitad, int mayor) {
            int i, j, k;
            int numero1 = mitad - menor + 1;
            int numero2 = mayor - mitad;
            int Izquierda[numero1], Derecha[numero2];
            for (i = 0; i < numero1; i++)
                Izquierda[i] = elements[menor + i];
            for (j = 0; j < numero2; j++)
                Derecha[j] = elements[mitad + 1 + j];
            i = 0;
            j = 0;
            k = menor;
            while (i < numero1 && j < numero2) {
                if (Izquierda[i] <= Derecha[j]){
                    elements[k] = Izquierda[i];
                    i++;
                } else {
                    elements[k] = Derecha[j];
                    j++;
                }
                k++;
            }
            while (i < numero1) {
                elements[k] =  Izquierda[i];
                i++;
                k++;
            }
            while (j < numero2) {
                elements[k] = Derecha[j];
                j++;
                k++;
            }
        }

        void sort(int menor, int mayor) {
            if (menor < mayor) {
                int mitad = menor + (mayor - menor) / 2;
                sort(menor, mitad);
                sort(mitad + 1, mayor);
                merge(menor, mitad, mayor);
            }
        }

        void execute() override {
            int menor = 0, mayor = size - 1;
            sort(menor, mayor);
        }

        inline string name() override { return "MergeSort"; }
};

#endif