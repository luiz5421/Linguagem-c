#include<stdio.h>
#include<math.h>
#include<locale.h>
#define ex4

/*****************************************************************************

			EXERCICIOS - CAPÍTULO 6

******************************************************************************
OBS.: Todos os programas devem ser finalizados pelo usuario.*/




#ifdef ex1


/**1 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.*/


void main()
{ setlocale(LC_ALL,"Portuguese");

int op,a,b;

do{
    printf("Digite um numero inteiro: ");
    scanf("%d",&a);

    printf("Digite um numero inteiro: ");
    scanf("%d",&b);

    printf(" Operadores bit-a-bit\n");
    printf(" AND                 a & b --> %3d  0x%x\n",a & b,a & b); /* 0x20 */
    printf(" OU                  a | b --> %3d  0x%x\n",a | b,a | b); /* 0x76 */
    printf(" OU EXCLUSIVO        a ^ b --> %3d  0x%x\n",a ^ b,a ^ b); /* 0x56 */


    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif


#ifdef ex2


/**2 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.*/


int main()
{ setlocale(LC_ALL,"Portuguese");

    float num1;
    float num2;
    int op;

do{

    printf ("Digite um número inteiro: ");
    scanf ("%f", &num1);

    do{
    printf ("\n\nDigite outro número inteiro (esse número não pode ser zero): ");
    scanf ("%f", &num2);
    if (num2==0)
    {
        printf ("\nErro! Esse número deve ser diferente de 0.\n\n");
    }
    }while(num2==0);

    printf ("Os resultados das operações aritméticas são:\n\n");
    printf ("Soma = %.f\n", num1+num2);
    printf ("Subtração = %.f\n", num1-num2);
    printf ("Multiplicação = %.f\n", num1*num2);
    printf ("Divisão = %.2f\n", num1/num2);


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif



#ifdef ex3

/**3 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.*/

int main()
{ setlocale(LC_ALL,"Portuguese");

float num1;
float num2;
float auxiliar;
int op;

do{

    printf ("Digite um número inteiro: ");
    scanf ("%f", &num1);
    auxiliar=num1;

    do{
    printf ("\n\nDigite outro número inteiro (esse número não pode ser zero): ");
    scanf ("%f", &num2);
    if (num2==0)
    {
        printf ("\nErro! Esse número deve ser diferente de 0.\n\n");
    }
    }while(num2==0);

    printf ("Os resultados das operações aritméticas são:\n\n");

    num1+=num2;
    printf ("Soma = %.f\n", num1);
    num1=auxiliar;

    num1-=num2;
    printf ("Subtração = %.f\n", num1);
    num1=auxiliar;

    num1*=num2;
    printf ("Multiplicação = %.f\n", num1);
    num1=auxiliar;

    num1 /= num2;
    printf ("Divisão = %.2f\n", num1);
    num1=auxiliar;


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif


#ifdef ex4

/**4 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.*/


int dataNasc[9],dataHoje[9];
int Meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void validaDataHoje()
{
    do{

    inicio:
    printf("Digite a data de HOJE (ddmmaaaa): ");
    scanf("%2d%2d%4d",&dataHoje[0],&dataHoje[1],&dataHoje[2]);
    printf("\nData de hoje registrada: %d/%d/%d\n",dataHoje[0],dataHoje[1],dataHoje[2]);


//validação da data de hoje

    if (dataHoje[1] < 1 || dataHoje[1] > 12)
        {
            printf("\nMês da data de hoje inválido.\n\n\n\n");
            goto inicio;
        }
        else
        {
            if (dataHoje[1] == 1 || dataHoje[1] == 3 || dataHoje[1] == 5 || dataHoje[1] == 7 ||
                dataHoje[1] == 8 || dataHoje[1] == 10 || dataHoje[1] == 12)
                {
                    do {
                            if (dataHoje[0] < 1 || dataHoje[0] > 31)
                            {
                                printf("\nData de hoje inválida para o mês escolhido - Digite um dia entre 1 e 31.\n\n\n\n");
                                goto inicio;
                            }
                    } while (dataHoje[0] < 1 || dataHoje[0] > 31);
                }


            if (dataHoje[1] == 4 || dataHoje[1] == 6 || dataHoje[1] == 9 || dataHoje[1] == 11)
                {
                    do {
                            if (dataHoje[0] < 1 || dataHoje[0] > 30)
                            {
                                printf("\nData de hoje inválida para o mês escolhido - Digite um dia entre 1 e 30.\n\n\n\n");
                                goto inicio;
                            }
                    } while (dataHoje[0] < 1 || dataHoje[0] > 30);
                }


            if (dataHoje[1] == 2)
                {
                    do {
                            if ((dataHoje[2] % 4 == 0 && dataHoje[2] % 100 != 0) || dataHoje[2] % 400 == 0) //condicional para ser ano bissexto
                            {
                                if (dataHoje[0] < 1 || dataHoje[0] > 29)
                                {
                                    printf("\nData de hoje inválida para o mês escolhido - Digite um dia entre 1 e 29.\n\n\n\n");
                                    goto inicio;
                                }
                            }
                            else
                            {
                                if (dataHoje[0] < 1 || dataHoje[0] > 28)
                                {
                                    printf("\nO ano escolhido não é bissexto. Para ano '%d' e mês '02' digite um dia entre 1 e 28.\n\n\n\n",dataHoje[2]);
                                    goto inicio;
                                }
                            }

                    }while (dataHoje[0] < 1 || dataHoje[0] > 29);
                }


            if (dataHoje[2] < 0 || dataHoje[2] > 2024)  //A contagem de da data de hoje pode ser de 0 a 2024 d.c
            {
                do {
                        printf("\nAno da data de hoje inválido - O ano deve ser entre 0 e 2024.\n\n\n\n");
                        goto inicio;
                }while (dataHoje[2] < 0 || dataHoje[2] > 2024);
            }

        }

    }while (dataHoje[1] < 1 || dataHoje[1] > 12);
}



void validaDataNasc()
{
    printf("\n\n\n");

    do{

    inicio:
    printf("Digite a sua data de NASCIMENTO (ddmmaaaa): ");
    scanf("%2d%2d%4d",&dataNasc[0],&dataNasc[1],&dataNasc[2]);
    printf("\nData de nascimento registrada: %d/%d/%d\n",dataNasc[0],dataNasc[1],dataNasc[2]);


//verifica se a data de hoje é menor ou maior do que a data de aniversário

    if (dataHoje[2] < dataNasc[2])
    {
        printf("\nData de Nascimento deve ser menor do que a data de Hoje. - Digite um ano que não seja superior a '%d' \n\n\n\n",dataHoje[2]);
        goto inicio;
    }

    if (dataHoje[2] == dataNasc[2])
    {
        if (dataHoje[1] < dataNasc[1])
        {
            printf("\nData de Nascimento deve ser menor do que a data de Hoje. - Para o ano '%d' digite um mês que não seja superior a '%d' \n\n\n\n",dataHoje[2],dataHoje[1]);
            goto inicio;
        }

        if (dataHoje[1] == dataNasc[1])
        {
            if (dataHoje[0] < dataNasc[0])
            {
                printf("\nData de Nascimento deve ser menor do que a data de Hoje. Para o mês '%d' digite um dia que não seja superior a '%d' \n\n\n\n",dataHoje[1],dataHoje[0]);
                goto inicio;
            }

            if (dataHoje[0] == dataNasc[0])
            {
                printf("\nParabéns! você NASCEU HOJE!!!");
                break;
            }
        }
    }

    if (dataHoje[1] == dataNasc[1])
    {
     if (dataHoje[0] == dataNasc[0])
        {
            printf("\nParabéns! hoje é SEU ANIVERSÁRIO!!!");
        }
    }

//validação da data de nascimento

    if (dataNasc[1] < 1 || dataNasc[1] > 12)
        {
            printf("\nMês de nascimento inválido - Digite um mês entre 1 e 12.\n\n\n\n");
            goto inicio;
        }
        else
        {
            if (dataNasc[1] == 1 || dataNasc[1] == 3 || dataNasc[1] == 5 || dataNasc[1] == 7 ||
                dataNasc[1] == 8 || dataNasc[1] == 10 || dataNasc[1] == 12)
                {
                    do {
                            if (dataNasc[0] < 1 || dataNasc[0] > 31)
                            {
                                printf("\nData de nascimento inválida para o mês escolhido - Digite um dia entre 1 e 31.\n\n\n\n");
                                goto inicio;
                            }
                    } while (dataNasc[0] < 1 || dataNasc[0] > 31);
                }


            if (dataNasc[1] == 4 || dataNasc[1] == 6 || dataNasc[1] == 9 || dataNasc[1] == 11)
                {
                    do {
                            if (dataNasc[0] < 1 || dataNasc[0] > 30)
                            {
                                printf("\nData de nascimento inválida para o mês escolhido - Digite um dia entre 1 e 30.\n\n\n\n");
                                goto inicio;
                            }
                    } while (dataNasc[0] < 1 || dataNasc[0] > 30);
                }


            if (dataNasc[1] == 2)
                {
                    do {
                            if ((dataNasc[2] % 4 == 0 && dataNasc[2] % 100 != 0) || dataNasc[2] % 400 == 0) //condicional para ser ano bissexto
                            {
                                if (dataNasc[0] < 1 || dataNasc[0] > 29)
                                {
                                    printf("\nData de nascimento inválida para o mês escolhido - Digite um dia entre 1 e 29.\n\n\n\n");
                                    goto inicio;
                                }
                            }
                            else
                            {
                                if (dataNasc[0] < 1 || dataNasc[0] > 28)
                                {
                                    printf("\nO ano escolhido não é bissexto. Para ano '%d' e mês '02' digite um dia entre 1 e 28.\n\n\n\n",dataNasc[2]);
                                    goto inicio;
                                }
                            }

                    }while (dataNasc[0] < 1 || dataNasc[0] > 29);
                }


            if (dataNasc[2] < 0 || dataNasc[2] > 2024)  //A contagem de da data de aniversário pode ser de 0 a 2024 d.c
            {
                do {
                        printf("\nAno de nascimento inválido - O ano deve ser entre 0 e 2024.\n\n\n\n");
                        goto inicio;
                }while (dataNasc[2] < 0 || dataNasc[2] > 2024);
            }

        }

    }while (dataNasc[1] < 1 || dataNasc[1] > 12);
}


void calculaIdade()    //cálculo da idade
{
    int anos,meses,dias;

    if ((dataHoje[2] % 4 == 0 && dataHoje[2] % 100 != 0) || dataHoje[2] % 400 == 0) //condicional para ser ano bissexto
    {
        Meses[1] = 29;
    }

    anos = dataHoje[2] - dataNasc[2];
    meses = dataHoje[1] - dataNasc[1];
    dias = dataHoje[0] - dataNasc[0];

    if (meses < 0)
    {
        anos--;
        meses += 12;
    }

   if (meses == 0 && dias < 0)
    {
        anos--;
        meses += 12;
    }

    if (dias < 0)
    {
        meses--;
        dias += Meses[dataHoje[1]-1];
    }



    printf("\n\n\nVocê tem %d anos, %d meses, e %d dias.",anos,meses,dias);
}


int main()
{ setlocale(LC_ALL,"Portuguese");

int op;

do{

    validaDataHoje();

    validaDataNasc();

    calculaIdade();

    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n\n\n");

    if (op==2) //Zerando os vetores para a próxima rodada
    {
        for (int i = 0; i < 8; i++)
            {
                dataNasc[i] = '\0';
                dataHoje[i] = '\0';
                Meses[1] = 28;
            }
    }

   }while(op!=1);

   printf("Fim");

}

#endif


#ifdef ex5

/**5 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.*/


int dataHoje[9];

void validaDataHoje()
{
    do{

    inicio:
    printf("Digite a data de HOJE (ddmmaaaa): ");
    scanf("%2d%2d%4d",&dataHoje[0],&dataHoje[1],&dataHoje[2]);
    printf("\nData de hoje registrada: %d/%d/%d\n",dataHoje[0],dataHoje[1],dataHoje[2]);


//validação da data de hoje

    if (dataHoje[1] < 1 || dataHoje[1] > 12)
        {
            printf("\nMês da data de hoje inválido.\n\n\n\n");
            goto inicio;
        }
        else
        {
            if (dataHoje[1] == 1 || dataHoje[1] == 3 || dataHoje[1] == 5 || dataHoje[1] == 7 ||
                dataHoje[1] == 8 || dataHoje[1] == 10 || dataHoje[1] == 12)
                {
                    do {
                            if (dataHoje[0] < 1 || dataHoje[0] > 31)
                            {
                                printf("\nData de hoje inválida para o mês escolhido - Digite um dia entre 1 e 31.\n\n\n\n");
                                goto inicio;
                            }
                    } while (dataHoje[0] < 1 || dataHoje[0] > 31);
                }


            if (dataHoje[1] == 4 || dataHoje[1] == 6 || dataHoje[1] == 9 || dataHoje[1] == 11)
                {
                    do {
                            if (dataHoje[0] < 1 || dataHoje[0] > 30)
                            {
                                printf("\nData de hoje inválida para o mês escolhido - Digite um dia entre 1 e 30.\n\n\n\n");
                                goto inicio;
                            }
                    } while (dataHoje[0] < 1 || dataHoje[0] > 30);
                }


            if (dataHoje[1] == 2)
                {
                    do {
                            if ((dataHoje[2] % 4 == 0 && dataHoje[2] % 100 != 0) || dataHoje[2] % 400 == 0) //condicional para ser ano bissexto
                            {
                                if (dataHoje[0] < 1 || dataHoje[0] > 29)
                                {
                                    printf("\nData de hoje inválida para o mês escolhido - Digite um dia entre 1 e 29.\n\n\n\n");
                                    goto inicio;
                                }
                            }
                            else
                            {
                                if (dataHoje[0] < 1 || dataHoje[0] > 28)
                                {
                                    printf("\nO ano escolhido não é bissexto. Para ano '%d' e mês '02' digite um dia entre 1 e 28.\n\n\n\n",dataHoje[2]);
                                    goto inicio;
                                }
                            }

                    }while (dataHoje[0] < 1 || dataHoje[0] > 29);
                }


            if (dataHoje[2] < 0 || dataHoje[2] > 2024)  //A contagem de da data de hoje pode ser de 0 a 2024 d.c
            {
                do {
                        printf("\nAno da data de hoje inválido - O ano deve ser entre 0 e 2024.\n\n\n\n");
                        goto inicio;
                }while (dataHoje[2] < 0 || dataHoje[2] > 2024);
            }

        }

    }while (dataHoje[1] < 1 || dataHoje[1] > 12);
}


int main ()
{ setlocale(LC_ALL,"Portuguese");

char semana[7][14]={"Sábado","Domingo","Segunda-Feira","Terça-Feira","Quarta-Feira","Quinta-Feira","Sexta-Feira"};
int op,d,m,a,s;

do{
    validaDataHoje();

    d=dataHoje[0];
    m=dataHoje[1];
    a=dataHoje[2];

    if (m < 3) //ajusta os meses 01 e 02 para usar na fórmula de zeller
    {
        m += 12;
        a--;
    }

    s = (d+(13*(m+1)/5)+a+(a/4)-(a/100)+(a/400))%7; // fórmula de Zeller para achar o dia da semana;


    printf("\n\nO dia da semana de hoje é: %s\n",semana[s]);


    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

    if (op==2) //Zerando os vetores para a próxima rodada
    {
        for (int i = 0; i < 8; i++)
            {
                dataHoje[i] = '\0';
            }
    }

   }while(op!=1);

   printf("Fim");

}


#endif
