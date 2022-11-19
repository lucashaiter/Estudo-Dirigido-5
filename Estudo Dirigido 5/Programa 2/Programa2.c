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
    // Dados obrigat�rios da atividade
    int id;
    char nome[128];
    char usuario[64];
    char senha[64];
    char tipo;
    address endereco;
} user;


// Estrutura de n� (node).
typedef struct NODE{ // Desculpa professor, mas doia muito no cora��o colocar o tamanho das strings como 100 e 50... colocamos n�meros que est�o na base 2 (2^7 e 2^6).
    // Estrutura do usu�rio
    user UserNode;

    // vari�vel para verificar se o n� est� ou n�o no arquivo criado pelo programa.
    int isOnFile;

    // Ponteiro que aponta para o endere�o do pr�ximo n�.
    struct NODE *proximo;
} node;

// Estrutura de lista.
typedef struct{
    node *inicio;
    node *fim;
} list;



/*------------------------------< Functions >------------------------------*/
// Fun��o est�tica.
void proxTela(){
    printf("\n\n");
    system("pause");
    system("cls");
}



list *CreateList(){
    // Declara uma lista vazia din�micamente.
    list *lista = (list *)malloc(sizeof(list));

    // Verifica se a lista foi realmente criada.
    if (lista == NULL){ // Caso haja erro, filaizar� o programa.
        printf("\nErro ao alocar mem�ria para a lista.\n");

        exit(1);
    }else{ // Caso n�o haja erro, o programa inicializa os elementos da lista como NULL (indica lista vazia).
        lista->inicio = NULL;
        lista->fim = NULL;

        return lista;
    }
}



void addUser(list *lista, user usuarioNode){
    //cria o node da lista din�mincamente.
    node *NewUser = (node*)malloc(sizeof(node));

    //Verifica se o n� foi criado com �xito.
    if(NewUser == NULL){
        printf("\nErro ao adicionar novo usu�rio.\n");
        proxTela();
        exit(1);  //finaliza o programa retornando c�digo de erro 1.
    }else{
        // Inserindo elemento no inicio da lista.
        NewUser->UserNode = usuarioNode;
        NewUser->proximo = lista->inicio;

        // Verificando se a lista est� vazia.
        if(lista->inicio == NULL){ // Caso esteja, o primeiro elemento tamb�m ser� o �ltimo.
            lista->fim = NewUser;
        }
        lista->inicio = NewUser;
    }
}


// Imprimer lista (para debug).
void printList(list *lista){
    for(node *I = lista->inicio; I!=NULL; I = I->proximo){
        printf(
        "ID: %d\nNome: %sUsu�rio: %sTipo: %s\nEndere�o:\nRua %s, bairro %s, n�mero %d, cep %d\n\n", 
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

    //Criando a lista e uma vari�vel aux�liar de "resposta".
    list *Lista = CreateList();
    user UserAdd;


    system("pause");
    return 0;
}
