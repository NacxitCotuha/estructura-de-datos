#include "utils/validar_entradas.h"

#include "utils/limpiar.h"

#include<stdio.h>

int entrada_entero() {
    int numero;
    int resultado;
    while ((resultado = scanf("%d", &numero)) != 1) {
        
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
    printf("Tipo de Entrada Valida para: %d\n", numero);
    return numero;
}