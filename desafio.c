#include "stdio.h"
#include "windows.h"

char medico1[20], medico2[20], medico3[20];
char data_consulta1[11], data_consulta2[11], data_consulta3[11];

//variaveis auxiliares
char verifica_medico[20];
char verifica_data[11];

//funçoes auxiliares
void atualizaDados()
{
    FILE *arquivo;

    arquivo = fopen("dados.txt", "r");

    //erro caso o .txt não exista
    if (arquivo == NULL)
    {
        printf("ERRO! O ARQUIVO AINDA NAO FOI CRIADO");
    }

    //passa o conteudo do .txt para os vetores
    fread(&medico1, sizeof(medico1), 1, arquivo);
    fread(&medico2, sizeof(medico2), 1, arquivo);
    fread(&medico3, sizeof(medico3), 1, arquivo);
    fread(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
    fread(&data_consulta2, sizeof(data_consulta2), 1, arquivo);
    fread(&data_consulta3, sizeof(data_consulta3), 1, arquivo);
    fclose(arquivo);
}

void transformaMaiusc()
{
    //transforma os vetores medicos em maiusculo
    for (int i = 0; medico1[i] != '\0' || medico2[i] != '\0' || medico3[i] != '\0'; i++)
    {
        int letra1, letra2, letra3;
        letra1 = letra2 = letra3 = 0;

        letra1 = medico1[i];
        letra2 = medico2[i];
        letra3 = medico3[i];

        if (letra1 >= 97 && letra1 <= 122)
        {
            letra1 -= 32;
        }
        if (letra2 >= 97 && letra2 <= 122)
        {
            letra2 -= 32;
        }
        if (letra3 >= 97 && letra3 <= 122)
        {
            letra3 -=32;
        }
        medico1[i] = letra1;
        medico2[i] = letra2;
        medico3[i] = letra3;
    }
}

int verificaMed()
{
    int i;

    //transforma vetor verifica_medico maiusculo
    for (i = 0; verifica_medico[i] != '\0'; i++)
    {
        int letra = 0;

        letra = verifica_medico[i];

        if (letra >= 97 && letra <= 122)
        {
            letra -= 32;
        }
        verifica_medico[i] = letra;
    }

    //compara os vetores 'verifica_medico' e 'medico' para pesquisa
    for (i = 0; verifica_medico[i] != '\0' || medico1[i] != '\0'; i++)
    {
        if (verifica_medico[i] != medico1[i])
        {
            break;
        }
    }
    if(medico1[i] == '\0' && verifica_medico[i] =='\0')
    {
        return 1;
    }

    for (i = 0; verifica_medico[i] != '\0' || medico2[i] != '\0'; i++)
    {
        if (verifica_medico[i] != medico2[i])
        {
            break;
        }
    }
    if(medico2[i] == '\0' && verifica_medico[i] =='\0')
    {
        return 2;
    }

    for (i = 0; verifica_medico[i] != '\0' || medico3[i] != '\0'; i++)
    {
        if (verifica_medico[i] != medico3[i])
        {
            break;
        }
    }
    if(medico3[i] == '\0' && verifica_medico[i] =='\0')
    {
        return 3;
    }

    return 0;
}

//funçoes desafio
void entradaDados()
{
    printf("\nDigite o nome dos 3 medicos: \n");
    printf("Digite o nome do medico 1: ");
    gets(&medico1[0]);

    printf("Digite o nome do medico 2: ");
    gets(&medico2[0]);

    printf("Digite o nome do medico 3: ");
    gets(&medico3[0]);


    printf("Digite a data das consultas: (dd/MM/aaaa)\n");
    printf("Digite a primeira data: ");
    gets(&data_consulta1[0]);

    printf("Digite a segunda data: ");
    gets(&data_consulta2[0]);

    printf("Digite a terceiro data: ");
    gets(&data_consulta3[0]);

    //transforma todos os vetores medico em letras maiusculas
    transformaMaiusc();

    //escreve os dados dos vetores medico no arquivo .txt criado
    FILE *arquivo;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL)
    {
        arquivo = fopen("dados.txt", "w+");
    }

    fwrite(&medico1, sizeof(medico1), 1, arquivo);
    fwrite(&medico2, sizeof(medico2), 1, arquivo);
    fwrite(&medico3, sizeof(medico3), 1, arquivo);
    fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
    fwrite(&data_consulta2, sizeof(data_consulta2), 1, arquivo);
    fwrite(&data_consulta3, sizeof(data_consulta3), 1, arquivo);
    fclose(arquivo);

    printf("\nDados coletados com sucesso!\n");

    system("pause");
    system("cls");
}

void listarDados()
{
    atualizaDados();

    printf("\nMedico 1: %s\tData consulta: %s", medico1, data_consulta1);
    printf("\nMedico 2: %s\tData consulta: %s", medico2, data_consulta2);
    printf("\nMedico 3: %s\tData consulta: %s\n", medico3, data_consulta3);

    system("pause");
    system("cls");
}

void pesquisaMedicos()
{
    int retorno = 0;

    atualizaDados();

    printf("\nDigite o nome do medico: \n");
    gets(&verifica_medico);

    retorno = verificaMed();

    //mostra medico e data na tela
    if (retorno == 1)
    {
        printf("\nMedico: %s\tData consulta: %s\n", medico1, data_consulta1);
    }

    else if (retorno == 2)
    {
        printf("\nMedico: %s\tData consulta: %s\n", medico2, data_consulta2);
    }

    else if (retorno == 3)
    {
        printf("\nMedico: %s\tData consulta: %s\n", medico3, data_consulta3);
    }

    else
        printf("Medico inexistente\n");

    system("pause");
    system("cls");
}

void pesquisaData()
{
    printf("\nDigite a data da consulta (dd/MM/AAAA):");
    gets(&verifica_data);

    atualizaDados();

    int i, indexador;
    indexador = 0;

    //compara os vetores 'verifica_data' e 'data_consulta1' para pesquisa
    for (i = 0; verifica_data[i] != '\0' && data_consulta1[i] != '\0'; i++)
    {
        if (verifica_data[i] != data_consulta1[i])
        {
            break;
        }
    }
    if (data_consulta1[i] == '\0')
    {
        indexador++;
        puts(medico1);
    }

    for (i = 0; verifica_data[i] != '\0' && data_consulta2[i] != '\0'; i++)
    {
        if (verifica_data[i] != data_consulta2[i])
        {
            break;
        }
    }
    if (data_consulta2[i] == '\0')
    {
        indexador++;
        puts(medico2);
    }


    for (i = 0; verifica_data[i] != '\0' && data_consulta3[i] != '\0'; i++)
    {
        if (verifica_data[i] != data_consulta3[i])
        {
            break;
        }
    }
    if (data_consulta3[i] == '\0')
    {
        indexador++;
        puts(medico3);
    }

    //mensagem erro
    if (indexador == 0)
        printf("Data inexistente\n");

    system("pause");
    system("cls");
}

void alterarDados()
{
    int retorno = 0;

    printf("\nDigite o nome do medico: \n");
    gets(&verifica_medico);

    retorno = verificaMed();

    if (retorno == 1)
    {
        printf("\nDigite o novo nome do medico 1: ");
        gets(&medico1[0]);

        printf("Digite a nova data 1: ");
        gets(&data_consulta1[0]);
    }

    else if (retorno == 2)
    {
        printf("\nDigite o novo nome do medico 2: ");
        gets(&medico2[0]);

        printf("Digite a nova data 2: ");
        gets(&data_consulta2[0]);
    }

    else if (retorno == 3)
    {
        printf("\nDigite o novo nome do medico 3: ");
        gets(&medico3[0]);

        printf("Digite a nova data 3: ");
        gets(&data_consulta3[0]);
    }

    else
        printf("Medico inexistente\n");

    //transforma todos os vetores medico em letras maiusculas
    transformaMaiusc();

    FILE *arquivo;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL)
    {
        arquivo = fopen("dados.txt", "w+");
    }

    fwrite(&medico1, sizeof(medico1), 1, arquivo);
    fwrite(&medico2, sizeof(medico2), 1, arquivo);
    fwrite(&medico3, sizeof(medico3), 1, arquivo);
    fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
    fwrite(&data_consulta2, sizeof(data_consulta2), 1, arquivo);
    fwrite(&data_consulta3, sizeof(data_consulta3), 1, arquivo);
    fclose(arquivo);

    system("pause");
    system("cls");
}

void excluirDados()
{
    int retorno = 0;

    printf("\nDigite o nome do medico para deletar dados:\n");
    gets(&verifica_medico);

    retorno = verificaMed();

    if (retorno == 1)
    {
        medico1[0] = '\0';
        data_consulta1[0] = '\0';
    }

    if (retorno == 2)
    {
        medico2[0] = '\0';
        data_consulta2[0] = '\0';
    }

    if (retorno == 3)
    {
        medico3[0] = '\0';
        data_consulta3[0] = '\0';
    }

    if(retorno < 1 || retorno > 3)
        printf("Medico inexistente\n");

    FILE *arquivo;
    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL)
    {
        arquivo = fopen("dados.txt", "w+");
    }

    retorno = 0;

    fwrite(&medico1, sizeof(medico1), 1, arquivo);
    fwrite(&medico2, sizeof(medico2), 1, arquivo);
    fwrite(&medico3, sizeof(medico3), 1, arquivo);
    fwrite(&data_consulta1, sizeof(data_consulta1), 1, arquivo);
    fwrite(&data_consulta2, sizeof(data_consulta2), 1, arquivo);
    fwrite(&data_consulta3, sizeof(data_consulta3), 1, arquivo);
    fclose(arquivo);

    system("pause");
    system("cls");
}

int menu()
{
    int choose;

    printf("1 - [Entrada de dados] \n2 - [Listar dados] Lista todos os dados na tela.\n3 - [Pesquisar medico] Pesquisa um medico pelo nome completo e mostra todo os dados na tela\n");
    printf("4 - [Pesquisar data] Pesquisa pela data de consulta e mostra todos na tela.\n5 - [Alterar dados] Pesquisa pelo nome completo do medico.\n");
    printf("6 - [Excluir dados] Pesquisa pelo nome completo do medico\n7 - Saida\n");

    scanf("%d", &choose);
    getchar(); // limpa buffer

    return choose;
}

int main()
{
    printf("\t\t\t\tBem-vindo ao Sistema de Consultas!\n\n\n\n");

    system("pause");
    system("cls");

    int escolhaMenu;
    do
    {
        do
        {
            escolhaMenu = menu();

            switch (escolhaMenu)
            {
            case 1:
                entradaDados();
                break;

            case 2:
                listarDados();
                break;

            case 3:
                pesquisaMedicos();
                break;

            case 4:
                pesquisaData();
                break;

            case 5:
                alterarDados();
                break;

            case 6:
                excluirDados();
                break;

            case 7:
                exit(0);

            default:
                printf("Escolha invalida\n");

                system("pause");
                system("cls");
            }
        } while (escolhaMenu != 7);
    } while (escolhaMenu > 7 || escolhaMenu <= 0);

    return 0;
}
