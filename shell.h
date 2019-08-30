#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            for (int intervalo = size / 2; intervalo > 0; intervalo /= 2) {
                for (int i = intervalo; i < size; ++i) {
                    int temporal = elements[i];
                    int j;
                    for (j = i; j >= intervalo && elements[j - intervalo] > temporal; j -= intervalo)
                        elements[j] = elements[j - intervalo];
                    elements[j] = temporal;
                }
            }
        }

        inline string name() override { return "ShellSort"; }
};

#endif