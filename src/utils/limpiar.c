#include "utils/limpiar.h"
#include <stdio.h>
#include <stdlib.h>

void limpiar_terminal() {
    printf("\033[2J\033[H");

    // #ifdef _WIN32
    //     system("cls");
    // #else
    //     system("clear");
    // #endif
}
