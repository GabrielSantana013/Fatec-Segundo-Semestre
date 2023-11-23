#include "stdio.h"
#include "stdlib.h"
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
    pStr1 = &str1[0];
    pStr2 = &str2[0];
    do
    {
        recebeString(pStr1, pStr2);
        int retorno = comparaString(pStr1, pStr2);

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

int soma(int pnumero, float res)
{
    return pnumero + res;
}

int sub(int pnumero, float res)
{
    return res - pnumero;
}
int mult(int pnumero, float res)
{
    return pnumero * res;
}
float divi(int pnumero, float res)
{
    if (pnumero == 0)
    {
        printf("Nao e possivel dividir por 0.");
        return 0;
    }
    else
    {
        return res / pnumero;
    }
}

int main()
{
    int numero, *pnumeros;
    char escolha;
    float res = 0;

    while (1)
    {
        printf("Digite um numero:\n");
        scanf("%d", &numero);
        pnumeros = &numero;

        printf("Qual operacao voce deseja fazer com os numeros? (+) (-) (x) (/)\n");
        printf("OU digite '=' para sair\n");

        getchar(); // limpa buffer
        escolha = getchar();

        switch (escolha)
        {
        case '+':
            res = soma(*pnumeros, res);
            printf("Resultado: %.2f\n", res);
            break;
        case '-':
            res = sub(*pnumeros, res);
            printf("Resultado: %.2f\n", res);
            break;
        case 'x':
            res = mult(*pnumeros, res);
            printf("Resultado: %.2f\n", res);
            break;
        case '/':
            res = divi(*pnumeros, res);
            printf("Resultado: %.2f\n", res);
            break;
        case '=':
            exit(0);
            break;
        default:
            printf("Operacao inválida, tente novamente.");
        }
    }
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

int buscaLetra(char *pLetra, char *ptrChave)
{

    for (int i = 0; *ptrChave != '\0'; i++, ptrChave++)
    {
        if (*pLetra == *ptrChave)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char key[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    char *ptrChave;
    ptrChave = &key[0];

    char letra;
    char *pLetra;

    pLetra = &letra;

    printf("Digite uma letra: \n");
    scanf("%c", pLetra);
    int retorno = buscaLetra(pLetra, ptrChave);

    retorno == 1 ? printf("Letra encontrada!") : printf("Letra nao encontrada!");
    // condicao ? valor se verdadeiro : valor se falso

    return 0;
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

void recebeDados(struct variaveis *ptr)
{

    printf("Digite um caractere: \n");
    scanf("%c", &(ptr->n1));
    printf("Digite um int: \n");
    scanf("%d", &(ptr->n2));
    printf("Digite um long: \n");
    scanf("%ld", &(ptr->n3));
    printf("Digite um float: \n");
    scanf("%f", &(ptr->n4));
    printf("Digite um doule: \n");
    scanf("%lf", &(ptr->n5));
    getchar(); // limpa buffer
    printf("Digite um unsigned char: \n");
    scanf("%c", &(ptr->n6));
    printf("Digite um unsigned int: \n");
    scanf("%u", &(ptr->n7));
    printf("Digite um unsigned long: \n");
    scanf("%lu", &(ptr->n8));
}

void imprimeDados(struct variaveis *ptr)
{

    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-1c         %-8d  %-11ld         %-8.1f  %-9.1lf\n", ptr->n1, ptr->n2, ptr->n3, ptr->n4, ptr->n5);
    printf("         %-1c                   %-8u            %-11lu", ptr->n6, ptr->n7, ptr->n8);
}

int main()
{
    typedef struct variaveis variaveis;
    variaveis cadastro, *ptr;
    ptr = &cadastro;
    recebeDados(ptr);
    imprimeDados(ptr);
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

struct cadastro
{

    char nome[15], end[35], cidade[15], estado[2];
    int cep;
};

void cadastrar(struct cadastro *ptr)
{
    for (int i = 1; i <= 4; i++)
    {
        printf("Digite o nome da pessoa %d:\n", i);
        gets(ptr->nome);
        printf("Digite o endereco da pessoa %d:\n", i);
        gets(ptr->end);
        printf("Digite a cidade da pessoa %d:\n", i);
        gets(ptr->cidade);
        printf("Digite o estado da pessoa %d:\n", i);
        gets(ptr->estado);
        printf("Digite o CEP da pessoa %d:\n", i);
        scanf("%d", &ptr->cep); // perguntar pq &ptr->cep funciona e ptr->cep ñ
        getchar();              // limpa buffer

        ptr++;
    }
}

void imprimeCadastro(struct cadastro *ptr)
{
    for (int i = 1; i <= 4; i++)
    {
        printf("Nome da pessoa %d: %s\n", i, ptr->nome);
        printf("Endereco da pessoa %d: %s\n", i, ptr->end);
        printf("Cidade da pessoa %d: %s\n", i, ptr->cidade);
        printf("Estado da pessoa %d: %s\n", i, ptr->estado);
        printf("CEP da pessoa %d: %d\n\n\n", i, ptr->cep);
        ptr++;
    }
}

int main()
{
    int menu;
    typedef struct cadastro cadastro;
    cadastro cadastros[4], *ptr;
    ptr = &cadastros[0];
    while (1)
    {
        printf("O que voce deseja fazer?\n");
        printf("1-Cadastrar\n2-Imprimir Dados\n3-Sair\n");
        scanf("%d", &menu);
        getchar(); // limpa buffer

        switch (menu)
        {
        case 1:
            cadastrar(ptr);
            break;
            ;
        case 2:
            imprimeCadastro(ptr);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Opcao invalida, tente novamente.\n");
        }
    }
}

#endif

#ifdef ex06

/*
6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.
*/

struct cadastro
{

    char nome[15], end[35], cidade[15], estado[2];
    unsigned int cep;
};

void cadastrar(struct cadastro *ptr)
{
    for (int i = 1; i <= 4; i++)
    {
        printf("Digite o nome da pessoa %d:\n", i);
        gets(ptr->nome);
        printf("Digite o endereco da pessoa %d:\n", i);
        gets(ptr->end);
        printf("Digite a cidade da pessoa %d:\n", i);
        gets(ptr->cidade);
        printf("Digite o estado da pessoa %d:\n", i);
        gets(ptr->estado);
        printf("Digite o CEP da pessoa %d:\n", i);
        scanf("%d", &ptr->cep); 
        getchar();              

        ptr++;
    }
}

void imprimeCadastro(struct cadastro *ptr)
{
    for (int i = 1; i <= 4; i++)
    {
        if(ptr->nome[0] != '*')
        {
        printf("Nome da pessoa %d: %s\n", i, ptr->nome);
        printf("Endereco da pessoa %d: %s\n", i, ptr->end);
        printf("Cidade da pessoa %d: %s\n", i, ptr->cidade);
        printf("Estado da pessoa %d: %s\n", i, ptr->estado);
        printf("CEP da pessoa %d: %d\n\n\n", i, ptr->cep);
        ptr++;
        }
        else
        {
            ptr++;
        } 
    }
}

int procura(struct cadastro *ptr)
{
    int i = 0, j = 0;
    char nome[15];
    printf("Digite o nome que voce deseja buscar:\n\n");
    gets(&nome);
    while (j<4)
    {
        for (i = 0; nome[i] != '\0' || ptr->nome[i] != '\0'; i++)
        {
            if (nome[i] != ptr->nome[i])
            {
                break;
            }
        }
        if (nome[i] == '\0' && ptr->nome[i] == '\0')
        {
            printf("Nome: %s\n", ptr->nome);
            printf("Endereco: %s\n", ptr->end);
            printf("Cidade: %s\n", ptr->cidade);
            printf("Estado: %s\n", ptr->estado);
            printf("CEP: %d\n", ptr->cep);
            return 1;
        }
        else
        {
            ptr++;
        }
        j++;
    }
    return 0;
}

void alteraDados(struct cadastro *ptr)
{
    int i = 0, j = 0;
    char nome[15];
    printf("Digite o nome que voce deseja buscar:\n\n");
    gets(&nome);
    while (j<4)
    {
        for (i = 0; nome[i] != '\0' || ptr->nome[i] != '\0'; i++)
        {
            if (nome[i] != ptr->nome[i])
            {
                break;
            }
        }
        if (nome[i] == '\0' && ptr->nome[i] == '\0')
        {
            printf("Digite um novo nome para a pessoa\n");
            gets(ptr->nome);
            printf("Digite um novo endereco para a pessoa:\n");
            gets(ptr->end);
            printf("Digite uma nova cidade para a pessoa:\n");
            gets(ptr->cidade);
            printf("Digite um novo estado para a pessoa:\n");
            gets(ptr->estado);
            printf("Digite um novo cep para a pessoa:\n");
            scanf("%d", &ptr->cep);
            getchar();//limpa buffer
            break;
        }
        else
        {
            ptr++;
        }
        j++;
    }
    
}
void excluiRegistro(struct cadastro *ptr)
{
    int i = 0, j = 0;
    char nome[15];
    printf("Digite o nome que voce deseja buscar:\n\n");
    gets(&nome);
    while (j<4)
    {
        for (i = 0; nome[i] != '\0' || ptr->nome[i] != '\0'; i++)
        {
            if (nome[i] != ptr->nome[i])
            {
                break;
            }
        }
        if (nome[i] == '\0' && ptr->nome[i] == '\0')
        {
            ptr->nome[0] = '*';
            j = 5;
            
        }
        else
        {
            ptr++;
        }
        j++;
    }
}


int main()
{
    int menu;
    typedef struct cadastro cadastro;
    cadastro cadastros[4], *ptr;
    ptr = &cadastros[0];
    while (1)
    {
        printf("O que voce deseja fazer?\n");
        printf("1-Cadastrar\n2-Imprimir Dados\n3-Procurar pessoas\n4-Alterar dados\n5-Excluir Registros\n6-Sair\n");
        scanf("%d", &menu);
        getchar(); // limpa buffer

        switch (menu)
        {
        case 1:
            cadastrar(ptr);
            break;

        case 2:
            imprimeCadastro(ptr);
            break;
        case 3:
            int retorno = procura(ptr);
            if (retorno != 1)
            {
                printf("\nPessoa nao encontrada\n\n");
            }
            break;
        case 4:
            alteraDados(ptr);
            break;
        case 5:
            excluiRegistro(ptr);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Opcao invalida, tente novamente.\n");
        }
    }
}

#endif