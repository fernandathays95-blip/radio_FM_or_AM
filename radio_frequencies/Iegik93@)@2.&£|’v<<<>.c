#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    char line[50];
    int count = 0;
    char chosen[50];

    file = fopen("1.txt", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    srand(time(NULL));

    // ler o arquivo linha por linha
    while (fgets(line, sizeof(line), file)) {
        count++;
        // escolher aleatoriamente a linha atual com probabilidade 1/count
        if (rand() % count == 0) {
            // salvar linha escolhida
            sscanf(line, "%[^\n]", chosen);
        }
    }

    fclose(file);

    printf("Numero aleatorio escolhido: %s\n", chosen);

    return 0;
}
