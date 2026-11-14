#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int restos[32];
int binarios[32];
int quant_restos = 0;

float operacao1(int n){

    if (n == 0) {
        restos[0] = 0;
        quant_restos = 1;
        return 0;
    }

    quant_restos = 0;
     while (n > 0) { 
        restos[quant_restos] = n % 2;
        n = n / 2;
        quant_restos++;
    }
    
}

int operacao2(float n){
    for (int i = 0; i < 4; i++) {
        binarios[i] = 0;
    }
    for (int i = 0; i < 4; i++)
    {
        n = n * 2;
        if (n >= 1.0f) {
            binarios[i] = 1;
            n -= 1.0f; // Remove a parte inteira
        } else {
            binarios[i] = 0;
        }
    }
    
}

int main()
{
    char escolha;
    char cont = 's';
    do
    {

        printf("Escolha o tipo de numero a ser convertido (i para inteiro e f para fracionário):");
        scanf(" %c", &escolha);

        if (escolha == 'i')
        {
            int decimal = 0;
            printf("Digite o decimal: ");
            scanf("%d", &decimal);
            operacao1(decimal);
            for (int i = quant_restos - 1; i >= 0; i--) {
                printf("%d", restos[i]);
            }

        }

        else if(escolha == 'f')
        {
            int decimalParte1 = 0;
            float decimalParte2 = 0;
            printf("Primeira parte do decimal(parte antes da virgula): ");
            scanf("%d", &decimalParte1);
            printf("Segunda parte do decimal(parte depois da virgula): ");
            scanf("%f", &decimalParte2);

            operacao1(decimalParte1);
            operacao2(decimalParte2);

            printf("Resultado em binario: ");

            for (int i = quant_restos - 1; i >= 0; i--) {
                printf("%d", restos[i]);
            }

            printf(".");

            for (int i = 0; i < 4; i++) {
                printf("%d", binarios[i]);
            }
        }


        else{
            printf("escolha invalida\n");
        }

        printf("\n");
        printf("Continue ? ");
        scanf(" %c", &cont);
    } while (cont == 's' || cont == 'S');

    printf("Bye Bye");

    return 0;
}
