#include<stdio.h>
#include<math.h>
#include<locale.h>
#define ex4

/*****************************************************************************

			EXERCICIOS - CAPÍTULO 3

******************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.*/



#ifdef ex1


/**1 - Escreva um programa que receba dois numeros inteiros e execute as seguintes funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/


int Verifiq(int num)
{
    if(num>0)
    {
        return 1;
    }
    if(num<0)
    {
        return 0;
    }
    if(num==0)
    {
        return -1;
    }

}
int Soma(int a, int b)
{
    int soma;

    soma=a+b;
    return soma;
}

int Mult(int a, int b)
{
    int mult;

    mult=a*b;
    return mult;
}
float Div(float a, float b)
{
    float div;

    div=b/a;
    return div;
}
int main()
{ setlocale(LC_ALL,"Portuguese");

    int op,retorno1,retorno2,soma,mult;
    float num1,num2,div;

do{
    printf("Digite um numero:");
    scanf("%f",&num1);

    printf("\nDigite mais um numero:");
    scanf("%f",&num2);
    retorno1=Verifiq(num1);
    retorno2=Verifiq(num2);

    if(retorno1==1 && retorno2==1)
    {
        soma=Soma(num1,num2);
        printf("\nA soma dos numeros digitados e: %d",soma);
    }
    if(retorno1==0 && retorno2==0)
    {
        mult=Mult(num1,num2);
        printf("\nA multiplicacao dos numeros digitados e: %d",mult);
    }
    if(retorno1==1 && retorno2==0)
    {
        div=Div(num1,num2);
        printf("\nA divisao dos numeros digitados e: %f",div);
    }

    printf("\n\n\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif // ex1


#ifdef ex2


/**2 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.*/


int Fatorial(int n)
{
    int fat=1,fim;

    if (n==0 || n==1)
    {
        return 1;
    }
    else
    {
         for(fim=n;fim>1;fim--)
         {
             fat=n*fat;
             n--;
         }
         return fat;
    }
}

int SomaAlga(int num) {
    int soma = 0;
    while (num > 0)
    {
        soma =soma+(num % 10);
        num =num/10;
    }
    return soma;
}

int main() { setlocale(LC_ALL,"Portuguese");
    int op,num,fato,soma;

do{
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);

    fato = Fatorial(num);
    soma = SomaAlga(fato);

    printf("\n%d! = %d. A soma dos algarismos de %d! é: %d\n",num,fato,num,soma);


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");
}

#endif // ex2



#ifdef ex3

/**3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().*/


int adicao(int a, int b)
{
    return a + b;
}

int subtracao(int a, int b)
{
    return a - b;
}

int multiplicacao(int a, int b)
{
    return a * b;
}

float divisao(float a, float b)
{
    if (b != 0)
        {
        return a / b;
        }
        else
        {
            printf("Erro: Divisão por zero não existe.\n");
            return 0;
        }
}

int main()
{ setlocale(LC_ALL,"Portuguese");

    int op;
    float valor1, valor2;

do{
    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);
    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);

    printf("Resultado da adição: %.f + %.f = %d\n",valor1,valor2,adicao(valor1, valor2));
    printf("Resultado da subtração: %.f - %.f = %d\n",valor1,valor2,subtracao(valor1, valor2));
    printf("Resultado da multiplicação: %.f * %.f = %d\n",valor1,valor2,multiplicacao(valor1, valor2));
    printf("Resultado da divisão: %.f / %.f = %.2f\n",valor1,valor2,divisao(valor1, valor2));


    printf("\nDigite 1 para sair ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif // ex3



#ifdef ex4

/**4 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.*/


int adicao(int a, int b)
{
    return a + b;
}

int subtracao(int a, int b)
{
    if (a==0)
    {
        return b - a;
    }
    else
    {
        return a - b;
    }
}

int multiplicacao(int a, int b)
{
    if (b != 0)
    {
        return a * b;
    }

    else
    {
        return a;
    }

}

float divisao(float a, float b)
{
    if (b != 0)
    {
        if (a==1)
        {
            return b / a;
        }
        else
        {
            return a / b;
        }
    }

    else
    {
        return a;
    }
}


int main()
{ setlocale(LC_ALL,"Portuguese");

    int op,n,soma,sub,mult;
    float valor,div;

do {

    int resultadoSoma=0,resultadoSub=0,resultadoMult=1;
    float resultadoDiv=1;
    char continuar;

    printf("Digite quantos valores quiser, ou digite 'zero' para ver os resultados: \n");

    int i=1;
    do {
        printf("\nDigite o valor %d: ",i++);
        scanf("%f", &valor);

        soma=adicao(resultadoSoma,valor);
        sub=subtracao(resultadoSub,valor);
        mult=multiplicacao(resultadoMult,valor);
        div=divisao(resultadoDiv,valor);

        resultadoSoma=soma;
        resultadoSub=sub;
        resultadoMult=mult;
        resultadoDiv=div;

    } while (valor!=0);

    printf("\n\nResultado da adição: %d\n",soma);
    printf("\nResultado da subtração: %d\n",sub);
    printf("\nResultado da multiplicação: %d\n",mult);
    printf("\nResultado da divisão: %.2f\n",div);

    printf("\n\nDigite 1 para sair do programa ou digite 2 para continuar: ");
    scanf("%d",&op);
    printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif // ex4



#ifdef ex5

/**5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser
    mostrado na funcao main().*/


float adicao(int n1, int n2)
{
float soma;

soma = n1+n2;

return soma;
}

float subtracao(int n1, int n2)
{
float sub;

sub = n1-n2;

return sub;

}

float multiplicacao(int n1, int n2)
{
float mult;

mult = n1*n2;

return mult;
}

float divisao(float n1, float n2)
{
float div;

div = n1/n2;

return div;

}


int main()
{ setlocale(LC_ALL,"Portuguese");

char operacao;
int op;
float num=0, resultado=0, numAnt=0, num2;


do{
printf("CALCULADORA\n\n");

printf("SOMA = +\n");
printf("SUBTRAÇÃO = -\n");
printf("MULTIPLICAÇÃO = *\n");
printf("DIVISÃO = /\n\n\n");

    printf("Digite um número: ");
    scanf("%f", &resultado);
    numAnt=resultado;

    for (;;) {
        printf("Digite a operação escolhida ( +, -, *, /) ou '=' para resultado final: ");
        scanf(" %c", &operacao);
        if (operacao == '=')
        {
         break;
        }

        printf("Digite um número: ");
        scanf("%f",&num);

        switch (operacao) {
            case '+':
                resultado = adicao(resultado, num);
                break;
            case '-':
                resultado = subtracao(resultado, num);
                break;
            case '*':
                resultado = multiplicacao(resultado, num);
                break;
            case '/':
                if (num != 0)
                {
                resultado = divisao(resultado, num);
                break;
                }
                 else
                 {
                  printf("Erro: Divisão por zero não existe!\n");
                  continue;
                 }
            default:
                printf("Operação inválida!\n");
            }


        printf("Resultado parcial: %.f %c %.f = %.2f\n",numAnt,operacao,num,resultado); // ver de arrumar essa linha

        numAnt = resultado;


    }


    printf("Resultado final: %.2f\n", resultado);

printf("\nDigite 1 para sair ou digite 2 para continuar: ");
scanf("%d",&op);
printf("\n\n");

   }while(op!=1);

   printf("Fim");

}

#endif
