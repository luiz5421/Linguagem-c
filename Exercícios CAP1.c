#include<stdio.h>
#include<math.h>
#include<locale.h>
#define ex1

/*****************************************************************************

			EXERCICIOS - CAPÍTULO 1

******************************************************************************/



#ifdef ex1 /******************************************************O usuário precisa digitar A e B?*/


/**1 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar.*/

int main()
{ setlocale(LC_ALL,"Portuguese");

int a, b;

    printf ("Digite um número para A, e outro para B.\n");
    printf("A: ");
    scanf("%d",&a);

    printf("B: ");
    scanf ("%d",&b);

    a = a + b; //lógica para a permuta
    b = a - b;
    a = a - b;

    printf ("\nValores após a permuta:\n\n");
    printf ("A: %d \nB: %d", a,b);


}

#endif


#ifdef ex2


/**2 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.*/

int main()
{ setlocale(LC_ALL,"Portuguese");

int tempo,hora,minuto,segundo;

    printf ("Digite um tempo em 'segundos' para que seja convertido em 'horas':\n" );
    scanf("%d",&tempo);

    hora = tempo/3600;
    minuto = (tempo/60)-(hora*60);
    segundo = tempo%60;

    printf("\nA hora certa é:\n");
    printf("\n%dh %dmin %ds",hora,minuto,segundo);


}

#endif



#ifdef ex3 /****************************************************Dúvidas sobre o espaçamento*/

/**3 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:
             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char */

int main()
{ setlocale(LC_ALL,"Portuguese");

short s;
long l;
int i;
float f;
double d;
char c;

    printf("Digite um valor para short: ");
    scanf("%hd", &s);
    printf("Digite um valor para long: ");
    scanf("%ld", &l);
    printf("Digite um valor para int: ");
    scanf("%d", &i);
    printf("Digite um valor para float: ");
    scanf("%f", &f);
    printf("Digite um valor para double: ");
    scanf("%lf", &d);
    printf("Digite um caracter para char: ");
    scanf(" %c", &c);

    printf("\n\n");

    printf("%10d %9d %9d %9d %9d %9d\n",10,20,30,40,50,60);
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");

    printf("%6d %19ld %19d\n", s, l, i);
    printf("%19.2f %19.2lf %16c\n", f, d, c);


}

#endif


#ifdef ex4

/**4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
    outro número formado pelos dígitos invertidos do número lido.
    Ex:   NúmeroLido = 123
        NúmeroGerado = 321 */


int main()
{ setlocale(LC_ALL,"Portuguese");

int numero, unidade, dezena, centena;

do {
    printf ("Digite um número inteiro, positivo e de 3 dígitos: ");
    scanf("%d",&numero);
    if (numero<100 || numero>999)
    {
     printf("O número deve ser positivo e ter 3 dígitos, digite novamente. ");
     printf("\n\n");
    }
} while (numero<100 || numero>999);


    unidade = numero % 10;
    dezena = (numero % 100) / 10;
    centena = numero / 100;

    printf("\nNúmero invertido: %d%d%d", unidade,dezena,centena);

}

#endif


#ifdef ex5

/**5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104. */


int main()
{ setlocale(LC_ALL,"Portuguese");


int num=0,min=0,mul=0;

    printf("Digite um numero para saber o seu menor multiplo: ");
    scanf("%d",&num);
    printf("Digite o limite minimo: ");
    scanf("%d",&min);

while (mul <= min)
{
    mul =mul+num;
}

    printf("\n\nO menor multiplo de %d maior que %d é: %d\n", num, min, mul);

}

#endif
