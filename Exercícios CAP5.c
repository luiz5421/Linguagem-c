#include<stdio.h>
#include<math.h>
#include<locale.h>
#define MAX_SIZE 100
#define ex1

/*****************************************************************************

			EXERCICIOS - CAPÍTULO 5

******************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.*/





#ifdef ex1


/**1 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3 */

char n1[8],n2[8],n3[8],n4[8],n5[8];
int op,i;

int main()
{ setlocale(LC_ALL,"Portuguese");

printf("Digite 5 nomes com até 7 caracteres: ");

do{               /**************************************** Perguntar pro professor se é possível encurtar a lógica com os vetores*/
    i=1;
    printf("\n\nDigite o Nome %d e tecle ENTER: ",i);
    scanf("%7s", &n1[0]);
    while (getchar() != '\n'); //limpar o buffer (Ou seja, ignorar os caracteres extras)
    printf("\nO nome %d é: %s\n",i++,n1);

    printf("\n\nDigite o Nome %d e tecle ENTER: ",i);
    scanf("%7s", &n2[0]);
    while (getchar() != '\n');
    printf("\nO nome %d é: %s\n",i++,n2);

    printf("\n\nDigite o Nome %d e tecle ENTER: ",i);
    scanf("%7s", &n3[0]);
    while (getchar() != '\n');
    printf("\nO nome %d é: %s\n",i++,n3);

    printf("\n\nDigite o Nome %d e tecle ENTER: ",i);
    scanf("%7s", &n4[0]);
    while (getchar() != '\n');
    printf("\nO nome %d é: %s\n",i++,n4);

    printf("\n\nDigite o Nome %d e tecle ENTER: ",i);
    scanf("%7s", &n5[0]);
    while (getchar() != '\n');
    printf("\nO nome %d é: %s\n",i++,n5);


     //linha de controle, só pra verificar como está dentro das strings:
    /*
    printf("\n\nN 1: ");
    for (int i=0;i<8;i++)
    {
        printf("%c",n1[i]);
    }*/


    printf("\n\n");
    printf("%10d%10d%10d%10d%10d\n",10,20,30,40,50);
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-7s                                 %-7s\n            %-7s             %-7s\n                      %-7s\n",n1,n5,n2,n4,n3);


    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

    if (op==2) //Zerando os vetores para a próxima rodada
    {
        for (int i = 0; i < 8; i++)
            {
                n1[i] = '\0';
                n2[i] = '\0';
                n3[i] = '\0';
                n4[i] = '\0';
                n5[i] = '\0';
            }
    }

   }while(op!=1);

   printf("Fim");

}

#endif


#ifdef ex2


/**2 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca) */


char string1[11],string2[11];

int compara()
{
int contDiferente=0;

    for (int j=0;j<11;j++)
    {
        if (string1[j] !=  string2[j])
        {
            contDiferente++;
        }
    }

    if (contDiferente > 0)
    {
        return 0;
    }
        else
        {
            return 1;
        }
}

int main()
{ setlocale(LC_ALL,"Portuguese");

int op,i,resultado;

do{
    printf("Digite 2 strings com até 10 caracteres: ");

    for (i=0;i<1;i++)
    {
    printf("\n\n\nDigite a string %d e tecle ENTER: ",i+1);
    scanf("%10s", &string1[0]);
    while (getchar() != '\n'); //limpar o buffer (Ou seja, ignorar os caracteres extras)
    printf("\nA string %d é: %s",i+1,string1);

    printf("\n\n\nDigite a string %d e tecle ENTER: ",i+2);
    scanf("%10s", &string2[0]);
    while (getchar() != '\n');
    printf("\nA string %d é: %s",i+2,string2);
    }

    resultado=compara();

    //linha de controle, só pra verificar como está dentro das strings:
    /*
    printf("\n\nString 1: ");
    for (int i=0;i<11;i++)
    {
        printf("%c",string1[i]);
    }
    printf("\n\nString 2: ");
    for (int i=0;i<11;i++)
    {
        printf("%c",string2[i]);
    }*/


    //printf("\n\nEm int: string1[0] = %d, string2[0] = %d",string1,string2);
    //printf("\n\nEm str: string1[0] = %s, string2[0] = %s",string1,string2);


    //printf("\n\nreturn = %d",resultado);

    if (resultado == 1)
    {
        printf("\n\n\nAs strings '%s' e '%s' são iguais.",string1,string2);
    }
        else
        {
            printf("\n\n\nAs strings '%s' e '%s' são diferentes.",string1,string2);
        }

    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

    if (op==2) //Zerando os vetores para a próxima rodada
    {
        for (int i = 0; i < 11; i++)
            {
                string1[i] = '\0';
                string2[i] = '\0';
            }
    }
   }while(op!=1);

   printf("Fim");

}

#endif



#ifdef ex3

/**3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
    calcula o comprimento de uma string recebida via teclado. Mostre o valor do
    comprimento na funcao main().
    (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca) */


char String[MAX_SIZE];

// Função para calcular o comprimento da string
int calcularComprimento() {
    int comprimento = 0;
    while (String[comprimento] != '\0') {
        comprimento++;
    }

    return comprimento;
}

int main (void)

{ setlocale(LC_ALL,"Portuguese");
int op;
do{

printf("Digite uma string: ");
    // Lendo a string
    scanf("%s", String);
    // Calculando o comprimento da string
    int comprimento = calcularComprimento();

    // Mostrando o valor do comprimento
    printf("O comprimento da string e: %d\n", comprimento);


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
     getchar();
    printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif


#ifdef ex4

/**4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas. (nao pode usar funcao de biblioteca) */


char String[11];

int main()
{ setlocale(LC_ALL,"Portuguese");

int cont,op;

do{
    printf("Digite uma cadeia de caracteres (10): ");
    scanf("%10s", String);

    for(cont=0;cont<10;cont++)
    {
        switch (String[cont]) {
            case 'a':
                String[cont] = 'A';
                break;
            case 'b':
                String[cont] = 'B';
                break;
            case 'c':
                String[cont] = 'C';
                break;
            case 'd':
                String[cont] = 'D';
                break;
            case 'e':
                String[cont] = 'E';
                break;
            case 'f':
                String[cont] = 'F';
                break;
            case 'g':
                String[cont] = 'G';
                break;
            case 'h':
                String[cont] = 'H';
                break;
            case 'i':
                String[cont] = 'I';
                break;
            case 'j':
                String[cont] = 'J';
                break;
            case 'k':
                String[cont] = 'K';
                break;
            case 'l':
                String[cont] = 'L';
                break;
            case 'm':
                String[cont] = 'M';
                break;
            case 'n':
                String[cont] = 'N';
                break;
            case 'o':
                String[cont] = 'O';
                break;
            case 'p':
                String[cont] = 'P';
                break;
            case 'q':
                String[cont] = 'Q';
                break;
            case 'r':
                String[cont] = 'R';
                break;
            case 's':
                String[cont] = 'S';
                break;
            case 't':
                String[cont] = 'T';
                break;
            case 'u':
                String[cont] = 'U';
                break;
            case 'v':
                String[cont] = 'V';
                break;
            case 'w':
                String[cont] = 'W';
                break;
            case 'x':
                String[cont] = 'X';
                break;
            case 'y':
                String[cont] = 'Y';
                break;
            case 'z':
                String[cont] = 'Z';
                break;
            default:
                break;
        }
    }

    printf("Tudo maiuscula: %s",String);
    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif



#ifdef ex5

/**5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. (nao pode usar funcao de biblioteca) */


char String[11];

int main()
{ setlocale(LC_ALL,"Portuguese");

int cont,op;

do{
    printf("Digite uma cadeia de caracteres (10): ");
    scanf("%10s", String);

    for(cont=0;cont<10;cont++)
    {
        switch (String[cont]) {
            case 'A':
                String[cont] = 'a';
                break;
            case 'B':
                String[cont] = 'b';
                break;
            case 'C':
                String[cont] = 'c';
                break;
            case 'D':
                String[cont] = 'd';
                break;
            case 'E':
                String[cont] = 'e';
                break;
            case 'F':
                String[cont] = 'f';
                break;
            case 'G':
                String[cont] = 'g';
                break;
            case 'H':
                String[cont] = 'h';
                break;
            case 'I':
                String[cont] = 'i';
                break;
            case 'J':
                String[cont] = 'j';
                break;
            case 'K':
                String[cont] = 'k';
                break;
            case 'L':
                String[cont] = 'l';
                break;
            case 'M':
                String[cont] = 'm';
                break;
            case 'N':
                String[cont] = 'n';
                break;
            case 'O':
                String[cont] = 'o';
                break;
            case 'P':
                String[cont] = 'p';
                break;
            case 'Q':
                String[cont] = 'q';
                break;
            case 'R':
                String[cont] = 'r';
                break;
            case 'S':
                String[cont] = 's';
                break;
            case 'T':
                String[cont] = 't';
                break;
            case 'U':
                String[cont] = 'u';
                break;
            case 'V':
                String[cont] = 'v';
                break;
            case 'W':
                String[cont] = 'w';
                break;
            case 'X':
                String[cont] = 'x';
                break;
            case 'Y':
                String[cont] = 'y';
                break;
            case 'Z':
                String[cont] = 'z';
                break;
            default:
                break;
        }
    }

    printf("Tudo minuscula: %s",String);

    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif
