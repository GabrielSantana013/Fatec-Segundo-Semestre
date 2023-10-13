/*

1 – Pesquise as funções de biblioteca abaixo que manipulam arquivos.
fopen();
fclose();
fwrite(); cuidado com esta função
fread(); cuidado com esta função
exit(0);
2 - Escreva um programa que tem 3 vetores unidimensionais medico[20] e 3
vetores unidimensionais dataConsulta[11] declarados como variáveis globais.
Na função main() faça um menu com as seguintes opções:
1 – Entrada de dados.
2 – Lista todos os dados na tela.
3 – Pesquisa um médico pelo nome completo e mostra todo os dados na tela
4 – Pesquisa pela data de consulta e mostra todos na tela.
5 – Altera dados. Pesquisa pelo nome completo do médico.
6 – Exclui dados. Pesquisa pelo nome completo do médico.
7 – Saída
Os 6 vetores devem ser escritos e lidos em um arquivo.
Cada uma das opções do menu é uma função no programa.
Não pode usar nenhuma função de biblioteca a não ser as 6 da apostila e as
funções de manipulação de arquivos pesquisadas.
Os vetores dos médicos são as chaves primárias do banco de dados. Portanto
não pode ter 2 médicos com nomes iguais
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char medicoUm[20];
char medicoDois[20];
char medicoTres[20];
char dataconsultaUm[11];
char dataConsultaDois[11];
char dataConsultaTres[11];

char tempNomeMedico[20];
char tempDataConsulta[11];

void atualizaMedicoDataConsultaPeloArquivo()
{
    FILE *arquivo;
    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de dados.\nTalvez ele não tenha sido criado na pasta do executavel compilado?\n");
        exit(0);
    }
    fread(&medicoUm, sizeof(medicoUm), 1, arquivo);
    fread(&medicoDois, sizeof(medicoDois), 1, arquivo);
    fread(&medicoTres, sizeof(medicoTres), 1, arquivo);
    fread(&dataconsultaUm, sizeof(dataconsultaUm), 1, arquivo);
    fread(&dataConsultaDois, sizeof(dataConsultaDois), 1, arquivo);
    fread(&dataConsultaTres, sizeof(dataConsultaTres), 1, arquivo);
    fclose(arquivo);
}

int pesquisaMedicosPelaData()
{
    printf("[MEDICOS COM CONSULTA EM %s]\n\n", tempDataConsulta);
    int i;
    int osMedicosSaoIguais = 0;
    int encontrouMedico = 0;


    for (i = 0; i < 11; i++)
    {
        if (dataconsultaUm[i] == tempDataConsulta[i])
            osMedicosSaoIguais = 1;
        else
        {
            osMedicosSaoIguais = 0;
            break;
        }
    }
    if (osMedicosSaoIguais == 1)
    {
        printf("Médico: %s\n", medicoUm);
        encontrouMedico = 1;
    }


    for (i = 0; i < 11; i++)
    {
        if (dataConsultaDois[i] == tempDataConsulta[i])
            osMedicosSaoIguais = 1;
        else
        {
            osMedicosSaoIguais = 0;
            break;
        }
    }
    if (osMedicosSaoIguais == 1)
    {
        printf("Médico: %s\n", medicoDois);
        encontrouMedico = 1;
    }


    for (i = 0; i < 11; i++)
    {
        if (dataConsultaTres[i] == tempDataConsulta[i])
            osMedicosSaoIguais = 1;
        else
        {
            osMedicosSaoIguais = 0;
            break;
        }
    }
    if (osMedicosSaoIguais == 1)
    {
        printf("Médico: %s\n", medicoTres);
        puts(dataConsultaTres);
        encontrouMedico = 1;
    }

    // Se o programa achou algum medico, retorna 1. Se não, retorna 0.
    return encontrouMedico;
}
void buscaPorMedicosNaData()
{
    printf("[+] Entre com a data a ser buscada: ");
    gets(tempDataConsulta);
    int encontrouAlgumMedico = pesquisaMedicosPelaData();
    if (encontrouAlgumMedico)
        printf("\n[SUCESSO] Medicos foram encontrado na data especificada.\n");
    else
        printf("\n[ERRO] Nao foram encontrados medicos na data especificada.\n");
}

int buscaMedicoComMesmoNome()
{
    // Retorna qual posição o nome se encontra. Se encontrou o nome no medicoDois, retorna 2.
    // Caso nao encontre nenhum, retorna 0.
    int i;
    for (i = 0; medicoUm[i] != '\0' || tempNomeMedico[i] != '\0'; i++)
    {
        if (medicoUm[i] != tempNomeMedico[i])
        break;
    }
    if (medicoUm[i]=='\0')
        return 1;


    for (i = 0; medicoUm[i] != '\0' || tempNomeMedico[i] != '\0'; i++)
    {
        if (medicoDois[i] != tempNomeMedico[i])
        break;
    }
    if (medicoDois[i]=='\0')
        return 2;



    for (i = 0; medicoUm[i] != '\0' || tempNomeMedico[i] != '\0'; i++)
    {
        if (medicoTres[i] != tempNomeMedico[i])
        break;
    }
    if (medicoTres[i]=='\0')
        return 3;


    return 0;
}
void pesquisaMedicoNome()
{
    printf("[+] Entre com o nome do medico: ");
    gets(tempNomeMedico);
    int indexadorDoMedico = buscaMedicoComMesmoNome();
    if (indexadorDoMedico == 1)
    {   
        printf("Médico encontrado.\nMédico: %-20s\tConsulta: %-11s\n", medicoUm, dataconsultaUm);
    }
    else if (indexadorDoMedico == 2)
    {
        printf("Médico encontrado.\nMédico: %-20s\tConsulta: %-11s\n", medicoDois, dataConsultaDois);
    }
    else if (indexadorDoMedico == 3)
    {
        printf("Médico encontrado.\nMédico: %-20s\tConsulta: %-11s\n", medicoTres, dataConsultaTres);
    }
    else
    {
        printf("\n[ERRO] Medico nao encontrado. Tente novamente.");
    }
}
void salvarDados()
{
    FILE *arquivo;
    arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(0);
    }
    fwrite(&medicoUm, sizeof(medicoUm), 1, arquivo);
    fwrite(&medicoDois, sizeof(medicoDois), 1, arquivo);
    fwrite(&medicoTres, sizeof(medicoTres), 1, arquivo);
    fwrite(&dataconsultaUm, sizeof(dataconsultaUm), 1, arquivo);
    fwrite(&dataConsultaDois, sizeof(dataConsultaDois), 1, arquivo);
    fwrite(&dataConsultaTres, sizeof(dataConsultaTres), 1, arquivo);
    fclose(arquivo);
}
void listaDados()
{
    atualizaMedicoDataConsultaPeloArquivo();
    printf("[LISTA DE MEDICOS E CONSULTAS]\n");
    if(medicoUm[0]!='\0')
    printf("\nNome: %-20s \t Data da consulta: %-11s", medicoUm, dataconsultaUm); 
    if(medicoDois[0]!='\0')
    printf("\nNome: %-20s \t Data da consulta: %-11s", medicoDois, dataConsultaDois);
    if(medicoTres[0]!='\0')
    printf("\nNome: %-20s \t Data da consulta: %-11s", medicoTres, dataConsultaTres);
    printf("\n\n");
}

void entradaDados()
{
    fflush(stdin);
    printf("[1/3] Entre com o nome do medico: ");
    gets(medicoUm);
    printf("[1/3] Entre com a data da consulta: ");
    gets(dataconsultaUm);
    printf("[2/3] Entre com o nome do medico: ");
    gets(medicoDois);
    printf("[2/3] Entre com a data da consulta: ");
    gets(dataConsultaDois);
    printf("[3/3] Entre com o nome do medico: ");
    gets(medicoTres);
    printf("[3/3] Entre com a data da consulta: ");
    gets(dataConsultaTres);
    salvarDados();
}
void alteraDados(int identificadorMedico)
{
    int i = 0;
    switch (identificadorMedico)
    {
    case 1:

        while (tempNomeMedico[i] != '\0')
        {
            medicoUm[i] = tempNomeMedico[i];
            i++;
        }
        medicoUm[i] = '\0';
        i=0;
        while (tempDataConsulta[i] != '\0')
        {
            dataconsultaUm[i] = tempDataConsulta[i];
            i++;
        }
        dataconsultaUm[i] = '\0';
        break;

    case 2:
         while (tempNomeMedico[i] != '\0')
        {
            medicoDois[i] = tempNomeMedico[i];
            i++;
        }
        medicoDois[i] = '\0';
        i=0;
        while (tempDataConsulta[i] != '\0')
        {
            dataConsultaDois[i] = tempDataConsulta[i];
            i++;
        }
        dataConsultaDois[i] = '\0';
        break;

    case 3:
        while (tempNomeMedico[i] != '\0')
        {
            medicoTres[i] = tempNomeMedico[i];
            i++;
        }
        medicoTres[i] = '\0';
        i=0;
        while (tempDataConsulta[i] != '\0')
        {
            dataConsultaTres[i] = tempDataConsulta[i];
            i++;
        }
        dataConsultaTres[i] = '\0';
        break;

    default:
        break;
    }

    salvarDados();
}
int buscaAlteraDados()
{
    printf("[BUSCAR] Entre com o nome do medico: ");
    gets(tempNomeMedico);
    int verificaMedicoExistente = buscaMedicoComMesmoNome();

    if (verificaMedicoExistente == 0 || verificaMedicoExistente > 3)
    {
        printf("[ERRO] Nenhum medico encontrado com esse nome.");
        return 0;
    }

    int checaNomeRepetido = 0;
    do
    {
        printf("[+] Entre com o novo nome: ");
        gets(tempNomeMedico);
        checaNomeRepetido = buscaMedicoComMesmoNome();

        if (checaNomeRepetido > 0)
            printf("[ERRO] Nome do medico ja existente.\n");
        else{
            printf("[+] Entre com a nova data da consulta: ");
            gets(tempDataConsulta, 11);
            alteraDados(verificaMedicoExistente);
        }
    } while (checaNomeRepetido != 0);
}
void deletaDados(int identificadorMedico){
    switch (identificadorMedico)
    {
    case 1:
        medicoUm[0] = '\0';
        dataconsultaUm[0] = '\0';
        break;

    case 2:
        medicoDois[0] = '\0';
        dataConsultaDois[0] = '\0';
        break;
    
    case 3:
        medicoTres[0] = '\0';
        dataConsultaTres[0] = '\0';
    
    default:
        break;
    }
    salvarDados();

}
void buscaDeletaDados(){
    printf("[BUSCAR] Entre com o nome do medico: ");
    gets(tempNomeMedico);
    int verificaMedicoExistente = buscaMedicoComMesmoNome();
    if (verificaMedicoExistente == 0 || verificaMedicoExistente > 3)
    {
        printf("[ERRO] Nenhum medico encontrado com esse nome.");
        return 0;
    }
    deletaDados(verificaMedicoExistente);

}
int main()
{
    int opcaoUsuario = 0;
    atualizaMedicoDataConsultaPeloArquivo();
    do
    {
        printf("Entre com a opcao que deseja: \n");
        printf("[1] Entrada de dados\n");
        printf("[2] Lista todos os dados na tela\n");
        printf("[3] Pesquisa um médico pelo nome completo e mostra todos os dados na tela\n");
        printf("[4] Pesquisa pela data de consulta e mostra todos na tela\n");
        printf("[5] Altera dados. Pesquisa pelo nome completo do médico\n");
        printf("[6] Exclui dados. Pesquisa pelo nome completo do médico\n");
        printf("[7] Saída\n");
        printf("[SELECIONAR] Item: ");
        scanf("%d", &opcaoUsuario);
        getchar();
        switch (opcaoUsuario)
        {
        case 1:
            entradaDados();
            break;
        case 2:
            listaDados();
            break;
        case 3:
            pesquisaMedicoNome();
            getchar();
            break;
        case 4:
            buscaPorMedicosNaData();
            getchar();
            break;
        case 5:
            buscaAlteraDados();
            getchar();
            break;
        case 6:
            buscaDeletaDados();
            getchar();
            break;
        case 7:
            exit(0);
            break;
        }
    } while (!(opcaoUsuario > 0 && opcaoUsuario < 8) || !(opcaoUsuario == 7));
}