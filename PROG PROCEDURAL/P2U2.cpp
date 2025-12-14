#include <stdio.h>
#include <string.h>

void carga(char frase[100]) {
    // Leer la frase desde teclado
    printf("Ingrese la frase: ");
    fgets(frase, 100, stdin);
}

void cambio(char frase[100]) {
    int i;
    // Reemplazar el primer '2' por un '0'
    for (i = 0; i < strlen(frase); i++) {
        if (frase[i] == '2') {
            frase[i] = '0';
            break; // Salir del bucle después de reemplazar el primer '2'
        }
    }
}

void copiar(char frase[100], char palabra[50]) {
    // Copiar la palabra "Programación" a una nueva cadena de caracteres
    strncpy(palabra, frase, 12);
    palabra[12] = '\0'; // Agregar el carácter nulo al final de la nueva cadena
}

int contar(char frase[100]) {
    int i, vocales = 0;
    // Contar la cantidad de vocales en la frase
    for (i = 0; i < strlen(frase); i++) {
        char c = frase[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vocales++;
        }
    }
    return vocales; // Mover el return fuera del bucle
}

int main() {
    char frase[100]; 
    char palabra[50]; 
    int vocales;

    carga(frase);
    cambio(frase);
    printf("Frase modificada: %s\n", frase);

    copiar(frase, palabra);
    printf("Palabra copiada: %s\n", palabra);

    vocales = contar(frase); // Capturar el retorno de contar en una variable
    printf("Cantidad de vocales en la frase: %d\n", vocales);

    return 0;
}
