#include "agencia.c"

int main(){
/*
    Contabancaria * nome1 = criar_conta("joao", "15/09/2023", 1506.65, "ativo", 12711 );
    printf(" %s\n", nome1->cliente);
    printf(" %s\n", nome1->data);
    printf(" %.2f\n", nome1->saldo);
    printf(" %s\n", nome1->status);
    printf(" %d\n", nome1->numero);

    Agenciabancaria * agencia = criar_agencia("Banco", 1134, "São Bento", "09:30 ate 15:00" );
    printf(" %s\n", agencia->nome);
    printf(" %d\n", agencia->codigo);
    printf(" %s\n", agencia->localizacao);
    printf(" %s\n", agencia->horario);

    agencia = cadastrar_cliente (nome1, agencia);
    printf(" %s\n", agencia->contas->conta->cliente);
   
*/
   
    
    int qntagencias = 0; // funcao para quantidade de agencias inicar em 0
    char opcao; //  switch case
    char nome[51], localizacao[51], horario[15]; // arrays para agencia
    int numero;
    int i;
    int qntcontas = 0; // funcao para quantidade de contas
    int j;
    Agenciabancaria **agencias = NULL;
    agencias = ler_arquivo(agencias, &qntagencias); // carregar dados salvos em um arquivo

do {

    printf("\n MENU DE OPCOES \n");
    printf(" 1 - Criar agencia bancaria \n");
    printf(" 2 - Cadastrar conta \n");
    printf(" 3 - Remover conta \n");
    printf(" 4 - Listar contas cadastradas \n");
    printf(" 5 - Buscar conta \n");
    printf(" 6 - Editar conta \n");
    printf(" 7 - Consultar contas ativas em uma dada agencia \n");
    printf(" 8 - Mostra a quantidade de agencias cadastrada \n");
    printf(" 9 - Sair \n");
    opcao = le_opcao ('1', '9');

    switch (opcao)
    {
    case '1':
        // criar agencia bancaria 
        printf("Informe o nome da agencia: ");
        scanf(" %[^\n]", nome);
        printf("Informe o codigo da agencia: ");
        scanf(" %d", &numero);
        printf("Informe a localização da agencia: ");
        scanf(" %[^\n]", localizacao);
        printf("Informe o horario de funcionamento da agencia: ");
        scanf(" %[^\n]", horario);

        agencias = realloc(agencias, (qntagencias+1)*sizeof(Agenciabancaria));
        agencias[qntagencias] = criar_agencia(nome, numero, localizacao, horario);
        qntagencias++;
        salva_arquivo(agencias, qntagencias);
        break;

    case '2':
        // Cadastrar cliente

        printf("Informe qual agencia deseja cadastrar o cliente");
        scanf (" %d", &numero);

        for(i=0; i<=qntagencias; i++){
            if(agencias[i]->codigo == numero){
                break;
            }
        }
        if( i> qntagencias){
            printf("Agencia nao existe");
        }else{
            agencias[i] = cadastrar_conta(agencias[i]);
            salva_arquivo(agencias, qntagencias);
        }
      
        
        break;
        
    case '3':
        // remover conta

        printf ("Informe o numero da conta que deseja remover \n");
        scanf(" %d", &numero);
        printf("Informe o codigo da agencia que a conta está registrada \n");
        scanf(" %d", &j);
        for(i= 0; i<qntagencias; i++){
            if(agencias[i]->codigo ==j){
                break;
            }
        }if(i == qntagencias){
            printf("Agencia nao localizada");
        }else{
            agencias[i] = remove_conta(agencias[i], numero);
            salva_arquivo(agencias, qntagencias);
            printf("Conta removida");
        }
        break;

    case '4':
        //listar agencias 
        listar_agencias(agencias, qntagencias);
        break;

        
    case '5':
    // buscar conta
    printf("Informe o numero da conta que deseja buscar: ");
    scanf(" %d", &numero);
    printf("Informe o codigo da agencia em que deseja buscar a conta: ");
    scanf(" %d", &j);
    for (i =0; i< qntagencias; i++){
        if (agencias[i]->codigo ==j){
            Contabancaria *contaencontrada = buscar_conta(agencias[i]->contas, numero);
            if(contaencontrada != NULL){
                printf(" \nInformacoes da conta: \n");
                printf("Nome da conta: %s\n", contaencontrada->cliente);
                printf("Numero da conta: %d\n", contaencontrada->numero);
                printf("Saldo: %.2f\n", contaencontrada->saldo);

            }else{
                printf("Conta nao localizada na agencia informada %d\n", j);

            }
            break;
        }
    }if(i == qntagencias){
                printf("Agencia nao localizada \n");
    }
        break;
        
    case '6':
    // modificar
        printf("Informe o numero da conta que deseja fazer alguma modificacao \n");
        scanf(" %d", &numero);
        printf("Informe o codigo da agencia em que deseja modifcar a conta \n");
        scanf(" %d", &j);
        for(i = 0; i < qntagencias; i++){
            if (agencias[i]->codigo == j){
                Contabancaria *contaeditar = buscar_conta(agencias[i]->contas, numero);
                if(contaeditar !=NULL){
                    printf("\n Informacoes da conta antes da edicao: \n");
                    printf("Cliente: %s\n", contaeditar->cliente);
                    printf("Numero: %d\n", contaeditar->numero);
                    printf("Saldo: %.2f\n", contaeditar->saldo);
                    printf("Status: %s\n", contaeditar->status);

                    editar_conta(contaeditar);

                    printf("\n Informacoes da conta depois da edicao: \n");
                    printf("Cliente: %s\n", contaeditar->cliente);
                    printf("Numero: %d\n", contaeditar->numero);
                    printf("Saldo: %.2f\n", contaeditar->saldo);
                    printf("Status: %s\n", contaeditar->status);

                    salva_arquivo(agencias, qntagencias);
                }
                else{
                    printf("Conta nao localizada na agencia %d\n", j);
                }
                break;
            }
        }
        if (i == qntagencias){
            printf("Agencia nao localizada \n");
        }
        salva_arquivo(agencias, qntagencias);
        break;
        
    case '7':

    //consultar contas ativas
    printf ("Informe o codigo da agencia da qual deseja consultar as contas ativas \n");
    scanf(" %d", &j);
    for (i = 0; i < qntagencias; i++){
        if(agencias[i]->codigo == j){
            listar_contas_ativas(agencias[i]->contas, j);
            break;
        }
    }
    if(i ==qntagencias){
        printf("Agencia nao localizada \n");
    }
        break;
    case '8':
        // informa a quantidade de agencias que está cadastrada
        printf("Quantidade de agencias cadastrada e de: %d", qntagencias);
        break;

    case '9':

        printf("Sair!! ");
        break;

    default: 
    printf ("Tente novamente, opcao fornecida está invalida! \n");


    }
}while(opcao != '9');
liberar_agencias(agencias, qntagencias); //funcao para liberar a memoria alocada para agencias bancarias
    return 0;
}