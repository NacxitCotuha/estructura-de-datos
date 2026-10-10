#include "menu_main.h"

#include <stdio.h>
#include <stdbool.h>


int main() {
    printf("====================================\n");
    printf("= ESTRUCTURA DE DATOS - EJERCICIOS =\n");
    printf("====================================\n");
    while(true) {
        bool isExit = menu_main();
        if (isExit) {
            return 0;
        }
    }

    return 0;
}