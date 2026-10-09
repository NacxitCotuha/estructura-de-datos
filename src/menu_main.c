#include "menu_main.h"
#include <stdio.h>
#include <stdbool.h>

void menu(int opcion) {
    switch(opcion) {
        case 1:
        break;
    }
}

bool opciones() {
    int opcion;
    printf("====================================\n");
    printf("= MENU                             =\n");
    
    printf("0.- Salir\n");
    printf("Por Favor, ingrese la opcion:");
    scanf("%d", &opcion);

    if (opcion == 0) {
        return true;
    }

    menu(opcion);
    return false;
}