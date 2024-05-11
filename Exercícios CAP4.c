#include<stdio.h>
#include<math.h>
#include<locale.h>
#define ex5

/*****************************************************************************

			EXERCICIOS - CAPÍTULO 4

******************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.*/





#ifdef ex1


/**1 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double */

int main()
{ setlocale(LC_ALL,"Portuguese");

int op,ints[3];
long longs[3];
unsigned unsigneds[3];
float floats[3];
double doubles[3];

do{

    printf("Digite 3 ints, 3 longs, 3 unsigneds, 3 floats e 3 doubles: \n\n");


    for (int i=0;i<3;i++)
    {
    printf("Digite o %dº número inteiro: ",i+1);
    scanf("%d", &ints[i]);
    }
    printf("\n\n");

    for (int i=0;i<3;i++)
    {
    printf("Digite o %dº número long: ",i+1);
    scanf("%ld", &longs[i]);
    }
    printf("\n\n");

    for (int i=0;i<3;i++)
    {
    printf("Digite o %dº número unsigned: ",i+1);
    scanf("%u", &unsigneds[i]);
    }
    printf("\n\n");

    for (int i=0;i<3;i++)
    {
    printf("Digite o %dº número float: ",i+1);
    scanf("%f", &floats[i]);
    }
    printf("\n\n");

    for (int i=0;i<3;i++)
    {
    printf("Digite o %dº número double: ",i+1);
    scanf("%lf", &doubles[i]);
    }
    printf("\n\n");

    printf("%10d%10d%10d%10d%10d\n",10,20,30,40,50);
    printf("12345678901234567890123456789012345678901234567890\n");

    printf("%5d%21ld%24u\n", ints[0], longs[0], unsigneds[0]);
    printf("%17.2f%21.2lf\n", floats[0], doubles[0]);
    printf("%5d%21ld%24u\n", ints[1], longs[1], unsigneds[1]);
    printf("%17.2f%21.2lf\n", floats[1], doubles[1]);
    printf("%5d%21ld%24u\n", ints[2], longs[2], unsigneds[2]);
    printf("%17.2f%21.2lf\n", floats[2], doubles[2]);

    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif


#ifdef ex2


/**2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ os componentes de ORDEM(indice) impar
    e o outro tera´ os componentes de ORDEM(indice) par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/


int op,Vec[10],Par[5],Imp[5];

int main()
{ setlocale(LC_ALL,"Portuguese");

do{
    int  cont=0,conti=0,contp=0,a;

    for (int cont = 0; cont < 10; ++cont)
    {
            printf("Digite um numero: ");
            scanf("%d", &Vec[cont]);
    }

    for(int cont=0;cont<10;cont++)
    {
           if(cont==1 || cont==3 || cont==5 || cont==7 || cont==9)
           {
               Imp[conti]=Vec[cont];
               conti++;
           }
           else
           {
               Par[contp]=Vec[cont];
               contp++;
           }
    }

    for(cont=0;cont<10;cont++)
    {
        printf("Vec[%d]=%d\n",cont,Vec[cont]);
    }
     printf("\n");
    for(conti=0;conti<5;conti++)
    {
        printf("Imp[%d]=%d\n",conti,Imp[conti]);
    }
    printf("\n");
    for(contp=0;contp<5;contp++)
    {
        printf("Par[%d]=%d\n",contp,Par[contp]);
    }


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif



#ifdef ex3

/**3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ os componentes de VALOR impar
    e o outro tera´ os componentes de VALOR par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. */


int op,Vec[10],Par[10],Imp[10];

int main()
{ setlocale(LC_ALL,"Portuguese");

do{

int cont=0,a,contp=0,conti=0,div;

    for ( cont = 0; cont < 10; ++cont)
    {
            printf("Digite um numero: ");
            scanf("%d", &Vec[cont]);
    }

    for(cont=0;cont<10;cont++)
    {
        div=Vec[cont]%2;
           if(div==0)
           {
               Par[contp]=Vec[cont];
               contp++;
           }
           else
           {
               Imp[conti]=Vec[cont];
               conti++;
           }
    }

    for(cont=0;cont<10;cont++)
    {
        printf("Vec[%d]=%d\n",cont,Vec[cont]);
    }
     printf("\n");
    for(int contI=0;contI<conti;contI++)
    {
        printf("Imp[%d]=%d\n",contI,Imp[contI]);
    }
    printf("\n");
    for(int contP=0;contP<contp;contP++)
    {
        printf("Par[%d]=%d\n",contP,Par[contP]);
    }


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif



#ifdef ex4


/**4 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.*/


int main()
{ setlocale(LC_ALL,"Portuguese");

int op;
do{
    int matriz1[2][3];
    int matriz2[2][3];
    int resultado[2][3];

    printf("Digite os elementos da matriz 1 (2x3):\n\n");
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("\n\nDigite os elementos da matriz 2 (2x3):\n\n");
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("\n\nÍndice\t\tMatriz 1\tMatriz 2\tResultado\n");
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("[%d][%d]\t\t%d \t\t%d \t\t%d \n", i, j, matriz1[i][j], matriz2[i][j], resultado[i][j]);
        }
    }

    printf("\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif



#ifdef ex5

/**5 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.*/


int vetor[10];

void ordena(int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho-i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main()
{ setlocale(LC_ALL,"Portuguese");

    int op, tamanhoVetor=10, novoElemento, i, j;

do {
    printf("Digite 10 valores inteiros: \n\n");

    for (i = 0; i < tamanhoVetor; i++)
        {
            printf("Digite o valor %d: ", i + 1);
            scanf("%d", &novoElemento);
            vetor[i] = novoElemento;

            ordena(i);

            printf("Vetor atualizado: [");
            for (j = 0; j <= i; j++)
                {
                    printf("%d", vetor[j]);
                    if (j < i)
                        {
                            printf(", ");
                        }
                }
            printf("]\n");
        }

    printf("\nValores armazenados e ordenados no vetor:\n");
    printf("[");
    for (i = 0; i < tamanhoVetor; i++)
        {
            printf("%d", vetor[i]);
            if (i < tamanhoVetor - 1)
            {
                printf(", ");
            }
        }
    printf("]\n");

    printf("\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}


#endif
