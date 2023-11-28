#include <stdio.h>
#define MAX 100

//definindo a estrutura dos produtos
typedef struct {
    int id;
    char nome[50];
    float preco;
    int quantidadeEstoque;
} Produto;

//solicita ao usuário que insira as informações de um novo produto e as armazena
// na próxima posição disponível do vetor produtos.
void adicionarProduto(Produto* produtos, int* totalProdutos) {
    printf("Digite o nome do produto: \n");
    scanf("%s", produtos[*totalProdutos].nome);

    printf("Digite o preco do produto: \n");
    scanf("%f", &produtos[*totalProdutos].preco);

    printf("Digite a quantidade em estoque: \n");
    scanf("%d", &produtos[*totalProdutos].quantidadeEstoque);

    produtos[*totalProdutos].id = *totalProdutos + 1;
    (*totalProdutos)++;

    printf("Produto adicionado com sucesso!\n");
}

//permite ao usuário alterar o preço de um produto específico, solicitando o ID do produto desejado.
void alterarPreco(Produto* produtos, int totalProdutos) {
    int id;
    printf("Digite o ID do produto que deseja alterar o preco: \n");
    scanf("%d", &id);

    if (id >= 1 && id <= totalProdutos) {
        printf("Digite o novo preco para o produto %s: \n", produtos[id - 1].nome);
        scanf("%f", &produtos[id - 1].preco);//[id - 1] usado para subtrair 1 do numero digitado pelo usuario
        printf("Preco alterado com sucesso!\n");
    } else {
        printf("ID de produto invalido.\n");
    }
}

//exibe uma tabela mostrando o estoque atual de todos os produtos.
void checarEstoque(Produto* produtos, int totalProdutos) {
    printf("Estoque:\n");
    printf("%-5s %-20s %-10s\n", "ID", "Nome", "Quantidade");
    for (int i = 0; i < totalProdutos; i++) {
        printf("%-5d %-20s %-10d\n", produtos[i].id, produtos[i].nome, produtos[i].quantidadeEstoque);
    }
}

//lista todos os produtos cadastrados no sistema, exibindo suas informações.
void listarProdutos(Produto* produtos, int totalProdutos) {
    printf("Produtos:\n");
    printf("%-5s %-20s %-10s\n", "ID", "Nome", "Preco");
    for (int i = 0; i < totalProdutos; i++) {
        printf("%-5d %-20s %-10.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
}

int main() {
    Produto produtos[MAX]; //vetor para a quantidade de produtos da struct
    int totalProdutos = 0; //contador para produtos
    int escolha; //variavel para armazenar a escolha do usuario

    do {
        printf("\n1. Adicionar Produto\n");
        printf("2. Alterar Preco\n");
        printf("3. Checar Estoque\n");
        printf("4. Listar Produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarProduto(produtos, &totalProdutos);
                break;
            case 2:
                alterarPreco(produtos, totalProdutos);
                break;
            case 3:
                checarEstoque(produtos, totalProdutos);
                break;
            case 4:
                listarProdutos(produtos, totalProdutos);
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}