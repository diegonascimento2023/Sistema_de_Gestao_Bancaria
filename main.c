#include "agencia.c"

int main(void){

    Contabancaria * nome1 = criar_conta("joao", "15/09/2023", 1506.65, "ativo", 12711 );
    printf(" %s\n", nome1->cliente);
    printf(" %s\n", nome1->data);
    printf(" %.2f\n", nome1->saldo);
    printf(" %s\n", nome1->status);
    printf(" %d\n", nome1->numero);


  /*  
    
    
    int op;


do {
    printf("\n MENU DE OPÇÕES \n");
    printf(" 1 - Adicionar conta");
    printf(" 2 - Remover conta");
    printf(" 3 - Listar contas cadastradas");
    printf(" 4 - Buscar conta");
    printf(" 5 - Editar conta");
    printf(" 6 - Consultar contas ativas em uma dada agência");
    printf(" 7 - Consultar contas ativas em uma dada agência");
    printf(" 8 - Sair");

    if (scanf("%d", &op) != 1) // verifica se o que foi digitado é um inteiro
    {
        printf(" Invalido. Tente novamente");
        
    }


    switch (op)
    {
        case 1:
        break;

        case 2:
        break;

        case 3:
        break

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;

        case 7:
        break;

        case 8:

        printf("Sair!! ");

        break;

    default: 
    printf ("Tente novamente, opcao fornecida está invalida! \n");


    }
}while(op !=8);



*/

    return 0;
}