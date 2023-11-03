#include "stdio.h"
#define ex01

#ifdef ex01

/*1 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().
*/

void recebeString(char *pStr1, char *pStr2)
{

    printf("Digite uma string:");
    gets(pStr1);
    printf("Digite outra string:");
    gets(pStr2);

}

int comparaString(char *pStr1, char *pStr2)
{
   
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
    char esc, str1[11], str2[11], *pStr1, *pStr2;
    pStr1 = & str1[0];
    pStr2 = & str2[0];
    do
    {
        recebeString(pStr1, pStr2);
        int retorno = comparaString(pStr1,pStr2);

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
2 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().
*/

int main()
{
}

#endif

#ifdef ex03

/*
3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

int main()
{
}

#endif

#ifdef ex04

/*
4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/

int main()
{
}

#endif

#ifdef ex05

/*
5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep
*/

int main()
{
}

#endif

#ifdef ex06

/*
6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.
*/

int main()
{
}

#endif