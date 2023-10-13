#include "stdio.h"
#include "windows.h"
#define ex05


#ifdef ex01
/*
1 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.
*/

int main()
{
    int seg;
    int min = 0;
    int hora = 0;
    char escolha;

    do{
        printf("===EXERCICIO 1===\n");
        printf("Digite os segundos: ");
        scanf("%d", &seg);

        while(seg>=60)
        {

            if(seg>=60)
            {
                seg -=60;
                min++;
            }

            if(min>=60)
            {
                min -=60;
                hora++;
            }

        }

        printf("%dh %dm %ds", hora, min, seg);
        seg = min = hora = 0;

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }while(escolha != 'n' && escolha != 'N');

    return 0;
}
#endif

#ifdef ex02
/*
2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char
*/

int main()
{
    short n1;
    long n2;
    int n3;
    float n4;
    double n5;
    char ch, escolha;

    do
    {
        printf("===EXERCICIOS 2===\n");

        printf("Digite uma variavel do tipo short: \n");
        scanf("%hd", &n1);
        printf("Digite uma variavel do tipo long: \n");
        scanf("%ld", &n2);
        printf("Digite uma variavel do tipo int: \n");
        scanf("%d", &n3);
        printf("Digite uma variavel do tipo float: \n");
        scanf("%f", &n4);
        printf("Digite uma variavel do tipo double: \n");
        scanf("%lf", &n5);
        printf("Digite uma variavel do tipo char: \n");
        scanf(" %c",&ch);


        /*          10        20        30        40        50        60
             12345678901234567890123456789012345678901234567890123456789012345
                 short               long                int
                           float               double              char
        */



        printf("=========================================\n");
        printf("       10        20        30        40        50        60     \n");
        printf("12345678901234567890123456789012345678901234567890123456789012345\n");
        printf("    %-6hd              %-11ld         %-11d\n", n1, n2, n3);
        printf("              %-8.1e            %-9.1e           %-1c\n", n4, n5, ch);

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }
    while(escolha != 'n' && escolha != 'N');

    return 0;
}

#endif


#ifdef ex03
/*
3 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar.
*/

int main()
{

    int n1;
    int n2;
    char escolha;

    do
    {
        printf("===EXERCICIO 3===\n");
        printf("Digite o primeiro numero: ");
        scanf("%d", &n1);
        printf("Digite o segundo numero: ");
        scanf("%d", &n2);

        printf("Antes de permutar:n1=%d n2=%d\n", n1, n2);
        printf("%d||%d\n",n1,n2);

        /*n1 = n1 ^ n2;
        n2 = n1 ^ n2;
        n1 = n1 ^ n2; jeito 1 */

        n1 = n1+n2;
        n2 = n1-n2;
        n1 = n1-n2;
//jeito 2

        printf("Depois de permutar:\n");
        printf("%d||%d",n1,n2);
        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }
    while(escolha != 'n' && escolha != 'N');

    return 0;
}

#endif

#ifdef ex04
/*
4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
    outro número formado pelos dígitos invertidos do número lido.
    Ex:   NúmeroLido = 123
        NúmeroGerado = 321
*/

int main()
{
    int n1;
    char escolha;

    do
    {
        printf("===EXERCICIO 4===\n");
        printf("Digite um numero de 3 algarismos: ");
        scanf("%d", &n1);
        printf("Numero digitado: %d\n", n1);

        int cent = n1/100;
        int dez = (n1 - cent * 100) / 10;
        int uni = (n1 - (cent * 100 + dez * 10));

        cent = cent^uni;
        uni = cent^uni;
        cent = cent^uni;

        n1 = (cent*100 + dez*10 + uni);
        printf("Numero Invertido: %d", n1);

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }while(escolha != 'n' && escolha != 'N');

    return 0;
}

#endif

#ifdef ex05
/*
5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.
*/

int main()
{

    int n1;
    int limite;
    int menorMultiplo = 0;
    char escolha;

    do
    {
        printf("===EXERCICIO 5===\n");
        printf("Digite seu numero inteiro: \n");
        scanf("%d", &n1);
        printf("Digite o limite: \n");
        scanf("%d", &limite);

        for (int i = 1; limite > menorMultiplo; i++)
        {
            menorMultiplo = n1 * i;
        }

        printf("Menor multiplo de %d maior que %d: %d", n1, limite, menorMultiplo);
        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }while(escolha != 'n' && escolha != 'N');

    return 0;
}
#endif
