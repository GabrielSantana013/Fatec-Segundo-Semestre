#include "stdio.h"
#define ex05

#ifdef ex01
/*
1 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.

*/
int main()
{

    char esc;
    int n1, n2;
    do
    {
        printf("Digite um numero: ");
        scanf("%d", &n1);
        printf("Digite o numero: ");
        scanf("%d", &n2);

        printf("%d+%d = %d\n", n1, n2, n1 + n2);
        printf("%d-%d = %d\n", n1, n2, n1 - n2);
        printf("%d*%d = %d\n", n1, n2, n1 * n2);
        printf("%d/%d = %d\n", n1, n2, n1 / n2);
        getchar();
        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}

#endif

#ifdef ex02

/*
2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.

*/
int main()
{
    char esc;
    int n1, n2;
    do
    {
        printf("Digite um numero: ");
        scanf("%d", &n1);
        printf("Digite o numero: ");
        scanf("%d", &n2);

        printf("%d+%d = %d\n", n1 -= n2, n2, n1 += n2);
        printf("%d-%d = %d\n", n1 += n2, n2, n1 -= n2);
        printf("%d*%d = %d\n", n1 /= n2, n2, n1 *= n2);
        printf("%d/%d = %d\n", n1 *= n2, n2, n1 /= n2);
        printf("\nDeseja continuar?\t(s/n)");
        getchar();
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}

#endif

#ifdef ex03

/*
3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.
*/

int anobissexto(int anoF, int anoI)
{

    int anosBi = 0;

    for (int i = anoI; i <= anoF; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) // calculo ano bissexto
        {
            anosBi++;
        }
    }
    return anosBi;
}

int main()
{
    char esc;
    int diaI, mesI, anoI, diaF, mesF, anoF;
    int anosBi;

    do
    {

        printf("Digite a data inicial (dd MM AAAA)\n");
        scanf("%d", &diaI);
        scanf("%d", &mesI);
        scanf("%d", &anoI);

        printf("Digite a data final (dd MM AAAA)\n");
        scanf("%d", &diaF);
        scanf("%d", &mesF);
        scanf("%d", &anoF);

        anosBi = anobissexto(anoF, anoI);

        int anos = anoF - anoI;
        int meses = mesF - mesI;
        int dias = diaF - diaI;

        dias += anosBi;

        if (dias < 0)
        {
            meses--;
            dias += 30; // Supondo 30 dias por mês
        }

        if (meses < 0)
        {
            anos--;
            meses += 12;
        }

        printf("Anos: %d\n", anos);
        printf("Meses: %d\n", meses);
        printf("Dias: %d\n", dias);
        getchar();
        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}

#endif

#ifdef ex04

/*4 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.*/

int main()
{
    char esc;
    int dia, mes, ano;

    do
    {

        printf("Digite a data (dia mes ano): ");
        scanf("%d %d %d", &dia, &mes, &ano);

        if (mes == 1 || mes == 2)
        {
            mes += 12;
            ano--;
        }

        int K = ano % 100;
        int J = ano / 100;
        int diaSemana = (dia + ((13 * (mes + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

        if (diaSemana < 0)
        {
            diaSemana += 7;
        }

        switch (diaSemana)
        {
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda-feira\n");
            break;
        case 3:
            printf("Terça-feira\n");
            break;
        case 4:
            printf("Quarta-feira\n");
            break;
        case 5:
            printf("Quinta-feira\n");
            break;
        case 6:
            printf("Sexta-feira\n");
            break;
        case 7:
            printf("Sábado\n");
            break;
        default:
            printf("Data inválida\n");
            break;
        }
        getchar();
        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}

#endif

#ifdef ex05

/*
Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.
    */
int main()
{
    char esc;
    int n1, n2;
    do
    {
        printf("Digite dois números inteiros:\n");
        scanf("%d%d", &n1, &n2);

        printf("Operacao AND \ndecimal:%d \nhexadecimal:(0x%x)\n\n", n1 & n2, n1 & n2);
        printf("Operacao OR \ndecimal:%d \nhexadecimal:(0x%x)\n\n", n1 | n2, n1 | n2);
        printf("Operacao XOR \ndecimal:%d \nhexadecimal:(0x%x)\n\n", n1 ^ n2, n1 ^ n2);
        getchar();
        printf("\nDeseja continuar?\t(s/n)");
        scanf("%c", &esc);
        getchar();
    } while (esc != 'n' && esc != 'N');
    return 0;
}

#endif
