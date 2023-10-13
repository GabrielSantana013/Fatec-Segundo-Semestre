#include "stdio.h"

#define ex04

#ifdef ex1
/*1 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.*/
int soma(int fat)
{
    int soma = 0;
    while (fat > 0)
    {
        soma += fat % 10;
        fat /= 10;
    }
    return soma;
}

int main()
{
    int n1, fat, f;
    char escolha;

    printf("=====EXERCÍCIO 1======\n");

    do
    {
        printf("Digite um numero: ");
        scanf("%d", &n1);
        fat = n1;

        for (int i = n1 - 1; i > 1; i--)
        {
            fat *= i;
        }
        f = soma(fat);

        printf("O resultado do fatorial de %d e igual a: %d\n", n1, fat);

        printf("A soma dos seus algarismos e igual a: %d", f);

        printf("\nDeseja encerrar o programa? (s) ou (n)");
        getchar(); // limpa o buffer
        escolha = getchar();

    } while (escolha != 's');

    return 0;
}
#endif

#ifdef ex02

/*2 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/

int verify(int n1, int n2)
{

    if (n1 < 0 && n2 < 0)
    {
        return 0;
    }
    else if (n1 > 0 && n2 > 0)
    {
        return 1;
    }
    else if (n1 > 0 && n2 < 0)
    {
        return -1;
    }

    else
    {
        printf("Tente novamente.");
        return 5;
    }
}

int isPos(int n1, int n2)
{
    if (n2 > n1)
    {
        n1 = n1 ^ n2;
        n2 = n1 ^ n2;
        n1 = n1 ^ n2;
    }

    int sum = 0;

    for (int i = n2 + 1; i < n1; i++)
    {
        sum += (i);
    }

    return sum;
}

int isNeg(int n1, int n2)
{
    int mult = 1;

    if (n2 > n1)
    {
        n1 = n1 ^ n2;
        n2 = n1 ^ n2;
        n1 = n1 ^ n2;
    }

    for (int i = n1 - 1; i > n2; i--)
    {
        mult *= (i);
    }

    return mult;
}

int div(int n1, int n2)
{
    return n1 / n2;
}

int main()
{
    int n1, n2;
    char a;
    do
    {

        printf("Digite N1: ");
        scanf("%d", &n1);
        printf("Digite N2: ");
        scanf("%d", &n2);
        int retorno = verify(n1, n2);

        if (retorno == 1)
        {
            printf("A soma entre os numeros e: %d", isPos(n1, n2));
        }
        else if (retorno == 0)
        {
            printf("A multiplicacao entre os numeros e: %d", isNeg(n1, n2));
        }
        else if (retorno == -1)
        {
            printf("A div entre os numeros e: %d", div(n1, n2));
        }

        printf("\nDeseja encerrar o programa? (s) ou (n)");
        getchar();
        a = getchar();

    } while (a != 's');

    return 0;
}
#endif

#ifdef ex03
/*3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().*/
int soma(int n1, int n2)
{
    int soma = 0;
    soma = n1 + n2;
    return soma;
}

int sub(int n1, int n2)
{
    int sub = 0;
    sub = n1 - n2;
    return sub;
}

int mult(int n1, int n2)
{
    int mult = 0;
    mult = n1 * n2;
    return mult;
}

int div(int n1, int n2)
{
    int div = 0;
    div = n1 / n2;
    return div;
}

int main()
{
    int n1, n2, f1, f2, f3, f4;
    char escolha;

    printf("=====EXERCICIO 3======\n");

    do
    {
        printf("Digite dois numeros inteiros\n");
        scanf("%d%d", &n1, &n2);

        f1 = soma(n1, n2);
        f2 = sub(n1, n2);
        f3 = mult(n1, n2);
        f4 = div(n1, n2);

        printf("Resultado da primeira funcaoo (soma): %d\nResultado da segunda funcao (subtracao): %d\nResultado da terceira funcao (multiplicacao): %d\nResultado da quarta funcao (divisao): %d\n", f1, f2, f3, f4);

        printf("\nDeseja encerrar o programa? (s) ou (n)");
        getchar(); // limpa o buffer
        escolha = getchar();

    } while (escolha != 's');

    return 0;
}
#endif

#ifdef ex04
/*3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().

    4 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.*/
int soma(int n1, int n2, int f1)
{
   
    printf("soma entre %d e %d\n", n1, n2);
    f1 = n1 + n2;
    return f1;
}

int sub(int n1, int n2, int f2)
{
    
    printf("sub entre %d e %d\n", n1, n2);
    f2 = n1 - n2;
    return f2;
}

int mult(int n1, int n2, int f3)
{
    
    printf("mult entre %d e %d\n", n1, n2);
    f3 = n1 * n2;
    return f3;
}

int div(int n1, int aux, int f4)
{

    printf("div entre %d e %d\n", n1, aux);
    f4 = n1/aux;
    return f4;
}

int main()
{
    int n1, f1 = 0, f2 = 0, f3 = 0, f4 = 0, cont = 1;
    char escolha;
    int aux;
    printf("=====EXERCICIO 3======\n");

    do
    {
        printf("Digite um numero inteiro\n");
        scanf(" %d", &n1);

        if (cont == 1)
        {
            aux = n1;
        }
        
        else if (cont == 2)
        { 
            f1 = soma(aux, n1, f1);  
            f2 = sub(aux, n1, f2);
            f3 = mult(aux, n1, f3);
            f4 = div(aux, n1, f4);
        }

        else if (cont % 2 != 0)
        {
           
            aux = n1;
            f1 = soma(f1, n1, f1);
            f2 = sub(f2, n1, f2);
            f3 = mult(f3, n1, f3);
            f4 = div(f4, n1, f4);
        }
        
        else
        {
            aux = f1;
            f1 = soma(aux, n1, f1);
            aux = f2;
            f2 = sub(aux, n1, f2);
            aux = f3;
            f3 = mult(aux, n1, f3);
            aux = f4;
            f4 = div(aux, n1, f4);

        }
        printf("aux %d\nf1 %d\nf2 %d\nf3 %d\nf4 %d\n", aux, f1, f2, f3, f4);

        printf("\nDeseja encerrar o programa? (s) ou (n)");
        getchar(); // limpa o buffer
        escolha = getchar();
        cont++;

    } while (escolha != 's');

    printf("Resultado da primeira funcaoo (soma): %d\nResultado da segunda funcao (subtracao): %d\nResultado da terceira funcao (multiplicacao): %d\nResultado da quarta funcao (divisao): %d\n", f1, f2, f3, f4);
    return 0;
}

#endif

#ifdef ex05

/*5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser
    mostrado na funcao main().*/

int sum(int n1, int res)
{

    return n1 + res;
}

int sub(int n1, int res)
{

    return n1 - res;
}

int mult(int n1, int res)
{

    return n1 * res;
}

int div(int n1, int res)
{

    int result;

    while (res == 0)
    {
        printf("Digite o denominador (diferente de 0): ");
        scanf("%d", &result);
        return n1 / result;
    }

    return n1 / res;
}

int main()
{

    int n;
    int n1, res = 0;
    char choose;

    do
    {

        printf("Quantos numeros voce deseja?");
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {

            printf("Digite o %d numero: ", i + 1);
            scanf("%d", &n1);
            if (i == 0)
            {
                res = n1;
            }
            else
            {
                printf("Escolha a operacao: (+) (-) (*) (/) ");
                char ch;
                scanf(" %c", &ch); // espaço p/ limpar buffer

                switch (ch)
                {
                case '+':
                    res = sum(res, n1);
                    break;
                case '-':
                    res = sub(res, n1);
                    break;
                case '*':
                    res = mult(res, n1);
                    break;
                case '/':
                    res = div(res, n1);
                    break;
                default:
                    printf("Operacao invalida, tente novamente:\n");
                    i--; // Voltar para a iteração anterior
                }
            }
        }

        printf("Res = %d", res);
        printf("\nDeseja encerrar o programa?");
        getchar(); // limpa buffer
        choose = getchar();

    } while (choose != 's' && choose != 'S');

    return 0;
}

#endif