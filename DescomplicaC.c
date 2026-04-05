#include <stdio.h>

int main(){
    int a,b;

    printf("Digite o primeiro inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo inteiro: ");
    scanf("%d", &b);

    if (&a>&b) {
        printf("Maior endereco: %p, conteudo: %d\n", (void*)&a, a);
    } else {
        printf("Maior endereco: %p, conteudo: %d\n", (void*)&b, b);
    }

    return 0;
}
