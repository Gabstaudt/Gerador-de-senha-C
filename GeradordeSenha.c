#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma senha aleatória
void generatePassword(int length, int uppercase, int lowercase, int numbers, int special) {
    char charset[95]; // Array para armazenar os caracteres possíveis
    char password[length + 1]; // Array para armazenar a senha gerada, incluindo espaço para o caractere nulo
    int i, index;

    // Populando o conjunto de caracteres com base nas opções selecionadas
    index = 0;
    if (uppercase) {
        for (i = 0; i < 26; i++) {
            charset[index++] = 'A' + i; // Adiciona letras maiúsculas ao conjunto de caracteres
        }
    }
    if (lowercase) {
        for (i = 0; i < 26; i++) {
            charset[index++] = 'a' + i; // Adiciona letras minúsculas ao conjunto de caracteres
        }
    }
    if (numbers) {
        for (i = 0; i < 10; i++) {
            charset[index++] = '0' + i; // Adiciona números ao conjunto de caracteres
        }
    }
    if (special) {
        for (i = 33; i <= 126; i++) {
            if (i >= 48 && i <= 57) // Exclui números
                continue;
            if (i >= 65 && i <= 90) // Exclui letras maiúsculas
                continue;
            if (i >= 97 && i <= 122) // Exclui letras minúsculas
                continue;
            charset[index++] = (char)i; // Adiciona caracteres especiais ao conjunto de caracteres
        }
    }
    charset[index] = '\0'; // Adicionando o caractere nulo no final do conjunto de caracteres

    // Gerando a senha aleatória
    srand(time(NULL)); // Inicializando gerador de números aleatórios
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % index]; // Seleciona aleatoriamente os caracteres do conjunto para a senha
    }
    password[length] = '\0'; // Adicionando o caractere nulo no final da senha

    // Imprimindo a senha gerada
    printf("Senha gerada: %s\n", password); // Exibe a senha gerada na tela
}

int main() {
    int length;
    int uppercase, lowercase, numbers, special;

    // Solicita ao usuário que insira as opções para gerar a senha
    printf("Comprimento da Senha: ");
    scanf("%d", &length);

    printf("Incluir Letras Maiusculas (1 para Sim, 0 para Nao): ");
    scanf("%d", &uppercase);

    printf("Incluir Letras Minusculas (1 para Sim, 0 para Nao): ");
    scanf("%d", &lowercase);

    printf("Incluir Numeros (1 para Sim, 0 para Nao): ");
    scanf("%d", &numbers);

    printf("Incluir Caracteres Especiais (1 para Sim, 0 para Nao): ");
    scanf("%d", &special);

    // Chama a função para gerar a senha com base nas opções fornecidas pelo usuário
    generatePassword(length, uppercase, lowercase, numbers, special);

    return 0;
}
