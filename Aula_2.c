#include "stdio.h"
#define ex5

//OBS.: Todos os programa devem ser finalizados pelo usuario.

#ifdef ex1
/*
1 - As ligacoes telefonicas s�o cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.
*/

int main()
{

    int horaI, minutoI, segundoI, horaF, minutoF, segundoF, horaResult = 0, minutoResult = 0, segundoResult = 0;
    char escolha;
    do
    {
        printf("=====EXERCICIO 1======\n");
            //HORARIO INICIAL
            do
            {
                printf("Digite a hora que comecou a sua ligacao: \n");
                scanf("%d", &horaI);
            }
            while (horaI < 0 || horaI > 24);

            do
            {
                printf("Digite o minuto que comecou a sua ligacao: \n");
                scanf("%d", &minutoI);
            }
            while (minutoI < 0 || minutoI > 60);

            do
            {
                printf("Digite o segundo que comecou a sua ligacao: \n");
                scanf("%d", &segundoI);
            }
            while (segundoI < 0 || segundoI > 60);

            //MOSTRA HORARIO INICIAL
            printf("Horario inicial: %dh %dm %ds\n", horaI, minutoI, segundoI);

            //HORARIO FINAL
            do
            {
                printf("Digite a hora que terminou a sua ligacao: \n");
                scanf("%d", &horaF);
            }
            while (horaF < 0 || horaF > 24);

            do
            {
                printf("Digite o minuto que terminou a sua ligacao: \n");
                scanf("%d", &minutoF);
            }
            while (minutoF < 0 || minutoF > 60);

            do
            {
                printf("Digite o segundo que terminou a sua ligacao: \n");
                scanf("%d", &segundoF);
            }
            while (segundoF < 0 || segundoF > 60);

            //MOSTRA HORARIO FINAL
            printf("Horario final: %dh %dm %ds\n", horaF, minutoF, segundoF);

            minutoI += horaI * 60;
            segundoI += minutoI * 60;

            minutoF += horaF * 60;
            segundoF += minutoF * 60;

            segundoResult = segundoF - segundoI;


        while (segundoResult >= 60)
        {

            if (segundoResult >= 60)
            {
                segundoResult -= 60;
                minutoResult++;
            }

            if (minutoResult >= 60)
            {
                minutoResult -= 60;
                horaResult++;
            }
        }
        printf("Horario total: %dh %dm %ds\n", horaResult, minutoResult, segundoResult);

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }while(escolha != 'n' && escolha != 'N');

    return 0;
}
#endif // ex1

#ifdef ex2
/*
2 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.
*/

int main()
{
    char resp, escolha;
    int inicio, fim, meio;

    do{
        printf("=====EXERCICIO 2======\n");
        printf("Pense em um numero entre 1 e 99!\n");

        inicio = 1;
        fim = 99;
        resp = NULL;
        meio = (inicio + fim)/2;

        while(resp != '=')
        {
            printf("Seu numero e' maior (>), menor (<) ou igual (=) a %d?\n", meio);
            setbuf(stdin, NULL);
            resp = getchar();

            if(resp == '>')
            {
                inicio = meio + 1;
                meio = (inicio + fim)/2;
            }
            else if(resp == '<')
            {
                fim = meio - 1;
                meio = (inicio + fim)/2;
            }
            else if (resp == '=')
                printf("Numero encontrado!");
            else
                printf("Entrada invalida!");
        }

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }while(escolha != 'n' && escolha != 'N');

    return 0;
}
#endif // ex2

#ifdef ex3
/*
3 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.
*/

int main()
{
    char resp, escolha;
    int inicio, fim, meio;

    do
    {
        printf("=====EXERCICIO 3======\n");
        printf("Pense em um numero entre 1 e 99!\n");

        inicio = 1;
        fim = 99;
        resp = NULL;
        meio = (inicio + fim)/2;

        while(resp != '=')
        {
            printf("Seu numero e' maior (>), menor (<) ou igual (=) a %d?\n", meio);
            setbuf(stdin, NULL);
            resp = getchar();

            switch(resp)
            {
                case '>':
                    {
                        inicio = meio + 1;
                        meio = (inicio + fim)/2;
                        break;
                    }
                case '<':
                    {
                        fim = meio - 1;
                        meio = (inicio + fim)/2;
                        break;
                    }
                case '=':
                    {
                        printf("Numero encontrado!");
                        break;
                    }
                default:
                    printf("Entrada invalida!");
            }
        }

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }while(escolha != 'n' && escolha != 'N');

    return 0;
}
#endif // ex3

#ifdef ex4
/*
4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!
*/

int main()
{
    char escolha;
    int dist, litro, consumo;

    do
    {
        printf("=====EXERCICIO 4======\n");

        dist=litro=consumo=0;

        do
        {
            printf("Digite a distancia (km) percorrida\n");
            scanf("%d",&dist);
        }while(dist<0);

        do
        {
            printf("Digite a quantidade de litros (L) consumidos\n");
            scanf("%d",&litro);
        }while(litro<0);

        consumo=dist/litro;

        if(consumo<8)
            printf("Venda o carro!");
        else if(consumo>=8 && consumo<14)
            printf("Economico!");
        else
            printf("Super Economico!");

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }while(escolha != 'n' && escolha != 'N');
    return 0;
}
#endif // ex4

#ifdef ex5
/*
5 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.
*/

int main()
{

    char escolha;
    int num, med, cont;
    do
    {
        printf("=====EXERCICIO 5======\n");

        num=med=cont=0;

        do
        {
            printf("Digite um numero positivo para armazenar; digite um numero negativo para encerrar a atividade\n");
            scanf("%d",&num);

            if(num>=0)
            {
                med+=num;
                cont++;
            }
        }
        while(num>=0);

        if(med==0)
            printf("Nenhum numero positivo foi digitado.");
        else
            printf("A media dos numeros digitados e' de: %d",med/cont);

        printf("\nDeseja continuar?\t(s/n)\n");
        setbuf(stdin, NULL);
        escolha = getchar();

        system("cls");

    }
    while(escolha != 'n' && escolha != 'N');
    return 0;
}
#endif // ex5
