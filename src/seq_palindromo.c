#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#define MAX_LINE_LENGTH 100

// Função para verificar se uma palavra é um palíndromo
bool IsPalindrome(char *word) {
    int length = strlen(word);

    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return false;
        }
    }

    return true;
}

// Função principal
int main(int argc, char *argv[]) {
    // Abrir o arquivo
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Ler as palavras do arquivo
    char *line,*line2;
    line = malloc(sizeof(char)*MAX_LINE_LENGTH);
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Remover o caractere de nova linha do final da linha
        line[strcspn(line, "\n")] = '\0';
	line2 = malloc(sizeof(char)*MAX_LINE_LENGTH);

	 for (int i = 0, j = 0; i < strlen(line); i++) {
            if (line[i] == ' ' || line[i] == ',' || line[i] == '-') {
         	continue; //       line[i] = '\0';
            } else {
                line2[j] = tolower(line[i]);
		j++;
            }
        }

        // Verificar se a palavra é um palíndromo
        if (IsPalindrome(line2)) {
            printf("%s é um palíndromo\n", line2);
        }
	free(line2);
    }

    // Fechar o arquivo
    fclose(fp);
    free(line);

    return 0;
}
