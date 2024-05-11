#include<stdio.h>
#include<locale.h>
FILE * dados;

/*****************************************************************************

			DESAFIO

*******************************************************************************/

//variáveis globais

char produto[3][25];
int quantidade[3];
int zeroProdutos, todosExcluidos=3;


//funções do programa

void Entrada(int vz)
{
    int a[3]= {0,0,0};
    int cont,cont2,cont3,igual,qt;
    char nomept[25];



    printf("\n\n >> OPÇÃO 1 - ENTRADA DE DADOS <<\n\n\n");

    if(vz==0)
    {
        dados = fopen("banco_de_dados.txt", "w");

        for (cont = 0; cont < 3; cont++)
        {
            do
            {
                igual = 0;
                printf("Digite o nome do produto: ");
                scanf("%24s", produto[cont]);
                while (getchar() != '\n');
                fwrite(&produto[cont], sizeof(produto[cont]), 1, dados);

                for (cont2 = 0; cont2 < cont; cont2++)
                {
                    for (cont3=0; produto[cont][cont3] != '\0' && produto[cont2][cont3] != '\0'; cont3++)
                    {
                        if (produto[cont][cont3] != produto[cont2][cont3])
                        {
                            break;
                        }
                    }

                    if (produto[cont][cont3] == '\0' && produto[cont2][cont3] == '\0')
                    {
                        igual = 1;
                        break;
                    }
                }

                if (igual)
                {
                    printf("Produto já cadastrado! Digite um produto diferente.\n");
                }

            }
            while (igual);

            do
            {
                printf("Digite a quantidade do produto: ");
                scanf("%d", &quantidade[cont]);
                if (quantidade[cont] < 0 || quantidade[cont] == 10)
                {
                    printf("Quantidade deve ser maior que 0 e difrente de 10 - Digite novamente.\n\n");
                }
            }
            while(quantidade[cont] < 0 || quantidade[cont] == 10);
            fwrite(&quantidade[cont], sizeof(quantidade[cont]), 1, dados);

            printf("\n");
            todosExcluidos--;
            zeroProdutos=1;
        }

        printf("\nProdutos cadastrados: \n\n");
        for (cont = 0; cont < 3; cont++)
        {
            printf("Produto %d: %s\n", cont + 1, produto[cont]);
            printf("Quantidade: %d\n\n", quantidade[cont]);
        }

        printf("\n");
        fclose(dados);
    }
    else
    {
        dados = fopen("banco_de_dados.txt", "w");

        for(cont=0; cont<3; cont++)
        {
            if(produto[cont][0]=='*')
            {
                do
                {
                    igual = 0;
                    printf("Digite o nome do produto: ");
                    scanf("%24s", produto[cont]);
                    while (getchar() != '\n');

                    for (cont2 = 0; cont2 < cont; cont2++)
                    {
                        for (cont3=0; produto[cont][cont3] != '\0' && produto[cont2][cont3] != '\0'; cont3++)
                        {
                            if (produto[cont][cont3] != produto[cont2][cont3])
                            {
                                break;
                            }
                        }
                        if (produto[cont][cont3] == '\0' && produto[cont2][cont3] == '\0')
                        {
                            igual = 1;
                            break;
                        }
                    }

                    if (igual)
                    {
                        printf("Produto já cadastrado! Digite um produto diferente.\n");
                    }

                }
                while (igual);

                do
                {
                    printf("Digite a quantidade do produto: ");
                    scanf("%d", &quantidade[cont]);
                    if (quantidade[cont] < 0 || quantidade[cont] == 10)
                    {
                        printf("Quantidade deve ser maior que 0 e difrente de 10 - Digite novamente.\n\n");
                    }
                }
                while(quantidade[cont] < 0 || quantidade[cont] == 10);

                printf("\n");
                todosExcluidos--;
                zeroProdutos=1;
                a[cont]=1;
            }

            else
            {
                a[cont]=0;
            }
        }

        for (cont = 0; cont < 3; cont++)
        {
            fwrite(&produto[cont], sizeof(produto[cont]), 1, dados);
            fwrite(&quantidade[cont], sizeof(quantidade[cont]), 1, dados);
        }

        if (a[0]==0 && a[1]==0 && a[2]==0)
        {
            printf("Não há espaço para mais produtos\n\n");
        }
        else
        {
            printf("\nProdutos cadastrados: \n\n");
            for (cont = 0; cont < 3; cont++)
            {
                printf("Produto %d: %s\n", cont + 1, produto[cont]);
                printf("Quantidade: %d\n\n", quantidade[cont]);
            }
        }
        printf("\n");
        fclose(dados);
    }
}


void Listagem(int vz)
{
    int cont,encontrado=0,qt;
    int a[3]= {0,0,0};
    char nomept[25];

    dados = fopen("banco_de_dados.txt", "r");

    printf("\n\n >> OPÇÃO 2 - LISTAGEM DE DADOS <<\n\n\n");
    if(vz>0 || zeroProdutos !=0)
    {
        for(cont=0; cont<3; cont++)
        {
            fread(&nomept, sizeof(produto[cont]), 1, dados);
            fread(&qt, sizeof(quantidade[cont]), 1, dados);

            if(produto[cont][0]!='*')
            {
                if (encontrado==0)
                {
                    printf("Produto(s) encontrado(s): \n\n");
                    encontrado=1;
                }
                printf("Produto: %s\n",nomept);
                printf("Quantidade: %d\n\n",qt);
                a[cont]=1;
            }
            else
            {
                a[cont]=0;
            }
        }

        if(a[0]==0 && a[1]==0 && a[2]==0)
        {
            printf("Todos os produtos foram apagados.\n\n");
        }
    }

    else
    {
        printf("Não há produtos para listar.\n\n");
    }
    printf("\n");
    fclose(dados);
}


void PesquisaCompleta(int vz)
{
    char nome[25],nomept[25];
    int a[3]= {0,0,0};
    int cont,cont2,encontrado=0,qt;

    dados = fopen("banco_de_dados.txt", "r");

    printf("\n\n >> OPÇÃO 3 - PESQUISA PRODUTO POR NOME COMPLETO <<\n\n\n");
    if(vz>0 && zeroProdutos !=0)
    {
        printf("Digite o nome completo do produto para pesquisar: ");
        scanf("%24s",nome);
        while (getchar() != '\n');

        for(cont=0; cont<3; cont++)
        {
            fread(&nomept, sizeof(produto[cont]), 1, dados);
            fread(&qt, sizeof(quantidade[cont]), 1, dados);

            for (cont2 = 0; nome[cont2] != '\0' && nomept[cont2] != '\0'; cont2++)
            {
                if (nome[cont2] != nomept[cont2])
                {
                    break;
                }
            }

            if (nome[cont2] == '\0' && nomept[cont2] == '\0')
            {
                if (encontrado==0)
                {
                    printf("\n\nProduto encontrado: \n\n");
                    encontrado=1;
                }
                printf("Produto: %s\n", nomept);
                printf("Quantidade: %d\n\n", qt);
                a[cont]=1;
            }
            else
            {
                a[cont]=0;
            }
        }

        if(a[0]==0 && a[1]==0 && a[2]==0)
        {
            printf("\n\nProduto não encontrado.\n\n");
        }
    }

    else
    {
        printf("Não há produtos para realizar a pesquisa.\n\n");
    }

    printf("\n");
    fclose(dados);
}


void PesquisaSimples(int vz)
{
    char letra[2],nomept[25];
    int a[3]= {0,0,0};
    int cont,cont2,encontrado=0,qt;

    dados = fopen("banco_de_dados.txt", "r");

    printf("\n\n >> OPÇÃO 4 - PESQUISA PRODUTO PELA PRIMEIRA LETRA <<\n\n\n");
    if(vz>0 && zeroProdutos !=0)
    {

        printf("Digite a primeira letra do nome do produto para pesquisar: ");
        scanf("%1s",letra);
        while (getchar() != '\n');

        for(cont=0; cont<3; cont++)
        {
            fread(&nomept, sizeof(produto[cont]), 1, dados);
            fread(&qt, sizeof(quantidade[cont]), 1, dados);

            if(letra[0]==nomept[0])
            {
                if (encontrado==0)
                {
                    printf("\n\nProduto(s) encontrado(s) com a letra '%c': \n\n",letra[0]);
                    encontrado=1;
                }

                printf("Produto: %s\n", nomept);
                printf("Quantidade: %d\n\n", qt);
                a[cont]=1;
            }

            else
            {
                a[cont]=0;
            }
        }

        if(a[0]==0 && a[1]==0 && a[2]==0)
        {
            printf("\n\nProduto(s) iniciado(s) com a letra '%c' não encontrado(s).\n\n",letra[0]);;
        }
    }

    else
    {
        printf("Não há produtos para realizar a pesquisa.\n\n");
    }

    printf("\n");
    fclose(dados);
}


void AlterarDados(int vz)
{
    char nome[25], produtoAnterior[25];
    int a[3]= {0,0,0};
    int cont=0,cont2,cont3,igual,quantidadeAnterior;

    dados = fopen("banco_de_dados.txt", "w");

    printf("\n\n >> OPÇÃO 5 - ALTERAR NOME DO PRODUTO <<\n\n\n");

    if(vz>0 && zeroProdutos !=0)
    {
        printf("Digite o nome completo do produto que será alterado: ");
        scanf("%24s",nome);
        while (getchar() != '\n');
        printf("\n");

        for(cont=0; cont<3; cont++)
        {
            for (cont2 = 0; nome[cont2] != '\0' && produto[cont][cont2] != '\0'; cont2++)
            {
                if (nome[cont2] != produto[cont][cont2])
                {
                    break;
                }
            }

            if (nome[cont2] == '\0' && produto[cont][cont2] == '\0')
            {
                int i;
                for (i=0; produto[cont][i] != '\0' && i < 24; i++)
                {
                    produtoAnterior[i] = produto[cont][i];
                }
                produtoAnterior[i] = '\0';
                quantidadeAnterior = quantidade[cont];

                printf("\nDigite o nome do novo produto: ");
                scanf("%24s",produto[cont]);
                while (getchar() != '\n');

                do
                {
                    printf("Digite a quantidade do novo produto: ");
                    scanf("%d", &quantidade[cont]);
                    printf("\n");
                    if (quantidade[cont] < 0 || quantidade[cont] == 10)
                    {
                        printf("Quantidade deve ser maior que 0 e difrente de 10 - Digite novamente.\n\n");
                    }
                }
                while(quantidade[cont] < 0 || quantidade[cont] == 10);
                printf("\n");
                a[cont]=1;

                printf("Alterações feitas: \n\n");
                printf("Produto anterior: %s\n",produtoAnterior);
                printf("Quandidade: %d\n\n",quantidadeAnterior);
                printf("Novo produto: %s\n",produto[cont]);
                printf("Quantidade: %d\n\n",quantidade[cont]);
            }
            else
            {
                a[cont]=0;
            }
        }

        for (cont = 0; cont < 3; cont++)
        {
            fwrite(&produto[cont], sizeof(produto[cont]), 1, dados);
            fwrite(&quantidade[cont], sizeof(quantidade[cont]), 1, dados);
        }

        if(a[0]==0 && a[1]==0 && a[2]==0)
        {
            printf("\nProduto não encontrado.\n\n");
        }
    }
    else
    {
        printf("Não há produtos para realizar a alteração dos dados.\n\n");
    }

    printf("\n");
    fclose(dados);
}


void Excluir(int vz)
{

    char nome[25];
    int a[3]= {0,0,0};
    int cont,cont2;

    char produtoAnterior[25];
    int quantidadeAnterior, encontrado=0;


    printf("\n\n >> OPÇÃO 6 - EXCLUIR PRODUTO DA LISTA <<\n\n\n");
    if(vz>0 && zeroProdutos !=0)
    {
        printf("Digite o nome comleto do produto que será excluído: ");
        scanf("%24s",nome);
        while (getchar() != '\n');

        for(cont=0; cont<3; cont++)
        {
            for (cont2 = 0; nome[cont2] != '\0' && produto[cont][cont2] != '\0'; cont2++)
            {
                if (nome[cont2] != produto[cont][cont2])
                {
                    break;
                }
            }

            if (nome[cont2] == '\0' && produto[cont][cont2] == '\0')
            {

                int i;
                for (i=0; produto[cont][i] != '\0' && i < 24; i++)
                {
                    produtoAnterior[i] = produto[cont][i];
                }
                produtoAnterior[i] = '\0';
                quantidadeAnterior = quantidade[cont];


                produto[cont][0]='*';
                quantidade[cont]=0;
                a[cont]=1;
                todosExcluidos++;

                if (encontrado==0)
                {
                    printf("\n\nProduto excluído: \n\n");
                    encontrado++;
                }
                printf("Produto: %s\n",produtoAnterior);
                printf("Quantidade: %d\n\n",quantidadeAnterior);

            }
            else
            {
                a[cont]=0;
            }

            if(todosExcluidos==3)
            {
                zeroProdutos=0;
            }
        }
        dados = fopen("banco_de_dados.txt", "w");

        for (cont = 0; cont < 3; cont++)
        {
            fwrite(&produto[cont], sizeof(produto[cont]), 1, dados);
            fwrite(&quantidade[cont], sizeof(quantidade[cont]), 1, dados);
        }
        fclose(dados);

        if(a[0]==0 && a[1]==0 && a[2]==0)
        {
            printf("\n\nProduto não encontrado.\n\n");
        }
    }
    else
    {
        printf("Não há produtos para excluir.\n\n");
    }

    printf("\n");

}


int main()
{
    setlocale(LC_ALL,"Portuguese");

    int op,vz=0,cont;

    dados = fopen("banco_de_dados.txt", "r");

    if(dados != NULL)
    {

        for (cont = 0; cont < 3; cont++)
        {
            fread(&produto[cont], sizeof(produto[cont]), 1, dados);
            fread(&quantidade[cont], sizeof(quantidade[cont]), 1, dados);
        }

        for(cont=0; cont<3; cont++)
        {

            if(produto[cont][0]!='*')
            {
                todosExcluidos--;
            }

        }

        vz=1;
        zeroProdutos=1;
    }


    do
    {
        printf(" >> MENU LISTAGEM DE PRODUTOS <<\n\n");
        printf("1 – Entrada de dados\n");
        printf("2 – Lista todos os dados na tela.\n");
        printf("3 – Pesquisa um produto pelo nome completo e mostra todo os dados na tela\n");
        printf("4 – Pesquisa os produtos pela 1ª letra e mostra todos na tela.\n");
        printf("5 – Altera dados. Pesquisa o produto pelo nome completo.\n");
        printf("6 – Exclui dados. Pesquisa o produto pelo nome completo.\n");
        printf("7 - Saída\n\n");

        printf("Digite o número da opção que deseja: ");
        scanf("%d",&op);

        if(op<1 || op>7)
        {
            printf("\n\nOpção não encontrada.\n\n\n");
        }
        switch (op)
        {
        case 1:
            Entrada(vz);
            vz++;
            break;
        case 2:
            Listagem(vz);
            break;
        case 3:
            PesquisaCompleta(vz);
            break;
        case 4:
            PesquisaSimples(vz);
            break;
        case 5:
            AlterarDados(vz);
            break;
        case 6:
            Excluir(vz);
            break;
        case 7:
            printf("\n\n >> OPÇÃO 7 - SAIR DO PROGRAMA <<\n\n");
            exit(0);
            break;
        default:
            break;
        }

    }
    while(op!=7);

}
