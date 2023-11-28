#include "stdio.h"
#include "stdlib.h"

/*PROGRAMA DESAFIO 2

1 - Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções de menu:

1 – Entrada de dados.

2 – Lista todas todos os dados na tela.

3 – Pesquisar um medico pelo nome completo e mostra na tela

4 – Pesquisar um celular pelo nome completo

5 – Pesquisar pela data da consulta.

6 – Altera dados. Pesquisa pelo nome completo.

7 – Exclui dados. Pesquisa pelo nome completo.

8 – Saída pelo usuário

Estrutura: medico, celular, data_consulta

A única estrutura de dados do programa deve ser uma variável local na função main(). Portanto a passagem da estrutura para as funções utiliza ponteiro.

Cada uma das opções do menu é uma função no programa.

O médico é a “chave primário” do banco de dados.

Todas as operações de leitura e escrita devem ser feitas direto no arquivo. (utilize a função fseek quando necessário).

O programa tem um único arquivo de dados. Não pode usar nenhum arquivo auxiliar.

Não pode usar nenhuma função de biblioteca a não ser as 6 da apostila e as funções de manipulação de arquivos.*/

typedef struct medicos
{

    char nomeMedico[20], nCelular[14], dataConsulta[9];
} medicos;

void registro(struct medicos *ptr)
{
    FILE *pfile;
    int bytes;
    bytes = sizeof(struct medicos);

    // se n existir,cria o arquivo
    if (pfile == NULL)
    {
        pfile = fopen("desafio2.txt", "w+");
    }

    // abre o arquivo para adicionar dados
    pfile = fopen("desafio2.txt", "a");

    printf("Digite o nome do Medico:\n");
    gets(ptr->nomeMedico);
    printf("Digite a data da consulta (ddMMAAAA):\n");
    gets(ptr->dataConsulta);
    printf("Digite o numero de celular do Medico:\n");
    gets(ptr->nCelular);

    fwrite(ptr, bytes, 1, pfile);

    fclose(pfile);
}

void listarRegistro(struct medicos *ptr)
{
    FILE *pfile;
    pfile = fopen("desafio2.txt", "r");
    int bytes;
    bytes = sizeof(struct medicos);

    if (pfile == NULL)
    {
        printf("ERRO! O documento ainda nao foi criado.");
        exit(0);
    }

    while (fread(ptr, bytes, 1, pfile) == 1)
    {
        if (ptr->nomeMedico[0] != '*')
        {
            printf("\nNome do Medico: %s\n", ptr->nomeMedico);
            printf("Data da consulta: %s\n", ptr->dataConsulta);
            printf("Numero de celular do Medico: %s\n", ptr->nCelular);
        }
    }

    fclose(pfile);
}

void pesquisaRegistro(struct medicos *ptr)
{
    FILE *pfile;
    int i = 0, j = 0, bytes;
    char nomeLocal[20];
    bytes = sizeof(struct medicos);
    printf("Qual o nome do Medico que voce deseja buscar?\n");
    gets(nomeLocal);

    pfile = fopen("desafio2.txt", "r");

    while (fread(ptr, bytes, 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeMedico[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeMedico[i])
            {
                break;
            }
        }
        if (nomeLocal[i] == '\0' && ptr->nomeMedico[i] == '\0')
        {
            printf("\nNome do Medico: %s\n", ptr->nomeMedico);
            printf("Data da consulta: %s\n", ptr->dataConsulta);
            printf("Numero de celular do Medico: %s\n\n", ptr->nCelular);
            j++;
            break;
        }
    }

    if(j == 0)
    {
    printf("\nMedico nao encontrado!\n");
    }

    fclose(pfile);
}

void pesquisaNumero(struct medicos *ptr)
{
    FILE *pfile;
    int i = 0, bytes, j = 0;
    char nomeLocal[20];
    bytes = sizeof(struct medicos);
    printf("Qual o nome do Medico que voce deseja buscar o Numero?\n");
    gets(nomeLocal);

    pfile = fopen("desafio2.txt", "r");

    while (fread(ptr, bytes, 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeMedico[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeMedico[i])
            {
                break;
            }
        }
        if (nomeLocal[i] == '\0' && ptr->nomeMedico[i] == '\0')
        {
            printf("\nNumero de celular do Medico %s: %s\n", ptr->nomeMedico, ptr->nCelular);
            j++;
            break;
        }
    }
    if(j == 0)
    {
    printf("\nMedico nao encontrado!\n");
    }
    fclose(pfile);
}

void pesquisaPelaData(struct medicos *ptr)
{
    FILE *pfile;
    int i = 0, j = 0, bytes;
    char dataConsultaLocal[9];
    bytes = sizeof(struct medicos);
    printf("Digite a data da consulta para procurar o nome do Medico:\n");
    gets(dataConsultaLocal);

    pfile = fopen("desafio2.txt", "r");

    while (fread(ptr, bytes, 1, pfile) == 1)
    {
        for (i = 0; dataConsultaLocal[i] != '\0' || ptr->dataConsulta[i] != '\0'; i++)
        {
            if (dataConsultaLocal[i] != ptr->dataConsulta[i])
            {
                break;
            }
        }
        if (dataConsultaLocal[i] == '\0' && ptr->dataConsulta[i] == '\0')
        {
            printf("\nNome do Medico: %s\n", ptr->nomeMedico);
            j++;
        }
    }
    if(j == 0)
    {
    printf("\nMedico nao encontrado!\n");
    }
    fclose(pfile);
}

void alteraDados(struct medicos *ptr)
{
    FILE *pfile;
    char nomeLocal[20];
    int i = 0, j = 0, bytes;

    bytes = sizeof(struct medicos);
    printf("Qual o nome do registro que voce deseja alterar?\n");
    gets(nomeLocal);
    pfile = fopen("desafio2.txt", "r+");

    while (fread(ptr, bytes, 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeMedico[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeMedico[i])
            {
                break;
            }
        }
        if (nomeLocal[i] == '\0' && ptr->nomeMedico[i] == '\0')
        {

            printf("Digite o novo nome do Medico:\n");
            gets(ptr->nomeMedico);
            printf("Digite a nova data da consulta:\n");
            gets(ptr->dataConsulta);
            printf("Digite o novo numero do Medico:\n");
            gets(ptr->nCelular);
            fseek(pfile, -bytes, 1);
            fwrite(ptr, bytes, 1, pfile);
            j++;
            break;
        }
    }
    if(j == 0)
    {
    printf("\nMedico nao encontrado!\n");
    }
    fclose(pfile);
}

void excluiDados(struct medicos *ptr)
{
    FILE *pfile;
    char nomeLocal[20];
    int i = 0, j = 0, bytes;
    bytes = sizeof(struct medicos);
    printf("Qual o nome do registro que voce deseja alterar?\n");
    gets(nomeLocal);
    pfile = fopen("desafio2.txt", "r+");

    while (fread(ptr, bytes, 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeMedico[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeMedico[i])
            {
                break;
            }
        }
        if (nomeLocal[i] == '\0' && ptr->nomeMedico[i] == '\0')
        {
            ptr->nomeMedico[0] = '*';
            fseek(pfile, -bytes, 1);
            fwrite(ptr, bytes, 1, pfile);
            j++;
            break;
        }
    }
    if(j == 0)
    {
    printf("\nMedico nao encontrado!\n");
    }
    fclose(pfile);
}

int main()
{

    int menu;

    medicos *ptr, medico;
    ptr = &medico;
    do
    {
        printf("\nDesafio 2!\n\n");
        printf("1-Entrada de dados\n2-Listar Dados\n3-Pesquisa Medico\n4-Pesquisar numero do medico\n5-Pesquisar pela Data da Consulta\n6-Altera Dados\n7-Exclui Dados\n8-Sair\n");
        scanf("%d", &menu);
        getchar(); // limpa buffer

        switch (menu)
        {
        case 1:
            registro(ptr);
            break;
        case 2:
            listarRegistro(ptr);
            break;
        case 3:
            pesquisaRegistro(ptr);
            break;
        case 4:
            pesquisaNumero(ptr);
            break;
        case 5:
            pesquisaPelaData(ptr);
            break;
        case 6:
            alteraDados(ptr);
            break;
        case 7:
            excluiDados(ptr);
            break;
        case 8:
            exit(0);
            break;
        }

    } while (menu != 8);
    return 0;
}

// printa a mensagem de erro