#include "stdio.h"
#define ex05

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
    int n1, *pn1, soma = 0, *psoma, i = 0;
    pn1 = &n1;
    psoma = &soma;

    do{
    printf("Digite um numero inteiro:\n");
    scanf("%d", pn1);
    *pn1>=0 ? *psoma += *pn1, i++ : printf("Numero negativo digitado, encerrando o loop...\n");
    }while(*pn1 >= 0);

    printf("A media acumulada e: %d", soma/i);

    return 0;
}

#endif

#ifdef ex05

/*
5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop. 
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep
*/

struct pessoa{

    char nome[15];
    char endereco[20];
    char cidade[11];
    char estado[14];
    char cep[8];
};

typedef struct pessoa pessoa;

pessoa cadastro[4];
pessoa *ptrCadastro = &cadastro[0];


void cadastrar(){

int i = 0;

    for(i = 0; i<4; i++)
    {
        printf("Digite o nome da pessoa %d:\n", i+1);
        gets((ptrCadastro+i)-> nome);
        printf("Digite o endereco da pessoa %d:\n", i+1);
        gets((ptrCadastro+i)-> endereco);
        printf("Digite a cidade da pessoa %d:\n", i+1);
        gets((ptrCadastro+i)-> cidade);
        printf("Digite o estado da pessoa %d:\n", i+1);
        gets((ptrCadastro+i)-> estado);
        printf("DIgite o CEP da pessoa %d: \n", i+1);
        gets((ptrCadastro+i)-> cep);

    }

}

int main()
{
    cadastrar();

    return 0;
}

#endif

#ifdef ex06

/*
6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado 
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano
*/
struct data
{
    int dia, mes, ano;
};

typedef struct data data;

int calculaDias(data *calendario)
{
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias1 = calendario[0].dia;
    int dias2 = calendario[1].dia;


    // Adicione os dias dos meses completos no primeiro ano
    for (int i = 0; i < calendario[0].mes; i++)
    {
        dias1 += diasPorMes[i];
    }

    for(int i = 0; i < calendario[1].mes; i++)
    {
        dias2 += diasPorMes[i];
    }

    for (int ano = calendario[0].ano; ano < calendario[1].ano; ano++)
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
            dias2 += 366;
        }
        else
        {
            dias2 += 365;
        }
    }

    return dias2-dias1;
}

int main()
{
    data *ptrCalendario;
    data calendarioFunc[2];

    ptrCalendario = &calendarioFunc[0];

    char ch;

    do
    {
        printf("Digite uma data (dd MM AAAA): ");
        scanf("%d",&(ptrCalendario+0) -> dia);
        setbuf(stdin,NULL);
        printf("Digite uma data (dd MM AAAA): ");
        scanf("%d",&(ptrCalendario+0) -> mes);
        setbuf(stdin,NULL);
        printf("Digite uma data (dd MM AAAA): ");
        scanf("%d",&(ptrCalendario+0) -> ano);
        setbuf(stdin,NULL);

        printf("Digite outra data (dd MM AAAA): ");
        scanf("%d",&(ptrCalendario+1) -> dia);
        setbuf(stdin,NULL);
        printf("Digite outra data (dd MM AAAA): ");
        scanf("%d",&(ptrCalendario+1) -> mes);
        setbuf(stdin,NULL);
        printf("Digite outra data (dd MM AAAA): ");
        scanf("%d",&(ptrCalendario+1) -> ano);
        setbuf(stdin,NULL);

        int diferenca = calculaDias(ptrCalendario);

        if(diferenca>0)
        {
            printf("A diferenca entre as datas e de: %d dias\n", diferenca);
        }
        else if(diferenca == 0)
        {
            printf("A diferenca e 0\n");
        }
        else
        {
            printf("A primeira data deve ser maior que a segunda\n");
        }
        printf("Deseja encerrar o programa? (s/n): ");
        scanf(" %c",&ch);
        setbuf(stdin, NULL);
    }
    while(ch != 's' && ch != 'S');

    return 0;
}
#endif