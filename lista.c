#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sec{
    int cpf;
    char *senha;
    char *nomedosec;
    struct sec *prox;
    struct sec *ant;
}secretario;

typedef struct trans{//nao ta sendo reconhecido
    int cpf_t;
    char *senha_t;
    char *nome_t;
    struct trans *prox_t;
    struct trans *ant_t;
}transportador;

secretario *inicio = NULL;
secretario *fim = NULL;
int tam = 0;
transportador *inicio_t = NULL;
transportador *fim_t = NULL;
int tam_t = 0;

void cadastrar_secretario(int cpf, char *senha, char *nomedosec){
    
    secretario *novo_sec = malloc(sizeof(secretario));
    novo_sec->cpf = cpf;
    novo_sec->senha = senha;
    novo_sec->nomedosec = nomedosec;
    novo_sec->prox = NULL;
    novo_sec->ant = NULL;

    if(inicio == NULL){
        inicio = novo_sec;
        fim = novo_sec;
    }else{
        fim->prox = novo_sec;
        novo_sec->ant = fim;
        fim = novo_sec;
    }
    tam++;
}

void cadastrar_transportador(int cpf_t, char *senha_t, char *nome_t){
    transportador *novo_t = malloc(sizeof(transportador));
    novo_t->cpf_t = cpf_t;
    novo_t->senha_t = senha_t;
    novo_t->nome_t = nome_t;
    novo_t->prox_t = NULL;
    novo_t->ant_t = NULL;

    if(inicio == NULL){
        inicio_t = novo_t;
        fim_t = novo_t;
    }else{
        fim_t->prox_t = novo_t;
        novo_t->ant_t = fim_t;
        fim_t = novo_t;
    }
    tam_t++;
}

void cadastrar(){
    int opcao;
    int cpf;
    char *senha;
    char *nome;

    printf("\n--------------------- Para realizar o cadastro, digite o numero referente ao seu cargo ---------------------\n");
    printf("1 - Secretario \n");
    printf("2 - Trasportador \n");
    scanf("%d", &opcao);  

    printf("Digite o nome: \n");
    scanf("%s", nome);
    printf("Digite o CPF: \n");
    scanf("%d",&cpf);
    printf("Digite a senha: \n");
    scanf("%s", senha);
    
    if(opcao == 1){
        cadastrar_secretario(cpf, senha, nome);
        printf("Secretario cadastrado com sucesso!");
    }else if(opcao == 2){
        cadastrar_transportador(cpf, senha, nome);
        printf("Transportador cadastrado com sucesso!");
    }else{
        printf("Opcao invalida!");
    }
}

void dados(){ //nao entendi a utilidade de imprimir os dados dele
    secretario * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("CPF: %d\nSenha: %s\nNome: %s\n", aux->cpf, aux->senha, aux->nomedosec);
        aux = aux->prox;
    }

    transportador * aux2 = inicio_t;
    for(int i = 0; i < tam_t; i++){
        printf("CPF: %d\nSenha: %s\nNome: %s\n", aux2->cpf_t, aux2->senha_t, aux2->nome_t);
        aux2 = aux2->prox_t;
    }
}

int login(){

    int cpf;
    char *senha;

    int cpf_t;
    char *senha_t;
    int opcao;

    secretario *aux = inicio;
    transportador *aux2 = inicio_t;

    printf("\n--------------------- Para realizar o login, digite o numero referente ao seu cargo ---------------------\n");
    printf("1 - Secretario \n");
    printf("2 - Trasportador \n");
    scanf("%d", &opcao);

    if(opcao == 1){
        printf("Digite seu CPF: \n");
        scanf("%d",&cpf);
        printf("Digite sua senha: \n");
        scanf("%s", senha);
        for(int i=0; i < tam; i++){
            if(aux->cpf == cpf && aux->senha == senha){
                    printf("\nBem vindo %s\n", aux->nomedosec);
            }
            aux = aux->prox;
        }
    }else if(opcao == 2){
        printf("Digite seu CPF: \n");
        scanf("%d",&cpf_t);
        printf("Digite sua senha: \n");
        scanf("%s", senha_t);
        for(int i=0; i < tam; i++){
            if(aux2->cpf_t == cpf_t && aux2->senha_t == senha_t){
                    printf("\nBem vindo %s\n", aux2->nome_t);
            }
            aux2 = aux2->prox_t;
        }
    }else if(opcao == 1 || opcao == 2){
        for(int i=0; i < tam; i++){
            if(aux->cpf != cpf || aux->senha != senha || aux2->cpf_t != cpf_t && aux2->senha_t != senha_t){
                printf("\nCPF ou senha incorreto! Tente novamente. %s\n");
            }
        }    
    }
    return 0;
}

int encomendar(){

    int cpf;
    char *senha;
    char *encomenda;
    secretario *aux = inicio;

    printf("\n--------------------- Para realizar uma encomenda, confirme a CPF e senha do secretario: ---------------------\n");
    printf("Digite seu CPF: \n");
    scanf("%d",&cpf);
    printf("Digite sua senha: \n");
    scanf("%*c", senha);
    
    for(int i = 0; i < tam; i++){
        if(aux->cpf == cpf && aux->senha == senha){
            printf("\nBem vindo %s\n", aux->nomedosec);
            printf("\nDigite as informacoes da encomenda: \n");
            scanf("%d", encomenda);
        }else{
            printf("\nCPF ou senha incorreto! Tente novamente.\n");
        }
        aux = aux->prox;
    }
    return 0;
}

void remover(){

    login();//chamar login para o pedido de remocao

}

int main(){

    
    int x = 1;
    int menu;
    while(x==1){
        printf("\n--------------------------- SISTEMA DE ENCOMENDA DE LIVRO ---------------------------\n");
        printf("\nPara cadastrar um seretario ou um transportador, digite: 1"); //funcao que possa continuar cadastrando loop, no caso retornar menu
        printf("\nPara encomendar um livro , digite: 2");
        printf("\nPara remover um pedido ou uma encomenda, digite: 3");
        printf("\nPara fechar o programa, digite: 4");
        printf("\n------------------------------------------------------------------\n");
        scanf("%d", &menu);

        switch(menu){
            case 1: cadastrar(); break; 
            case 2: encomendar(); break; 
            case 3: remover(); break;
            case 4: x = 0; break; 
        }   
    }
    cadastrar_secretario(58555, "senha1", "Luis");
    cadastrar_secretario(56789, "senha2", "Mariana");
    cadastrar_secretario(98755, "senha3", "Ester");
    cadastrar_transportador(2222, "senha4", "Jose");
    cadastrar_transportador(5555, "senha5", "Joana");
    cadastrar_transportador(7777, "senha6", "Leonardo");
    cadastrar_transportador(1111, "senha7", "Wanderson");
    cadastrar_transportador(33232, "senha8", "Pedro");
    //dados();
    
}
