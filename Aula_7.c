/*Todos os programas devem ser encerrados pelo usuário*/

#include "stdio.h"
#define ex02

#ifdef ex01

/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/

struct variaveis
{

    char n1;
    int n2;
    long n3;
    float n4;
    double n5;
    unsigned char n6;
    unsigned int n7;
    unsigned long n8;

};

typedef struct variaveis variaveis;

variaveis valores;


int main()
{
    char ch;
do{
    printf("Digite um char:");
    scanf("%c", &valores.n1);
    printf("\nDigite um int:");
    scanf("%d", &valores.n2);
    printf("\nDigite um long:");
    scanf("%ld", &valores.n3);
    printf("\nDigite um float:");
    scanf("%f", &valores.n4);
    printf("\nDigite um double:");
    scanf("%lf", &valores.n5);
    setbuf(stdin, NULL);
    printf("\nDigite um unsigned char:");
    scanf("%c", &valores.n6);
    printf("\nDigite um unsigned int:");
    scanf("%u", &valores.n7);
    printf("\nDigite um unsigned long:");
    scanf("%lu", &valores.n8);

    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-1c         %-8d  %-11ld         %-8.1e          %9.1e\n", valores.n1, valores.n2, valores.n3, valores.n4, valores.n5);
    printf("          %-c                   %-8d            %-11lu\n", valores.n6, valores.n7,valores.n8);
    printf("Deseja encerrar o programa? (s/n):");
    setbuf(stdin, NULL);
    ch = getchar();
    setbuf(stdin, NULL);

}while(ch != 's' && ch != 'S');
    return 0;
}

#endif

#ifdef ex02

/*2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faça um menu com uma opcao para saida do programa.
        estrutura: nome, end, cidade, estado, cep
*/

struct cadastro
{
    char nome[20], end[30], cidade[20], estado[15], cep[20];
};

typedef struct cadastro cadastro;

cadastro pessoas[4];

void recebeCadastro()
{

    for (int i = 0; i <= 3; i++)
    {

        printf("Digite o nome da pessoa %d:\n", i + 1);
        gets(&pessoas[i].nome);
        printf("Digite o endereco da pessoa %d:\n", i + 1);
        gets(&pessoas[i].end);
        printf("Digite a cidade da pessoa %d:\n", i + 1);
        gets(&pessoas[i].cidade);
        printf("Digite o estado da pessoa %d:\n", i + 1);
        gets(&pessoas[i].estado);
        printf("Digite o cep da pessoa %d:\n", i + 1);
        gets(&pessoas[i].cep);
    }
}

void imprimeCadastro()
{

    for (int i = 0; i <= 3; i++)
    {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Endereco: %s\n", pessoas[i].end);
        printf("Cidade: %s\n", pessoas[i].cidade);
        printf("Estado: %s\n", pessoas[i].estado);
        printf("Cep: %s\n", pessoas[i].cep);
        printf("==========\n");
    }
}

int main()
{
    int menu;

    while (1)
    {
        printf("Selecione a opcao adequada: \n");
        printf("[1] - Receber dados\n[2] - Imprimir dados\n[3] - Sair\n");
        scanf("%d", &menu);
        setbuf(stdin, NULL);
        switch (menu)
        {
        case 1:
            recebeCadastro();
            break;

        case 2:
            imprimeCadastro();
            break;

        case 3:
            exit(0);

        default:
            printf("Digite uma opcao valida.");
        }
        printf("\n");
    }
    return 0;
}

#endif

#ifdef ex03

/*
3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano
*/

struct data
{
    int dia, mes, ano;
};

typedef struct data data;
data calendario[2];

int calculaDias(data calendario[2]){

    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias1 = calendario[0].dia;
    int dias2 = calendario[1].dia;


    // Adicione os dias dos meses completos no primeiro ano
    for (int i = 0; i < calendario[0].mes; i++) 
    {
        dias1 += diasPorMes[i];
    }

    for(int i = 0; i<calendario[1].mes; i++)
    {
        dias2 += diasPorMes[i];
    }


        for (int ano = calendario[0].ano; ano < calendario[1].ano; ano++) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            dias2 += 366;
        } else {
            dias2 += 365;
        }
    }
    return dias2-dias1;

}
 

int main()
{

char ch;

do{
    printf("Digite uma data (dd MM AAAA):");
    scanf("%d%d%d", &calendario[0].dia,&calendario[0].mes, &calendario[0].ano);
    setbuf(stdin,NULL);
    printf("Digite outra data (dd MM AAAA):");
    scanf("%d%d%d", &calendario[1].dia,&calendario[1].mes, &calendario[1].ano);
    int diferenca = calculaDias(calendario);

    if(diferenca>0)
    {
        printf("A diferenca entre as datas e de: %d dias\n", diferenca);
    }
    else if(diferenca == 0)
    {
        printf("A diferenca e 0.\n");
    }
    else
    {
        printf("A primeira data deve ser maior que a segunda\n");
    }
    printf("Deseja encerrar o programa? (s/n):");
    setbuf(stdin, NULL);
    ch = getchar();
    setbuf(stdin, NULL);

}while(ch != 's' && ch != 'S');
    return 0;
}

#endif


#ifdef ex04

/*
4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faça um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/

struct dados{

    char nome[20];
    float peso, altura;
};

typedef struct dados dados;

dados pessoa[4];

void recebeCadastro(){

    for(int i = 0; i<=3; i++)
    {
    printf("Digite o nome da pessoa %d\n", i+1);
    gets(&pessoa[i].nome);
    printf("Digite o peso da pessoa %d\n", i+1);
    scanf("%f", &pessoa[i].peso);
    setbuf(stdin, NULL);
    printf("Digite a altura da pessoa %d\n", i+1);
    scanf("%f", &pessoa[i].altura);
    setbuf(stdin, NULL);
    }
}

void imprimeCadastro(){

    for(int i = 0; i<=3; i++)
    {
        printf("Nome da pessoa %d: %s\n", i+1, pessoa[i].nome);
        printf("Peso da pessoa %d: %.2f\n", i+1, pessoa[i].peso);
        printf("Altura da pessoa %d: %.2f\n", i+1, pessoa[i].altura);
        printf("==========\n");
    }


}

void calculoIMC(){

    float imc;

    for(int i = 0; i<=3;i++)
    {
        imc = pessoa[i].peso/(pessoa[i].altura*pessoa[i].altura);
        printf("IMC da pessoa %d: %.2f\n", i+1, imc);
    }

}

int main()
{
    int menu;

    while (1)
    {
        printf("Selecione a opcao adequada: \n");
        printf("[1] - Receber dados\n[2] - Imprimir dados\n[3] - Calculo de IMC\n[4] - Sair\n");
        scanf("%d", &menu);
        setbuf(stdin, NULL);
        switch (menu)
        {
        case 1:
            recebeCadastro();
            break;

        case 2:
            imprimeCadastro();
            break;

        case 3:
            calculoIMC();
            break;

        case 4:
            exit(0);

        default:
            printf("Digite uma opcao valida.");
        }
        printf("\n");
    }
    return 0;
}

#endif