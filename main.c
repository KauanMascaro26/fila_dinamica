#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio, *fim;
} FilaDinamica;

FilaDinamica* criarFilaDinamica() {
    FilaDinamica *fila = (FilaDinamica*) malloc(sizeof(FilaDinamica));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

int filaVazia(FilaDinamica *fila) {
    return (fila->inicio == NULL);
}

void enfileirar(FilaDinamica *fila, int dado) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = dado;
        novoNo->prox = NULL;
        if (filaVazia(fila)) {
            fila->inicio = novoNo;
        } else {
            fila->fim->prox = novoNo;
        }
        fila->fim = novoNo;
        printf("Elemento %d enfileirado na fila.\n", dado);
    } else {
        printf("Erro: Não foi possível alocar memória para o novo elemento.\n");
    }
}

int desenfileirar(FilaDinamica *fila) {
    int elemento;

    if (filaVazia(fila)) {
        printf("Erro: Fila dinâmica vazia, não é possível desenfileirar.\n");
        return -1; 
    } else {
        No *temp = fila->inicio;
        elemento = temp->dado;
        fila->inicio = temp->prox;
        free(temp);
        if (fila->inicio == NULL) {
            fila->fim = NULL; 
        }
        return elemento;
    }
}

void imprimirFilaDinamica(FilaDinamica *fila) {
    printf("Fila Dinâmica: ");
    if (filaVazia(fila)) {
        printf("fila vazia\n");
    } else {
        No *atual = fila->inicio;
        while (atual != NULL) {
            printf("%d ", atual->dado);
            atual = atual->prox;
        }
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "portuguese");
    FilaDinamica *fila = criarFilaDinamica();
    int opcao, elemento;

    do {
        printf("\nOpções:\n");
        printf("1. Enfileirar elemento\n");
        printf("2. Desenfileirar elemento\n");
        printf("3. Imprimir fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser enfileirado: ");
                scanf("%d", &elemento);
                enfileirar(fila, elemento);
                break;
            case 2:
                elemento = desenfileirar(fila);
                if (elemento != -1) {
                    printf("Elemento desenfileirado: %d\n", elemento);
                }
                break;
            case 3:
                imprimirFilaDinamica(fila);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
