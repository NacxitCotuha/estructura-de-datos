#include "menu_main.h"
#include <stdio.h>
#include <stdbool.h>

int validar_opcion() {
    int opcion;
    int resultado;
    while ((resultado = scanf("%d", &opcion)) != 1) {
        
        // 2. Comprobar si se llegó al final del archivo (EOF)
        if (resultado == EOF) {
            printf("Error grave en la entrada de datos.\n");
            return 0; 
        }

        // 3. Limpiar el búfer de entrada (descarta los caracteres incorrectos)
        while (getchar() != '\n'); 

        printf("Entrada invalida. Por favor, introduce un numero entero: ");
    }
    limpiar_terminal();
    printf("Entrada Valida para: %d\n", opcion);
    return opcion;
}

void opciones(int opcion) {
    switch(opcion) {
        case 1:
        break;
    }
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
    int opcion = validar_opcion();

    if (opcion == 0) {
        return true;
    }

    menu(opcion);
    return false;
}