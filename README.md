# 🍔 food_order_system — Sistema de Pedidos em C

> Um projeto desenvolvido em **C** que simula uma plataforma de pedidos de comida semelhante ao **iFood**, totalmente operada via **terminal** e com **armazenamento em arquivos de texto**.

O sistema permite o **cadastro, login, criação de pedidos e avaliações** de forma simples e intuitiva, ideal para reforçar conceitos de **manipulação de arquivos, structs e modularização em C**.

---

## 🧠 Visão Geral

O **food_order_system** foi projetado como uma aplicação de linha de comando que gerencia usuários, alimentos e pedidos através de menus interativos.  
Cada interação gera registros persistentes em arquivos `.txt`, funcionando como um mini banco de dados.

---

## 🚀 Funcionalidades Principais

| Função | Descrição |
|--------|------------|
| 👤 **Cadastro de Usuário** | Cria um novo usuário e salva seus dados em `usuarios.txt`. |
| 🔐 **Login** | Autentica um usuário a partir de seu e-mail e senha. |
| 🍱 **Busca e adição de alimentos** | Permite procurar um alimento por nome e adicioná-lo à “sacola virtual”. |
| 🛒 **Gerenciamento de sacola** | O usuário pode visualizar e remover itens antes de confirmar o pedido. |
| 📦 **Confirmação do pedido** | Gera um novo pedido em `pedidos.txt` com todos os itens e o valor total. |
| ⭐ **Avaliação do pedido** | Após confirmar o pedido, o usuário pode atribuir uma nota de 1 a 5 estrelas. |
| 💾 **Armazenamento persistente** | Todos os dados são salvos e lidos de arquivos `.txt` dentro da pasta `data/`. |

---

## ⚙️ Principais Funções do Sistema

### 🔸 `cadastrarUsuario()`
- Cadastra um novo usuário solicitando **nome**, **e-mail** e **senha**.
- Gera um **ID aleatório** e armazena os dados em `usuarios.txt`.
- Utiliza `fprintf()` para salvar no formato:

---

### 🔸 `loginUsuario()`
- Solicita **e-mail** e **senha** e verifica se os dados estão corretos.
- Caso o login seja bem-sucedido, retorna o `idUsuario` para manter a sessão ativa.
- Faz a leitura do arquivo linha por linha com `fscanf()` e compara usando `strcmp()`.

---

### 🔸 `cadastrarPedido(int idUsuario)`
É o **núcleo do sistema**, responsável por todo o fluxo de pedidos.

1. Exibe um **menu interativo da sacola**:
 - Adicionar alimento
 - Remover alimento
 - Ver itens da sacola
 - Edita os itens da sacola
 - Confirmar pedido
2. Busca alimentos em `alimentos.txt` comparando nomes com `strcasecmp()`.
3. Armazena os itens da sacola em um array de `Alimento`.
4. Ao confirmar:
 - Gera um `Pedido` com IDs dos alimentos, valor total e estado de avaliação.
 - Salva o pedido em `pedidos.txt`.
 - Pergunta se o usuário deseja avaliar o pedido (1–5 estrelas).
 - Caso afirmativo, grava a avaliação em `avaliacoes.txt`.

---

## 🧩 Estrutura do Projeto

## 📁 projeto
- ├── main.c # Função principal e menu do sistema
- ├── funcoes.c # Implementação das funcionalidades principais
- ├── funcoes.h # Estruturas e protótipos das funções
- ├── data/
- │ ├── usuarios.txt # Banco de usuários
- │ ├── alimentos.txt # Catálogo de alimentos
- │ ├── pedidos.txt # Histórico de pedidos
- │ └── avaliacoes.txt # Avaliações registradas
