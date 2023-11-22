#define ex03
#include "stdio.h"
#include "stdlib.h"

//OBS.: Todos os programa devem ser finalizados pelo usuario.

#ifdef ex01
/*
    1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).
*/

int main()
{
    FILE *ptrArq;
    char recebeChar;
    char imprimeChar;
    char esc;

do
{

    if((ptrArq = fopen("arq.txt","w"))==NULL)
	{
        printf("Erro na abertura do arquivo.\n");
        exit(0);  //Encerra o programa
	}
    printf("Digite caracteres para serem armazenados ('0' finaliza o processo)\n");

    do
    {
        recebeChar = getchar();
        if(recebeChar != '0')
            putc(recebeChar, ptrArq);
    }while(recebeChar != '0');

    fclose(ptrArq);

    if((ptrArq = fopen("arq.txt","r"))==NULL)
	{
        printf("Erro na abertura do arquivo.\n");
        exit(0);  //Encerra o programa
	}

	printf("\nCaracteres digitados: ");
    do
    {
        imprimeChar = getc(ptrArq);
        putchar(imprimeChar);
    }while(imprimeChar != EOF);

    printf("\nDeseja encerrar o programa?\t(s/n)");
    getchar();
    scanf("%c",&esc);

}while(esc != 'S' && esc != 's');

    return 0;
}
#endif // ex1

#ifdef ex02
/*
    2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida
*/

struct dados
{
    char nome[20];
    char tel[15];
    int niverDia;
    int niverMes;
};

typedef struct dados dados;

void inserirContato(dados *ptrDados)
{
    FILE *ptrArq;

    if((ptrArq = fopen("dados.txt","w"))==NULL)
	{
        printf("Erro na abertura do arquivo.\n");
        exit(0);  //Encerra o programa
	}

	for(int i = 0; i < 4; i++)
    {
        printf("Digite o nome do %do medico a ser adicionado: \n",i+1);
        gets((ptrDados+i)->nome);

        printf("Digite o telefone do %do medico a ser adicionado: \n",i+1);
        gets((ptrDados+i)->tel);

        printf("Digite o dia do aniversario do %do medico a ser adicionado: \n",i+1);
        scanf("%d", &(ptrDados+i)->niverDia);
        getchar();

        printf("Digite o mes do aniversario do %do medico a ser adicionado: \n",i+1);
        scanf("%d", &(ptrDados+i)->niverMes);
        getchar();

        fwrite((ptrDados+i), sizeof(dados),1,ptrArq);
    }

    fclose(ptrArq);
}

void listarTodosContatos(dados *ptrDados)
{
    FILE *ptrArq;

    ptrArq = fopen("dados.txt", "r");

    for(int i = 0; i < 4; i++)
    {
        if((ptrDados+i)->nome[0] != '*')
        {
            printf("\nNome do contato: %s\n", (ptrDados+i)->nome);
            printf("Telefone do contato: %s\n", (ptrDados+i)->tel);
            printf("Aniversario do contato: %d/%d\n", (ptrDados+i)->niverDia, (ptrDados+i)->niverMes);
        }
    }
    fclose(ptrArq);
}

void pesquisarContatoNome(dados *ptrDados)
{

}

void pesquisarContatosLetra(dados *ptrDados)
{

}

void listarAniversariantes(dados *ptrDados)
{

}

void alterarContato(dados *ptrDados)
{

}

void excluirContato(dados *ptrDados)
{

}

int main()
{
    dados cadastrados[4];
    dados *ptrDados = &cadastrados[0];
    char select;

    do
    {
        printf("\n\tMENU");
        printf("\n[1] - Inserir contato\n[2] - Listar todos os contatos\n[3] - Pesquisar um contato pelo nome\n[4] - Listar os contatos cujo nome inicia com a letra digitada\n[5] - Imprimir os aniversariantes do mês.\n[6] - Alterar contato\n[7] - Excluir contato\n[8] - Sair\n");
        scanf("%c", &select);
        getchar(); //Limpa o buffer

        switch(select)
        {
        case '1':
            inserirContato(ptrDados);
            break;

        case '2':
            listarTodosContatos(ptrDados);
            break;

        case '3':
            pesquisarContatoNome(ptrDados);
            break;

        case '4':
            pesquisarContatosLetra(ptrDados);
            break;

        case '5':
            listarAniversariantes(ptrDados);
            break;

        case '6':
            alterarContato(ptrDados);
            break;

        case '7':
            excluirContato(ptrDados);
            break;

        case '8':
            exit(0);

        default:
            printf("Opcao invalida, tente novamente.\n");
        }

    }while(select != 8);

    return 0;
}
#endif // ex2

#ifdef ex03
/*
    3 - Escreva um programa para o controle de mercadorias em uma dispensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida
*/
struct produtos
{
    char nomeProduto[20], codigoProduto[5];
    int quantidade;
};

void registro(FILE *pfile, struct produtos *ptr)
{
    char ch;
    char codigoLocal[5];
    int i;

    // abre o arquivo para adicionar dados
    pfile = fopen("dados.txt", "a");

    // se n existir,cria o arquivo
    if (pfile == NULL)
    {
        pfile = fopen("dados.txt", "w+");
    }

    do
    {
        printf("\nDigite o nome do produto:\n");
        gets(ptr->nomeProduto);
        printf("Digite o codigo do produto:\n");
        gets(ptr->codigoProduto);
        printf("Digite a quantidade do produto:\n");
        scanf("%d", &(ptr->quantidade));
        getchar();

        fwrite(ptr, sizeof(struct produtos), 1, pfile);

        printf("Deseja adicionar outro produto? (s) ou (n)\n");

        ch = getchar();
        getchar();

    } while (ch != 'n' && ch != 'N');
    fclose(pfile);
}

void listarProdutos(FILE *pfile, struct produtos *ptr)
{
    pfile = fopen("dados.txt", "r");

    while(fread(ptr, sizeof(struct produtos), 1, pfile) == 1)
    {
        if(ptr->nomeProduto[0] != '*' && ptr->quantidade != 0)
        {
        printf("\nNome do produto: %s\n", ptr->nomeProduto);
        printf("Codigo do cliente: %s\n", ptr->codigoProduto);
        printf("Quantidade: %d\n", ptr->quantidade);
        }
    }

    fclose(pfile);
}

void pesquisaProdutos(FILE *pfile, struct produtos *ptr)
{
    int i = 0;
    char nomeLocal[20];
    printf("Qual o nome do registro que voce deseja buscar?\n");
    gets(nomeLocal);

    pfile = fopen("dados.txt", "r");

    while (fread(ptr, sizeof(struct produtos), 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeProduto[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeProduto[i])
            {
                break;
            }
        }
            if (nomeLocal[i] == '\0' && ptr->nomeProduto[i] == '\0')
            {
                printf("\nNome do produto: %s\n", ptr->nomeProduto);
                printf("Codigo do produto: %s\n", ptr->codigoProduto);
                printf("Quantidade: %d\n\n", ptr->quantidade);
                break;
            }
    }
    fclose(pfile);
}

void listarProdutosNaoDisp(FILE *pfile, struct produtos *ptr)
{
    pfile = fopen("dados.txt", "r");

    while(fread(ptr, sizeof(struct produtos), 1, pfile) == 1)
    {
        if(ptr->quantidade == 0)
        {
            printf("Nome do produto: %s\n", ptr->nomeProduto);
            printf("Codigo do cliente: %s\n", ptr->codigoProduto);
            printf("Quantidade: %d\n", ptr->quantidade);
        }
    }

    fclose(pfile);
}

void alterarQuantidade(FILE *pfile, struct produtos *ptr)
{
    char nomeLocal[20];
    int i = 0, procura;
    procura = -sizeof(ptr->quantidade);

    printf("Qual o nome do registro que voce deseja alterar?\n");
    gets(nomeLocal);

    pfile = fopen("dados.txt", "r+");

    while (fread(ptr, sizeof(struct produtos), 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeProduto[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeProduto[i])
            {
                break;
            }
        }
            if (nomeLocal[i] == '\0' && ptr->nomeProduto[i] == '\0')
            {

                printf("Digite a nova quantidade do produto:\n");
                scanf("%d",&(ptr->quantidade));
                getchar();

                fseek(pfile, procura, 1);

                fwrite(&(ptr->quantidade), sizeof(ptr->quantidade), 1, pfile);
                break;
            }
    }
    printf("%d",ptr->quantidade);
    fclose(pfile);
}

void alteraRegistro(FILE *pfile, struct produtos *ptr)
{
    char nomeLocal[20];
    int i = 0, procura;
    procura = -sizeof(struct produtos);

    printf("Qual o nome do registro que voce deseja alterar?\n");
    gets(nomeLocal);
    pfile = fopen("dados.txt", "r+");

    while (fread(ptr, sizeof(struct produtos), 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeProduto[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeProduto[i])
            {
                break;
            }
        }
            if (nomeLocal[i] == '\0' && ptr->nomeProduto[i] == '\0')
            {

                printf("Digite o novo nome do produto:\n");
                gets(ptr->nomeProduto);
                printf("Digite o novo codigo do produto:\n");
                gets(ptr->codigoProduto);
                printf("Digite a nova quantidade do produto:\n");
                scanf("%d",&(ptr->quantidade));
                getchar();

                fseek(pfile, procura, 1);
                fwrite(ptr, sizeof(struct produtos), 1, pfile);
                break;
            }
    }
    fclose(pfile);
}

void excluiRegistro(FILE *pfile, struct produtos *ptr)
{
    char nomeLocal[20];
    int i = 0;
    printf("Qual o nome do registro que voce deseja excluir?\n");
    gets(nomeLocal);
    pfile = fopen("dados.txt", "r+");


    while (fread(ptr, sizeof(struct produtos), 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nomeProduto[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nomeProduto[i])
            {
                break;
            }
        }
            if (nomeLocal[i] == '\0' && ptr->nomeProduto[i] == '\0')
            {
                ptr->nomeProduto[0] = '*';

                fseek(pfile, -sizeof(struct produtos), 1);
                fwrite(ptr, sizeof(struct produtos), 1, pfile);
                break;

            }
    }
    fclose(pfile);
}

int main()
{
    int menu;
    FILE *pFile;

    struct produtos cliente, *ptr;
    ptr = &cliente;

    do
    {
        printf("\n\tMENU");
        printf("\n1-Incluir produtos\n2-Listar todos os produtos\n3-Pesquisar mercadoria por descricao\n4- Listar os produtos nao disponiveis\n5- Alterar quantidade atual\n6-Alterar produtos\n7-Excluir produtos\n8-Sair\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &menu);
        getchar(); // limpa buffer
        switch (menu)
        {
        case 1:
            registro(pFile, ptr);
            break;
        case 2:
            listarProdutos(pFile, ptr);
            break;
        case 3:
            pesquisaProdutos(pFile, ptr);
            break;
        case 4:
            listarProdutosNaoDisp(pFile, ptr);
            break;
        case 5:
            alterarQuantidade(pFile, ptr);
            break;
        case 6:
            alteraRegistro(pFile,ptr);
            break;
        case 7:
            excluiRegistro(pFile, ptr);
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("Opcao inválida, tente novamente.");
        }
    } while (menu != 8);

    return 0;
}
#endif // ex3

#ifdef ex04
/*4 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/

struct cadastro
{

    char nome[20], email[40], nCelular[14];
};

void registro(FILE *pfile, struct cadastro *ptr)
{
    char ch;
    // abre o arquivo para adicionar dados
    pfile = fopen("dados.txt", "a");

    // se n existir,cria o arquivo
    if (pfile == NULL)
    {
        pfile = fopen("dados.txt", "w+");
    }

    do
    {
        printf("Digite o nome do cliente:\n");
        gets(ptr->nome);
        printf("Digite o email do cliente:\n");
        gets(ptr->email);
        printf("Digite o numero do cliente:\n");
        gets(ptr->nCelular);

        fwrite(ptr, sizeof(struct cadastro), 1, pfile);

        printf("Deseja adicionar outro cliente? (s) ou (n)\n");

        ch = getchar();
        getchar();

    } while (ch != 'n' && ch != 'N');
    fclose(pfile);
}

void listarRegistro(FILE *pfile, struct cadastro *ptr)
{
    pfile = fopen("dados.txt", "r");

    if(pfile == NULL)
    {
        printf("ERRO! O documento ainda nao foi criado.");
        exit(0);
    }
    
    while (fread(ptr, sizeof(struct cadastro), 1, pfile) == 1)
    {
        if(ptr->nome[0] != '*')
        {
        printf("Nome do cliente: %s\n", ptr->nome);
        printf("Email do cliente: %s\n", ptr->email);
        printf("Numero do cliente: %s\n", ptr->nCelular);
        }
    }

    fclose(pfile);
}

void pesquisaRegistro(FILE *pfile, struct cadastro *ptr)
{
    int i = 0;
    char nomeLocal[20];
    printf("Qual o nome do registro que voce deseja buscar?\n");
    gets(nomeLocal);

    pfile = fopen("dados.txt", "r");

    
    while (fread(ptr, sizeof(struct cadastro), 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nome[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nome[i])
            {
                break;
            }
        }
            if (nomeLocal[i] == '\0' && ptr->nome[i] == '\0')
            {
                printf("\nNome do cliente: %s\n", ptr->nome);
                printf("Email do cliente: %s\n", ptr->email);
                printf("Numero do cliente: %s\n\n", ptr->nCelular);
                break;
            }
    }
    fclose(pfile);
}

void alteraRegistro(FILE *pfile, struct cadastro *ptr)
{
    char nomeLocal[20];
    int i = 0;
    printf("Qual o nome do registro que voce deseja alterar?\n");
    gets(nomeLocal);
    pfile = fopen("dados.txt", "r+");

     //tirar
    while (fread(ptr, sizeof(struct cadastro), 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nome[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nome[i])
            {
                break;
            }
        }
            if (nomeLocal[i] == '\0' && ptr->nome[i] == '\0')
            {

                printf("Digite o novo nome do cliente:\n");
                gets(ptr->nome);
                printf("Digite o novo email do cliente:\n");
                gets(ptr->email);
                printf("DIgite o novo numero do cliente:\n");
                gets(ptr->nCelular);
                fseek(pfile, -sizeof(struct cadastro), 1);
                fwrite(ptr, sizeof(struct cadastro), 1, pfile);
                break;

            }
    }
    fclose(pfile);
}

void excluiRegistro(FILE *pfile, struct cadastro *ptr)
{
    char nomeLocal[20];
    int i = 0;
    printf("Qual o nome do registro que voce deseja alterar?\n");
    gets(nomeLocal);
    pfile = fopen("dados.txt", "r+");


    while (fread(ptr, sizeof(struct cadastro), 1, pfile) == 1)
    {
        for (i = 0; nomeLocal[i] != '\0' || ptr->nome[i] != '\0'; i++)
        {
            if (nomeLocal[i] != ptr->nome[i])
            {
                break;
            }
        }
            if (nomeLocal[i] == '\0' && ptr->nome[i] == '\0')
            {
                ptr->nome[0] = '*';
                fseek(pfile, -sizeof(struct cadastro), 1);
                fwrite(ptr, sizeof(struct cadastro), 1, pfile);
                break;

            }
    }
    fclose(pfile);
}




    

int main()
{
    int menu;
    FILE *pFile;

    typedef struct cadastro cadastro;
    cadastro cliente, *ptr;
    ptr = &cliente;

    do
    {
        printf("1-Inclui Registros\n2-Listar Registros\n3-Pesquisar Registro\n4-Alterar Registro\n5-Excluir Registro\n6-Sair\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &menu);
        getchar(); // limpa buffer
        switch (menu)
        {
        case 1:
            registro(pFile, ptr);
            break;
        case 2:
            listarRegistro(pFile, ptr);
            break;
        case 3:
            pesquisaRegistro(pFile, ptr);
            break;
        case 4:
            alteraRegistro(pFile,ptr);
            break;
        case 5:
            excluiRegistro(pFile, ptr);
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("Opcao inválida, tente novamente.");
        }
    } while (menu != 6);

    return 0;
}

#endif