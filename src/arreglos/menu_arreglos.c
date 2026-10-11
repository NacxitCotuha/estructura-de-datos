#include "arreglos/menu_arreglos.h"

#include "utils/limpiar.h"
#include "utils/validar_entradas.h"

#include <stdio.h>
#include <stdbool.h>

bool menu_arreglos() {
    printf("====================================\n");
    printf("= MENU - EJERCICIOS DE ARREGLOS    =\n");
    printf("1.- Arreglo de numeros enteros sin puntero\n");
    printf("2.- Arreglo de numeros enteros con punteros\n");
    printf("3.- Cadenas con punteros\n");
    printf("\n");
    printf("0.- Salir\n");
    printf("\n");
    printf("Por Favor, ingrese la opcion como numero entero:");
    int opcion = entrada_entero();

    if (opcion == 0) {
        return true;
    }
    return false;
}

