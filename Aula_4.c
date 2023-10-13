#include "stdio.h"
#include "windows.h"

// se tiver que inicializar o vetor, ele e' STATIC

#define ex05
/*Todos os programas devem ser finalizados pelo usuario*/

#ifdef ex01
/*1 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
decomponha em dois outros vetores. Um tera� as componentes de ordem impar
e o outro tera� as componentes de ordem par.
Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/

int main()
{

    char ch;

    do
    {
        int vetor1[9];
        int vetor2[9];
        int vetor3[9];

        int cont1 = 0;
        int cont2 = 0;

        printf("Digite 10 numeros do primeiro vetor: ");
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", &vetor1[i]);
        }

        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
            {
                vetor2[cont1] = vetor1[i];
                cont1++;
            }
            else
            {
                vetor3[cont2] = vetor1[i];
                cont2++;
            }
        }

        printf("Vetor 1:\n");

        for (int i = 0; i < cont1; i++)
        {
            printf("%d|", vetor2[i]);
        }

        printf("\nVetor 2:\n");

        for (int i = 0; i < cont2; i++)
        {
            printf("%d|", vetor3[i]);
        }

        printf("\nDeseja encerrar o programa? (s) ou (n)");
        getchar(); // limpa buffer
        ch = getchar();
        if (ch == 'n')
        {
            system("cls");
        }

    } while (ch != 's' && 'S');
    return 0;
}

#endif

#ifdef ex02

/*2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera� as componentes de valor impar
    e o outro tera� as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. */

int main()
{

    char ch;

    do
    {
        int vetor1[9];
        int vetor2[9];
        int vetor3[9];

        int cont1 = 0;
        int cont2 = 0;

        printf("Digite 10 numeros do primeiro vetor: ");
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", &vetor1[i]);
        }

        for (int i = 0; i < 10; i++)
        {
            if (vetor1[i] % 2 == 0)
            {
                vetor2[cont1] = vetor1[i];
                cont1++;
            }
            else
            {
                vetor3[cont2] = vetor1[i];
                cont2++;
            }
        }

        printf("Vetor 1:\n");

        for (int i = 0; i < cont1; i++)
        {
            printf("%d|", vetor2[i]);
        }

        printf("\nVetor 2:\n");

        for (int i = 0; i < cont2; i++)
        {
            printf("%d|", vetor3[i]);
        }

        printf("\nDeseja encerrar o programa? (s) ou (n)");
        getchar(); // limpa buffer
        ch = getchar();
        if (ch == 'n')
        {
            system("cls");
        }

    } while (ch != 's' && 'S');
    return 0;
}

#endif

#ifdef ex03

/*3 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.*/

int main()
{
    char ch;
    do
    {
        int vetor1[2][3];
        int vetor2[2][3];
        int vetor3[2][3];

        printf("Digite o vetor1: (2 linhas e 3 colunas)");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &vetor1[i][j]);
            }
        }

        printf("Digite o vetor2: (2 linhas e 3 colunas)");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &vetor2[i][j]);
            }
        }

        printf("Vetor 1:");
        for (int i = 0; i < 2; i++)
        {
            printf("\n");
            for (int j = 0; j < 3; j++)
            {
                printf("%d|", vetor1[i][j]);
            }
        }

        printf("\nVetor 2:");
        for (int i = 0; i < 2; i++)
        {
            printf("\n");
            for (int j = 0; j < 3; j++)
            {
                printf("%d|", vetor2[i][j]);
            }
        }

        printf("\nVetor 3 (soma dos vetores): ");
        for (int i = 0; i < 2; i++)
        {
            printf("\n");
            for (int j = 0; j < 3; j++)
            {
                vetor3[i][j] = vetor1[i][j] + vetor2[i][j];
                printf("%d|", vetor3[i][j]);
            }
        }

        printf("\nDeseja encerrar o programa? (s) ou (n)");
        getchar(); // limpa buffer
        ch = getchar();
        if (ch == 'n')
        {
            system("cls");
        }

    } while (ch != 's' && ch != 'S');
    return 0;
}

#endif

#ifdef ex04

/*4 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.*/
// tem que ordenar na medida que eles entram (ex: valide o primeiro numero digitado em relacao a primeira pos, dps o segundo num e etc)

int main()
{
    int f[10], aux = 0;
    char esc;

    do
    {
        for (int i = 0; i < 10; i++)
        {
            printf("Digite um numero inteiro: ");
            scanf("%d", &f[i]);
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j < 10; j++)
            {
                if (f[i] > f[j])
                {
                    aux = f[i];
                    f[i] = f[j];
                    f[j] = aux;
                }
            }
        }

        printf("O vetor ordenado e': ");
        printf(" %d %d %d %d %d %d %d %d %d %d", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]);

        printf("\nDeseja encerrar o programa?\t(s/n)");
        getchar();
        scanf("%c", &esc);
        system("cls");
    } while (esc != 's');

    return 0;
}

#endif

#ifdef ex05

/*5 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double*/

int main()
{

    int vetI[3];
    long vetL[3];
    unsigned vetU[3];
    float vetF[3];
    double vetD[3];
    char ch;
    do
    {
        printf("Digite 3 inteiros: ");
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &vetI[i]);
        }

        printf("Digite 3 longs: ");
        for (int i = 0; i < 3; i++)
        {
            scanf("%ld", &vetL[i]);
        }
        printf("Digite 3 unsigneds: ");
        for (int i = 0; i < 3; i++)
        {
            scanf("%u", &vetU[i]);
        }
        printf("Digite 3 floats: ");
        for (int i = 0; i < 3; i++)
        {
            scanf("%f", &vetF[i]);
        }
        printf("Digite 3 doubles: ");
        for (int i = 0; i < 3; i++)
        {
            scanf("%lf", &vetD[i]);
        }

        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");
        for (int i = 0; i < 3; i++)
        {
            printf("  %-11d         %-11ld         %-10u\n", vetI[i], vetL[i], vetU[i]);
            printf("            %-8.1e        %-9.1e\n", vetF[i], vetD[i]);
        }
        printf("\nDeseja encerrar o programa?\t(s/n)");
        getchar();
        scanf("%c", &ch);
        system("cls");
    } while (ch != 's' && 'S');
    return 0;
}

#endif