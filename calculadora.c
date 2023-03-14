#include "stdio.h"
#include "math.h"

float stack[8];
void printstack()
{
    int i = 0;
    for(i=0; i < 8; i++)
    {
        printf("%d", 8 - i);
        printf(". ");
        printf("%f", stack[i]);
        printf("\n");
    }
}

void printOption()
{
    printf("Que desea realizar\n");
    printf("1. Agregar numero 2. Seleccionar Operacion 3.Limpiar ultimo");
    printf("\n4. Limpiar todo 5. Salir ");
}

void moveup()
{
    int i=0;
    for(i=1; i < 8; i++)
    {
        stack[i-1] = stack[i];
    }
}

void movedown() 
{
    int i= 0;
    for(i=5; i>=0; i--)
    {
        stack[i+1] = stack[i];
    }
}

void operation(char n)
{
    switch (n)
    {
    case '+':
        stack[7] += stack[6];
        movedown();
        printf("\033[2J");
        break;
    case '-':
        stack[7] = stack[6] - stack[7];
        movedown();
        printf("\033[2J");
        break;
    case '*':
        stack[7] *= stack[6];
        movedown();
        printf("\033[2J");
        break;
    case '/':
        if(stack[6]==1 && stack[7]==0)
        {
            printf("\033[2J");
            printf("Error matematico\n");
        }
        else
        {
            stack[7] = stack[6] / stack[7];
            movedown();
            printf("\033[2J");
        }
        break;
    case 'r':
        if(stack[7]>=0)
        {
            stack[7]=sqrt(stack[7]);
            printf("\033[2J");
        }
        else
        {
            printf("\033[2J");
            printf("Error matematico\n");
        }
        break;
    case 's':
        stack[7] = sin(stack[7]);
        printf("\033[2J");
        break;
    case 'c':
        stack[7] = cos(stack[7]);
        printf("\033[2J");
        break;
    case 't':
        if(stack[7] != 90){
            stack[7] = tan(stack[7]);
            printf("\033[2J");
        }
        else
        {
            printf("\033[2J");
            printf("Error matematico\n");
            
        }
        break;
    case 'p':
        pow(stack[6],stack[7]);
        movedown();
        printf("\033[2J");
        break;
    default:
        break;
    }
}

void deleteall()
{
    int i =0;
    for(i=0; i<8; i++)
    {
        stack[i] = 0.0;
    }
}

void deletefirst()
{
    int i= 0;
    for(i=6; i>=0; i--)
    {
        stack[i+1] = stack[i];
    }
}

int main()
{
    int opt = 0, num;
    char ascci;
    while(opt != 5)
    {
        printstack();
        printOption();
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("\033[2J");
            printstack();
            printf("Ingrese el numero: ");
            scanf("%d",&num);
            moveup();
            stack[7] = num;
            printf("\033[2J");
            break;
        case 2:
            printf("\033[2J");
            printstack();
            printf("+, -, *, /, r(raiz cuadrada), s(seno), c(coseno), t(tangante), p(potencia) ");
            scanf("%s",&ascci);
            operation(ascci);
            break;
        case 3:
            printf("\033[2J");
            printstack();
            deletefirst();
            printf("\033[2J");
            break;
        case 4:
            printf("\033[2J");
            printstack();
            deleteall();
            printf("\033[2J");
            break;
        default:
            printf("Opcion fuera del rango");
            printf("\033[2J");
            break;
        }
    }
    return 0;
}
