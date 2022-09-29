#include <stdio.h>

int calculaDV1(char cpf[12]);
int calculaDV2(char cpf[12]);

int main() {
    char cpf[11] = {};
    printf("Insira o CPF (somente numeros):\t");
    fgets(cpf, 12, stdin);
    printf("\n");

    if ((int) cpf[9] - 48 == calculaDV1(cpf)) {
        if ((int) cpf[10] - 48 == calculaDV2(cpf)) {
            printf("CPF VALIDO!\n");
        } else {
            printf("CPF INVALIDO!\n");
        }
    } else {
        printf("CPF INVALIDO!\n");
    }
    return 0;
}

int calculaDV1(char cpf[11]) {
    int soma = 0, i = 10;
    char *ptr = cpf;

    while (i > 1) {
        int n = (int) *ptr - 48;
        soma = soma + i * n;
        ptr++;
        i--;
    }

    if (soma % 11 < 2) {
        return 0;
    } else {
        return 11 - (soma % 11);
    }
}

int calculaDV2(char cpf[11]) {
    int soma = 0, i = 11;
    char *ptr = cpf;

    while (i > 1) {
        int n = (int) *ptr - 48;
        soma = soma + i * n;
        ptr++;
        i--;
    }

    if (soma % 11 < 2) {
        return 0;
    } else {
        return 11 - (soma % 11);
    }
}