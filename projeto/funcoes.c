#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include <time.h>

void cadastrarUsuario() {
    Usuario u; // Declarando a tabela usuario.
    FILE *file = fopen("data/usuarios.txt", "a"); // Abre arquivo usuarios em modo de adição.

    if (!file) { // Estrutura padrão para checar se o arquivo existe.
        printf("Erro ao abrir arquivo de usuários!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", u.nome); // Lê todos os caracteres até \n do arquivo.
    printf("Digite o email: ");
    scanf(" %[^\n]", u.email);
    printf("Digite a senha: ");
    scanf(" %[^\n]", u.senha);

    // Gera um id de forma aleatória.
    u.id = rand() % 1000;

    fprintf(file, "%d;%s;%s;%s\n", u.id, u.nome, u.email, u.senha); // Armazena os dados do usuário cadastrado no arquivo.
    fclose(file); // Fecha o arquivo.
    printf("Usuário cadastrado com sucesso!\n");
}

int loginUsuario() {
    char email[50], senha[20]; // Declara caracteres de email e senha.
    Usuario u;// Declara a tabela de usuario de funcoes.h
    FILE *file = fopen("data/usuarios.txt", "r"); // Abre o arquivo em modo de leitura

    if (!file) { // Estrutura padrão para checar se o arquivo existe.
        printf("Erro ao abrir arquivo de usuários!\n");
        return -1;
    }

    printf("Email: ");
    scanf(" %[^\n]", email);
    printf("Senha: ");
    scanf(" %[^\n]", senha);

    while (fscanf(file, "%d;%[^;];%[^;];%[^\n]\n", &u.id, u.nome, u.email, u.senha) == 4) { // Verifica se os dados de usuario foram lidos.
        if (strcmp(u.email, email) == 0 && strcmp(u.senha, senha) == 0) { // Verifica se naquela linha o email e senha estão iguais, uso de comparativo.
            fclose(file); // Caso ache, não haverá mais necessidade da leitura do arquivo.
            printf("Login realizado com sucesso! Bem-vindo, %s!\n", u.nome);
            return u.id; // Retorna o id do usuário que o manterá logado.
        }
    }

    fclose(file);
    printf("Email ou senha incorretos.\n"); // Checagem padrão para email e senhas incorretas.
    return -1;
}

void cadastrarPedido(int idUsuario) {
    Alimento sacola[20]; // Declaramos uma array que retorna quantidades máximas de itens na sacola.
    int qtd = 0; // Armazenamos as quantidades atuais da sacola, sempre iniciará como 0.
    int opcao; // Formato simples de armazenar a opção do usuario.

    do { // Iniciamos o loop com do-while pra restringir o looping.
        printf("\n===== MENU DA SACOLA =====\n");
        printf("1. Buscar e adicionar alimento\n");
        printf("2. Remover alimento da sacola\n");
        printf("3. Ver itens da sacola\n");
        printf("4. Confirmar pedido\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            FILE *file = fopen("data/alimentos.txt", "r"); // Abrimos alimentos.txt em formato de leitura.
            if (!file) {
                printf("Erro ao abrir alimentos.txt\n"); // Retorno padrão em relação ao erro com abrir o arquivo.
                return;
            }

            char busca[50]; // Criamos um array com 50 indices as quais irão armazenar os valores de busca.
            Alimento a; // Definimos a tabela Alimento como "a".
            int encontrado = 0; // Armazenamos um contador que também deve sempre iniciar como 0.

            printf("\nDigite o nome do alimento: ");
            scanf(" %[^\n]", busca); // Irá ler para todo arranjo até /n

            while (fscanf(file, "%d;%[^;];%[^;];%f\n", &a.id, a.nome, a.categoria, &a.preco) == 4) { // Normã padrão para verificar os valores dentro do arquivo apontado.
                if (_stricmp(a.nome, busca) == 0) { // Compara se o nome do alimento é igual o que está armazenado em busca.
                    printf("Adicionado: %s (R$ %.2f)\n", a.nome, a.preco);
                    sacola[qtd++] = a; // Retornamos um incremento no valor da sacola.
                    encontrado = 1; // Valor do contador marcaod como TRUE, portanto:
                    break; // Encerra o loop.
                }
            }
            fclose(file);
            if (!encontrado) // Normã padrão para caso o valor do contador retorne como FALSE.
                printf(" Alimento não encontrado.\n");
        }

        else if (opcao == 2) {
            if (qtd == 0) { // Aqui percebemos a importânica do valor da quantidade, caso demarcado como zero o código sempre irá retornar como vazio.
                printf("Sacola vazia.\n");
                continue;
            }

            printf("\nItens na sacola:\n");
            for (int i = 0; i < qtd; i++) // Criamos um laço para exibir os itens presentes na sacola do usuario.
                printf("%d. %s (R$ %.2f)\n", i + 1, sacola[i].nome, sacola[i].preco);

            int remover; // Armazenamos uma variável para remoção do índice.
            printf("Digite o número do item a remover: ");
            scanf("%d", &remover);
            remover--; // Remoção decrementa enquanto for verdade.

            if (remover >= 0 && remover < qtd) { // Lógica que interpreta quando a remoção é menor que a quantidade
                for (int i = remover; i < qtd - 1; i++) // Criamos um laço para interpretar um novo indice para cada remoção, onde para cada uma a quantidade também será alterada.
                    sacola[i] = sacola[i + 1];
                qtd--; // Valor da quantidade decrementado com a interação de cada remoção.
                printf("Item removido!\n");
            } else {
                printf("Índice inválido.\n");
            }
        }

        else if (opcao == 3) {
            if (qtd == 0) { // Mesma normã da quantidade.
                printf("Sacola vazia.\n");
                continue;
            }

            float total = 0; // Definimos um total de itens como float para evitar discrepâncias.
            printf("\n--- Itens na sacola ---\n");
            for (int i = 0; i < qtd; i++) { // Laço comum para exibir os índices da sacola que contém seus respectivos itens.
                printf("%d. %s (R$ %.2f)\n", i + 1, sacola[i].nome, sacola[i].preco);
                total += sacola[i].preco; // O valor total será complementado com os preços de cada índice.
            }
            printf("Total: R$ %.2f\n", total);
        }

        else if (opcao == 4) {
            if (qtd == 0) { // Mesma normã de quantidade.
                printf("Você precisa adicionar pelo menos um alimento.\n");
                continue;
            }

            // Geramos valores para a tabela pedidos e zeramos alguns destes.
            Pedido p;
            p.id = rand() % 10000; // Cria-se um id do pedido de forma aleatória.
            p.idUsuario = idUsuario; // Informamos ao código que o id do usuario em Pedido é o mesmo do idUsuario global.
            p.qtdAlimentos = qtd;
            p.valorTotal = 0; // Zeramos o valor total
            p.avaliado = 0; // Definimos um contador para caso avaliado ou não.

            for (int i = 0; i < qtd; i++) { // Criamos um laço para inteirar cada índice.
                p.idAlimentos[i] = sacola[i].id; // Inteiramos os valores de id alimentos para armazenar em cada índice.
                p.valorTotal += sacola[i].preco; // Inteiramos o valor total para armazenar em cada índice.
                // Isso será declarado no arquivo de pedidos.
            }

            FILE *fped = fopen("data/pedidos.txt", "a"); // Abrimos pedidos.txt em formato de adição.
            if (!fped) { // Normão padrão para erros.
                printf("Erro ao abrir pedidos.txt\n");
                return;
            }
            fprintf(fped, "%d;%d;", p.id, p.idUsuario); // Armazenamos primeiramente o id do pedido e o id do usuário.

            for (int i = 0; i < p.qtdAlimentos; i++){ // Criamos um laço para armazenar o id do alimento em cad índice.
                fprintf(fped, "%d,", p.idAlimentos[i]);
            }
            fprintf(fped, "%.2f;%d\n", p.valorTotal, p.avaliado);
            fclose(fped);
            printf("\nPedido confirmado com sucesso! (ID: %d)\n", p.id);

            // Parte em que o código deverá retornar uma opção de avaliação.
            char resp; // A decisão neste cenário foi de armazenar um caractér como opção do usuário.
            printf("Deseja avaliar este pedido? (s/n): ");
            scanf(" %c", &resp);

            if (resp == 's' || resp == 'S') {
                Avaliacao av; // Definimos a tabela avaliação como "av"
                av.idPedido = p.id; // Definimos o id da avaliação.
                av.idUsuario = p.idUsuario; // Definimos o id do usuario na tabela de pedidos.

                do { // Inicializamos o do-while novamente para restringir os valores das notas obtidas.
                    printf("Dê uma nota de 1 a 5 estrelas: ");
                    scanf("%d", &av.estrelas);

                    if (av.estrelas < 1 || av.estrelas > 5)
                        printf("Valor inválido! Digite um número entre 1 e 5.\n");
                } while (av.estrelas < 1 || av.estrelas > 5);

                FILE *fav = fopen("data/avaliacoes.txt", "a"); // Abre avaliacoes.txt em modo de adição.
                if (!fav) { // Normã de verificação simples.
                    printf("Erro ao abrir avaliacoes.txt\n");
                    return;
                }

                fprintf(fav, "%d;%d;%d\n", av.idPedido, av.idUsuario, av.estrelas); // Armazena os dados do pedido no arquivo.
                fclose(fav);

                printf("Avaliação registrada com sucesso! Obrigado!\n");
            } else {
                printf("Tudo bem! Você pode avaliar depois.\n");
            }

            break; // Encerra o menu da sacola após confirmar o pedido
        }

    } while (opcao != 0);
}