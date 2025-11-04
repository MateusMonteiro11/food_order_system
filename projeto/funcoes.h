#ifndef FUNCOES_H
#define FUNCOES_H

// Banco de dados.
typedef struct {
    int id;
    char nome[50];
    char email[50];
    char senha[20];

} Usuario; // Estrutura para usuario

typedef struct {
    int id;
    char nome[50];
    char categoria[50];
    float preco;

} Alimento; // Estrutura para alimentos

typedef struct {
    int id;
    int idUsuario;
    int idAlimentos[10];
    int qtdAlimentos;
    float valorTotal;
    int avaliado; // 0 = não, 1 = sim

} Pedido; // Estrutura para pedido

typedef struct {
    int idPedido;
    int idUsuario;
    int estrelas;

} Avaliacao; // Estrutura para avaliação

void cadastrarUsuario();
int loginUsuario();
void cadastrarPedido(int idUsuario);

#endif