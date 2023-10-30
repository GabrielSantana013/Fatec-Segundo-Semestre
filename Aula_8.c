#include "stdio.h"
#define ex02

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

        if(*pStr1 != *pStr2)
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

char key[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

int buscaLetra(char *pLetra){

    char *pKey;
    pKey = &key[0];

    for(int i = 0; *pKey != '\0'; i++, pKey++)
    {   
        if(*pLetra == *pKey)
        {
            return 1;    
        }
    }

    return 0;
}

int main(){

    char letra;
    char *pLetra;

    pLetra = &letra;

    printf("Digite uma letra: \n");
    scanf("%c", pLetra);
    int retorno = buscaLetra(pLetra);

    retorno == 1 ? printf("Letra encontrada!") : printf("Letra nao encontrada!");
    //condicao ? valor se verdadeiro : valor se falso

    return 0;
}

#endif

#ifdef ex03

int main(){


    return 0;
}

#endif

#ifdef ex04

int main(){


    return 0;
}

#endif

#ifdef ex05

int main(){


    return 0;
}

#endif

#ifdef ex06

int main(){


    return 0;
}

#endif