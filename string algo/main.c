#include "stralg.h"
#include <stdio.h>


int main() {
    const char* stroka = "Eta programma ishet samuyu dlinnuyu podstroku v stroke";
    printf("%d %c", find(stroka, "programma"), '\n');
    return 0;
}