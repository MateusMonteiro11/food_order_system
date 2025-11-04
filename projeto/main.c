#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "funcoes.c"
#include <time.h>

int main() {
    srand(time(NULL));
    int opcao = -1; // Inicializa com valor diferente de 0, não pode ser maior que 0.
    int idUsuario = -1; // -1 indica que nenhum usuário está logado, ou seja, inicializa sempre com um usuário deslogado.

    while (opcao != 0) {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Fazer login\n");
        printf("3 - Cadastrar pedido\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                idUsuario = loginUsuario();
                break;
            case 3:
                if (idUsuario != -1)
                    cadastrarPedido(idUsuario);
                else
                    printf("Você precisa estar logado para efetuar a operação\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
