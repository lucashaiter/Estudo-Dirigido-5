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
}address;


typedef struct NO{//Desculpa professor, mas doia muito no cora��o colocar o tamanho das strings como 100 e 50... colocamos n�meros que est�o na base 2 (2^7 e 2^6);
    //Dados obrigat�rios da atividade
    int id;
    char nome[128];
    char tipo;
    char usuario[64];
    char senha[64];
    address endereco;

    //vari�vel de verifica��o
    int isOnFile;

    //Ponteiro que aponta para o endere�o do pr�ximo n�.
    struct NO *proximo;
}no;


typedef struct{
    no *inicio;
    no *fim;
}lista;


/*------------------------------< Functions >------------------------------*/







/*------------------------------< Main >------------------------------*/
int main()
{
    setlocale(LC_ALL, "portuguese");

    


    system("pause");
    return 0;
}
