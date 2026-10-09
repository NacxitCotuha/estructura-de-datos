#include <stdio.h>
#include <stdbool.h>
#include "menu_main.h"

int main() {
    printf("====================================\n");
    printf("= ESTRUCTURA DE DATOS - EJERCICIOS =\n");
    printf("====================================\n");
    while(true) {
        bool isExit = opciones();
        if (isExit) {
            return 0;
        }
    }

    return 0;
}