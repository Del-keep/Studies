#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[30];
    struct no *proximo;
}No;  //estrutura da cel

void adc(No **lista, char nm){
    No *novo=malloc(sizeof(No)); //aloc

    if(novo){
        strcpy(novo->nome, nm);  //nome na lista e prossegue
        novo->proximo=*lista;
        *lista=novo; 
    }else{
        printf("erro de alocacao");
    }
}
    
void rem(No **lista, char *nm){
    No *atual=*lista;
    No *anterior=NULL;

    while (atual && strcmp(atual->nome,nm)){
        anterior=atual;
        atual=atual ->proximo;
    }

    if(atual){
        if (anterior){
            anterior->proximo=atual->proximo;
        } else {
            *lista=atual->proximo;
        }
        free(atual);
        printf("nome removido.\n");
    }else{
        printf("nome nao encontrado.\n");
    }
}

void list(No *no){
    printf("\nLista: ");
    while (no){
        printf("%s\n", no->nome);
        no=no->proximo;
    }
    printf("\n");
}

int main(){
    int opcao, nome;
    No *lista=NULL;
   
    do{
        printf ("1)Adicionar nome\n2)Remover nome\n3)Listar\n4)Sair\nOpcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
        case 1:
            printf("Digite o nome pra adc: ");
            fgets(nome,sizeof(nome),stdin);
            nome[strcspn(nome,"\n")]='\0';
            adc(&lista, nome);
            break;
        case 2:
            printf("Digite o nome pra remv:");
            fgets(nome,sizeof(nome),stdin);
            nome[strcspn(nome,"\n")]='\0';
            rem(&lista,nome);
            break;
        case 3:
            list(lista);
            break;
        case 4:
            printf("Encerrando o programa....");
            break;
        default:
            printf("Opcao invalida.");
        }
    }while (opcao!=4);
    return 0;
}