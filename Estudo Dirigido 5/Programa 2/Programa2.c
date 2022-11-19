#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*
O=======================================================================O
| Estudo dirigido 5 - Programa 2 - Sistema de login com Lista encadeada |
|    Nomes:                                                             |
|        Matheus Camargo Ginebro CP3016153                              |
|        Lucas Haiter Leoni CP3017362                                   |
O=======================================================================O
*/

/*------------------------------< Structs >------------------------------*/
typedef struct{
    char rua[128];
    char bairro[128];
    int numero;
    int cep;
} address;


typedef struct{
    // Dados obrigatórios da atividade
    int id;
    char nome[128];
    char usuario[64];
    char senha[64];
    char tipo;
    address endereco;
} user;


// Estrutura de nó (node).
typedef struct NODE{ // Desculpa professor, mas doia muito no coração colocar o tamanho das strings como 100 e 50... colocamos números que estão na base 2 (2^7 e 2^6).
    // Estrutura do usuário
    user UserNode;

    // variável para verificar se o nó está ou não no arquivo criado pelo programa.
    int isOnFile;

    // Ponteiro que aponta para o endereço do próximo nó.
    struct NODE *proximo;
} node;

// Estrutura de lista.
typedef struct{
    node *inicio;
    node *fim;
} list;



/*------------------------------< Functions >------------------------------*/
// Função estética.
void proxTela(){
    printf("\n\n");
    system("pause");
    system("cls");
}



list *CreateList(){
    // Declara uma lista vazia dinâmicamente.
    list *lista = (list *)malloc(sizeof(list));

    // Verifica se a lista foi realmente criada.
    if (lista == NULL){ // Caso haja erro, filaizará o programa.
        printf("\nErro ao alocar memória para a lista.\n");

        exit(1);
    }else{ // Caso não haja erro, o programa inicializa os elementos da lista como NULL (indica lista vazia).
        lista->inicio = NULL;
        lista->fim = NULL;

        return lista;
    }
}



void addUser(list *lista, user usuarioNode){
    //cria o node da lista dinâmincamente.
    node *NewUser = (node*)malloc(sizeof(node));

    //Verifica se o nó foi criado com êxito.
    if(NewUser == NULL){
        printf("\nErro ao adicionar novo usuário.\n");
        proxTela();
        exit(1);  //finaliza o programa retornando código de erro 1.
    }else{
        // Inserindo elemento no inicio da lista.
        NewUser->UserNode = usuarioNode;
        NewUser->proximo = lista->inicio;

        // Verificando se a lista está vazia.
        if(lista->inicio == NULL){ // Caso esteja, o primeiro elemento também será o último.
            lista->fim = NewUser;
        }
        lista->inicio = NewUser;
    }
}


// Imprimer lista (para debug).
void printList(list *lista){
    for(node *I = lista->inicio; I!=NULL; I = I->proximo){
        printf(
        "ID: %d\nNome: %sUsuário: %sTipo: %s\nEndereço:\nRua %s, bairro %s, número %d, cep %d\n\n", 
        I->UserNode.id, 
        I->UserNode.nome, 
        I->UserNode.usuario, 
        I->UserNode.tipo, 
        I->UserNode.endereco.rua, 
        I->UserNode.endereco.bairro, 
        I->UserNode.endereco.numero, 
        I->UserNode.endereco.cep);
    }
}



/*------------------------------< Main >------------------------------*/
int main(){
    setlocale(LC_ALL, "portuguese");

    //Criando a lista e uma variável auxíliar de "resposta".
    list *Lista = CreateList();
    user UserAdd;


    system("pause");
    return 0;
}
