#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 100

// Función para verificar si una palabra es un palíndromo
int es_palindromo(char *palabra)
{
    int len = strlen(palabra);
    for (int i = 0; i < len / 2; i++)
    {
        if (palabra[i] != palabra[len - i - 1])
        {
            return 0; // No es palíndromo
        }
    }
    return 1; // Es palíndromo
}

int main()
{
    char palabra[MAX_LEN];

    printf("Ingresa una palabra: ");
    if (fgets(palabra, MAX_LEN, stdin) == NULL)
    {
        perror("Error al leer la entrada");
        exit(1);
    }

    // Eliminar el salto de línea al final
    palabra[strcspn(palabra, "\n")] = '\0';

    // Verificar si es un palíndromo
    if (es_palindromo(palabra))
    {
        printf("La palabra '%s' es un palíndromo.\n", palabra);
    }
    else
    {
        printf("La palabra '%s' NO es un palíndromo.\n", palabra);
    }

    return 0;
}
