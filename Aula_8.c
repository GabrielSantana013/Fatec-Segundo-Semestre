#include "stdio.h"
#define ex03

#ifdef ex01

/*
1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global
    */

char str1[11];
char str2[11];

int comparaString()
{
    char *pStr1, *pStr2;
    pStr1 = &str1[0];
    pStr2 = &str2[0];

    for (int i = 0; *pStr1 != '\0' && *pStr2 != '\0'; i++)
    {
        pStr1++;
        pStr2++;

        if (*pStr1 != *pStr2)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char esc;
    do
    {
        printf("Digite uma string:");
        gets(&str1);
        printf("Digite outra string:");
        gets(&str2);

        int retorno = comparaString();

        if (retorno == 1)
        {
            printf("As string são iguais");
        }
        else
        {
            printf("As string são diferentes");
        }

        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}

#endif

#ifdef ex02

/*
2 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

char key[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};

int buscaLetra(char *pLetra)
{

    char *pKey;
    pKey = &key[0];

    for (int i = 0; *pKey != '\0'; i++, pKey++)
    {
        if (*pLetra == *pKey)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{

    char letra;
    char *pLetra;

    pLetra = &letra;

    printf("Digite uma letra: \n");
    scanf("%c", pLetra);
    int retorno = buscaLetra(pLetra);

    retorno == 1 ? printf("Letra encontrada!") : printf("Letra nao encontrada!");
    // condicao ? valor se verdadeiro : valor se falso

    return 0;
}

#endif

#ifdef ex03

/*
3 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/

int main()
{

    int n1, *pn1;
    long n2, *pn2;
    unsigned n3, *pn3;
    float n4, *pn4;
    double n5, *pn5;
    char n6, *pn6, ch;
    unsigned long n7, *pn7;
    unsigned char n8, *pn8;

        pn1 = &n1;
        pn2 = &n2;
        pn3 = &n3;
        pn4 = &n4;
        pn5 = &n5;
        pn6 = &n6;
        pn7 = &n7;
        pn8 = &n8;

    do
    {
        printf("\nDigite um int:");
        scanf("%d", pn1);
        printf("\nDigite um long:");
        scanf("%ld", pn2);
        printf("\nDigite um unsigned int:");
        scanf("%u", pn3);
        printf("\nDigite um float:");
        scanf("%f", pn4);
        printf("\nDigite um double:");
        scanf("%lf", pn5);
        setbuf(stdin, NULL);
        printf("\nDigite um char:");
        scanf("%c", pn6);
        getchar();
        printf("\nDigite um unsigned long:");
        scanf("%lu", pn7);
        setbuf(stdin, NULL);
        printf("\nDigite um unsigned char:");
        scanf("%c", pn8);
        getchar();


        printf("\n123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %-8d            %-11ld         %-8d \n", *pn1, *pn2, *pn3);
        printf("              %-8.1f            %.2f                %-1c\n", *pn4, *pn5, *pn6);
        printf("         %-11lu                   %-1c\n", *pn7, *pn8);

        /*          10        20        30        40        50        60
        123456789012345678901234567890123456789012345678901234567890
            int                 long                unsigned
                      float               double              char
                 unsigned long       unsigned char
        */
        printf("Deseja encerrar o programa? (s/n):");
        ch = getchar();
        setbuf(stdin, NULL);

    } while (ch != 's' && ch != 'S');
    return 0;
}

#endif

#ifdef ex04

/*4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
*/

int main()
{

    return 0;
}

#endif

#ifdef ex05

int main()
{

    return 0;
}

#endif

#ifdef ex06

int main()
{

    return 0;
}

#endif