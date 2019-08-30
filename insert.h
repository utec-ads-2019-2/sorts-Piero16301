#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            int pivote, key;
            for (int i = 1; i < size; ++i) {
                pivote = elements[i];
                key = i - 1;
                while (key >= 0 && elements[key] > pivote) {
                    elements[key + 1] = elements[key];
                    key--;
                }
                elements[key + 1] = pivote;
            }
        }

        inline string name() override { return "InsertSort"; }
};

#endif