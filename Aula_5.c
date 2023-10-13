#include "stdio.h"
#define ex01

#ifdef ex01

/*1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)*/

char str1[11];
char str2[11];

int comparaString()
{

    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
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
        gets(str2);

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

/*2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3
                          */

char str1[8], str2[8], str3[8], str4[8], str5[8];

int main()
{
    char esc;
    do
    {
        printf("Digite 5 nomes (até 7 caracteres):\n");
        gets(&str1);
        gets(&str2);
        gets(&str3);
        gets(&str4);
        gets(&str5);

        printf("\n12345678901234567890123456789012345678901234567890\n");
        printf("  %-7s                                 %-7s\n", str1, str5);
        printf("            %-7s             %-7s\n", str2, str4);
        printf("                      %-7s", str3);

        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}

#endif

#ifdef ex03

/*3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
    calcula o comprimento de uma string recebida via teclado. Mostre o valor do
    comprimento na funcao main().
    (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)*/

char str[31];

int stringSize(int i)
{

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{

    char esc;
    do
    {
        int i = 1;
        printf("Digite uma String (ate 30 caracteres):");
        gets(&str);

        int retorno = stringSize(i);

        printf("A string tem %d caracteres.", retorno);
        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');

    return 0;
}

#endif

#ifdef ex4
int main()
{
    char esc;
    do
    {
        char str[10];

        printf("Digite uma string (max. 10 caracteres)\n");
        gets(&str[0]);

        for (int i = 0; str[i] != '\0'; i++)
        {
            int letra = 0;
            letra = str[i];
            if (letra >= 97 && letra <= 122)
            {
                letra -= 32;
            }
            str[i] = letra;
        }

        puts(str);

        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}
#endif

/*5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. (nao pode usar funcao de biblioteca)*/

#ifdef ex5
int main()
{
    char esc;
    do
    {
        char str[10];

        printf("Digite uma string (max. 10 caracteres)\n");
        gets(&str[0]);

        for (int i = 0; str[i] != '\0'; i++)
        {
            int letra = 0;
            letra = str[i];
            if (letra >= 'A' && letra <= 'Z')
            {
                letra += 32;
            }
            str[i] = letra;
        }

        puts(str);

        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}
#endif