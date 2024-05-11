#include<stdio.h>
#include<math.h>
#include<locale.h>
#define ex1

/*****************************************************************************

			EXERCICIOS - CAPÍTULO 2

******************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.*/





#ifdef ex1 /*****************************************************O número negativo entra na media?*/


/**1 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.*/

int main()
{ setlocale(LC_ALL,"Portuguese");

int num=0,soma=0,cont=0,op=0;
float media=0;

do{
    cont=0;
    soma=0;

    printf("Digite um número positivo, ou para fechar a conta, digite um número negativo:\n\n");

    do{
        printf("%d: ",cont+1);
        scanf("%d",&num);

        if(num>=0)
        {
            soma=soma+num;
            cont++;
        }

        }while(num>=0);

    media= soma/cont;

    printf("\nA média dos valores digitados é:%2.f\n\n",media);


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif


#ifdef ex2


/**2 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.*/

int main()
{ setlocale(LC_ALL,"Portuguese");

int op=0;

do {
    int limite_inferior = 1;
    int limite_superior = 99;
    int chute = 50;
    char resposta;

    printf("Pense em um número entre 1 e 99.\n");

    do {
        //printf("\nLimite Inferior: %d, Limite Superior: %d, Chute: %d",limite_inferior,limite_superior,chute);  //linha de controle de dados
        printf("\nO número que voce pensou é %d? Digite: '=' para acerto, '>' para maior, ou '<' para menor: ", chute);
        scanf(" %c", &resposta);

        if (resposta == '=') {
            printf("\n\nNúmero %d adivinhado com sucesso!!!\n", chute);
            break;
        } else if (resposta == '>') {
            limite_inferior = chute + 1;
        } else if (resposta == '<') {
            limite_superior = chute - 1;
        } else {
            printf("\nEntrada inválida. Digite '=', '>' ou '<'\n");
            continue;
        }

        chute = (limite_inferior + limite_superior) / 2;


    } while (resposta != '='); /**(limite_inferior <= limite_superior); *****ñ entendi a logica do limite inferior ser <= ao superior e só entao sair do looping**/


  printf("\nDigite 1 para sair ou digite 2 para continuar: ");
  scanf("%d",&op);
  printf("\n\n");

  }while(op!=1);

  printf("Fim");

}

#endif



#ifdef ex3

/**3 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.*/

int main()
{ setlocale(LC_ALL,"Portuguese");

int op=0;

do {
    int limite_inferior = 1;
    int limite_superior = 99;
    int chute = 50;
    char resposta;
    int tentativas = 0;

    printf("Pense em um número entre 1 e 99.\n");

    do {
        //printf("\nLimite Inferior: %d, Limite Superior: %d, Chute: %d",limite_inferior,limite_superior,chute);  //linha de controle de dados
        printf("\nO número que voce pensou é %d? Digite: '=' para acerto, '>' para maior, ou '<' para menor: ", chute);
        scanf(" %c", &resposta);

        switch (resposta) {
            case '=':
                printf("\n\nNúmero %d adivinhado com sucesso!!!\n", chute);
                break;
            case '>':
                limite_inferior = chute + 1;
                break;
            case '<':
                limite_superior = chute - 1;
                break;
            default:
            printf("\nEntrada inválida. Digite '=', '>' ou '<'\n");
            continue;
        }

        tentativas++;
        chute = (limite_inferior + limite_superior) / 2;


    } while (resposta != '='); /**(limite_inferior <= limite_superior); *****ñ entendi a logica do limite inferior ser <= ao superior e só entao sair do looping**/

  printf("\n\nAdivinhado em um total de %d tentativas!\n\n", tentativas);

  printf("\nDigite 1 para sair ou digite 2 para continuar: ");
  scanf("%d",&op);
  printf("\n\n");

  }while(op!=1);

  printf("Fim");

}

#endif


#ifdef ex4

/**4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!*/


int main()
{ setlocale(LC_ALL,"Portuguese");

int km=0,litro=0,op=0;
float consumo=0;

do{
    printf("Digite a distância em KM percorrida pelo carro: ");
    scanf("%d",&km);
    printf("\nDigite quantos litros de gasolina o carro utilizou no percurso: ");
    scanf("%d",&litro);

    consumo=km/litro;
    //printf("\nkm: %d, litro: %d, consumo: %.f\n",km,litro,consumo); //linha de controle de dados

    printf("\nStatus: ");
    if(consumo>14)
    {
        printf("Super econômico!");
    }
    else
    {
        if(consumo<15 && consumo>7)
        {
            printf("Econômico!");
        }
        else
        {
            printf("Venda o carro!!!");
        }
    }

printf("\n\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
scanf("%d",&op);
printf("\n\n\n");

  }while(op!=1);

printf("Fim");


}

#endif


#ifdef ex5

/**5 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.*/


int main()
{ setlocale(LC_ALL,"Portuguese");

int ihr=0,imin=0,iseg=0,op=0,fhr=0,fmin=0,fseg=0,difMin=0,difHr=0,difSeg=0;
int totalSegundos1=0,totalSegundos2=0;

do{
    printf("Digite a hora de início da ligação:");
    printf("\nHora: ");
    scanf("%d",&ihr);
    printf("Minuto: ");
    scanf("%d",&imin);
    printf("Segundo: ");
    scanf("%d",&iseg);

    printf("\nDigite a hora do fim da ligação:");
    printf("\nHora: ");
    scanf("%d",&fhr);
    printf("Minuto: ");
    scanf("%d",&fmin);
    printf("Segundo: ");
    scanf("%d",&fseg);

    totalSegundos1=((ihr*3600)+(imin*60)+iseg);
    totalSegundos2=((fhr*3600)+(fmin*60)+fseg);

    if (totalSegundos1 > totalSegundos2)
    {
        difSeg=totalSegundos1-totalSegundos2;
    }
    else
    {
        difSeg=totalSegundos2-totalSegundos1;
    }

difHr=difSeg/3600;
difSeg=difSeg%3600;
difMin=difSeg/60;
difSeg=difSeg%60;

printf("\nA ligação durou o total de: %d horas, %d minutos e %d segundos.\n", difHr, difMin, difSeg);


printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
scanf("%d",&op);
printf("\n\n");

  }while(op!=1);

printf("Fim");


}

#endif
