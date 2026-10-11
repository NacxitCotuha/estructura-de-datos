#include "menu_main.h"

// #include "utils/limpiar.h"
#include "arreglos/menu_arreglos.h"
#include "utils/validar_entradas.h"

#include <stdio.h>
#include <stdbool.h>

bool opciones(int opcion) {
    if (opcion == 1) return menu_arreglos();
    if (opcion == 2) return true;
    if (opcion == 3) return true;
    if (opcion == 4) return true;
    if (opcion == 5) return true;
    if (opcion == 6) return true;
    if (opcion == 7) return true;
    if (opcion == 8) return true;
    if (opcion == 9) return true;
    printf("Opcion Invalida, la opcion %d no existe.\n", opcion);
    return false;
}

bool menu_main() {
    printf("====================================\n");
    printf("= MENU - EJERCICIOS                =\n");
    printf("1.- Arreglos\n");
    printf("2.- Estructuras\n");
    printf("3.- Punteros\n");
    printf("4.- Memoria Dinamica\n");
    printf("5.- Colas Circulares\n");
    printf("6.- Pilas Estaticas\n");
    printf("7.- Colas Dinamicas\n");
    printf("8.- Pilas Dinamicas\n");
    printf("9.- Arboles Binarios\n");
    printf("\n");
    printf("0.- Salir\n");
    printf("\n");
    printf("Por Favor, ingrese la opcion como numero entero:");
    int opcion = entrada_entero();

    if (opcion == 0) {
        return true;
    }

    return opciones(opcion);
}