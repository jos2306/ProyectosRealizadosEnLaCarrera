#include<stdio.h>
#include<stdlib.h>

void suma(float a, float b, float res);
void resta(float a, float b, float res);
void multiplicacion(float a, float b, float res);
void division(float a, float b, float res);
int main()
{
	int o;
	float a,b,res;
	char op;
	float u,d,re;
	do
	{
	system("cls");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Menu\n");
	printf(" \n\t\t\t\t Calculadora\n\n");
	printf("1 Suma \n");
	printf("2 Resta \n");
	printf("3 Multiplicacion \n");
	printf("4 Division \n");
	printf("5 Salir\n");
	printf("\nEscoge una opcion de menu: ");
	scanf("%d",&o);
	while(o<=0 || o>5)
	{
		printf("Error, Escoge una opcion del menu:");
		scanf("%d",&o);
	}
	system("cls");
	switch(o)
	{
		case 1:
			do
			{
			system("cls");
			printf("\nSuma\n");
			printf("\n");
			printf("\nIntroduzca primer numero: ");
			scanf("%f",&a);
			printf("Introduzca segundo numero: ");
			scanf("%f",&b);
			suma(a,b,res);
			do
			{
			fflush(stdin);
			printf("Realizar otra suma S/N :  ");
			scanf("%c",&op);
			}
			while(op!='s' && op!='n');
			}
			while(op=='s');
		break;
		
		case 2:
			do
			{
			system("cls");
			printf("\nResta\n");
			printf("\n");
			printf("Introduzca el primer numero: ");
			scanf("%f",&a);
			printf("Introduzca el segundo numero: ");
			scanf("%f",&b);
			resta(a,b,res);
			do
			{
			fflush(stdin);
			printf("Realizar otra resta S/N: ");
			scanf("%c",&op);
			}
			while(op!='s' && op!='n');
			}
			while(op=='s');
			
		break;
		
		case 3:
			do
			{
			system("cls");
			printf("\nMultiplicacion\n");
			printf("\n");
			printf("Introduzca primer numero: ");
			scanf("%f",&a);
			printf("Introduzca segundo numero: ");
			scanf("%f",&b);
			multiplicacion(a,b,res);
			do
			{
			fflush(stdin);
			printf("Realizar otra Multiplicacion S/N: ");
			scanf("%c",&op);
			}
			while(op!='s' && op!='n');
			}
			while(op=='s');
		break;
		
		case 4:
			
			do
			{
			system("cls");
			printf("\nDivision\n");
			printf("\n");
			printf("Introduzca primer numero: ");
			scanf("%f",&a);
			printf("Introduzca segundo numero: ");
			scanf("%f",&b);
			division(a,b,res);
			do
			{
		     
			fflush(stdin);
			printf("Realizar otra division S/N: ");
			scanf("%c",&op);
			}
			while(op!='s' && op!='n');
			}
			while(op=='s');
		break;
	
		case 5:
			printf("\t\t\t\nNos vemos............................");
			exit(-1);
		break;	
	}
		
		do
		{
			fflush(stdin);
			printf("Desea Realizar otra operacion S/N: ");
			scanf("%c",&op);
		}
		while(op!='s' && op!='n');
	}
	while(op=='s');
	printf("\t\t\t\nCerrando Programa............................");
}


void suma(float a,float b,float res)
{
	char op;
			
			res=a+b;
			printf("El resultado de la operacion es: %f\n",res);			
					do
					{	fflush(stdin);
						if(op=='s')
						{
						a=res;
						system("cls");
						printf("Introduce segundo numero:");
						scanf("%f",&b);
						res=a+b;
						printf("El resultado de la operacion es: %f\n",res);
						fflush(stdin);
						}
						do
						{
						fflush(stdin);
						printf("Usar el resultado como valor para hacer otra suma S/N");
						scanf("%c",&op);
						}
						while(op!='s' && op!='n');
					}
					while(op=='s');
				
}

void resta(float a,float b,float res)
{
	char op;
			
			res=a-b;
			printf("El resultado de la operacion es: %f\n",res);			
					do
					{	fflush(stdin);
						if(op=='s')
						{
						a=res;
						system("cls");
						printf("Introduce segundo numero:");
						scanf("%f",&b);
						res=a-b;
						printf("El resultado de la operacion es: %f\n",res);
						fflush(stdin);
						}
						do
						{
							fflush(stdin);
						printf("Usar el resultado como valor para hacer otra resta S/N: ");
						scanf("%c",&op);
						}
						while(op!='s' && op!='n');
					}
					while(op=='s');
}

void multiplicacion(float a,float b, float res)
{
		char op;
			
			res=a*b;
			printf("El resultado de la operacion es: %f\n",res);			
					do
					{	fflush(stdin);
						if(op=='s')
						{
						a=res;
						system("cls");
						printf("Introduce segundo numero:");
						scanf("%f",&b);
						res=a*b;
						printf("El resultado de la operacion es: %f\n",res);
						fflush(stdin);
						}
						do
						{
						printf("Usar el resultado como valor para hacer otra multiplicacion S/N: ");
						scanf("%c",&op);
						}
						while(op!='s' && op!='n');
					}
					while(op=='s');	
}

void division(float a,float b, float res)
{
	
	
	        char op;
		
			        res=a/b;
		          	printf("El resultado de la operacion es: %f\n",res);			
					do
					{	fflush(stdin);
						if(op=='s')
						{
						a=res;
						system("cls");
						printf("Introduce segundo numero:");
						scanf("%f",&b);
						res=a/b;
						printf("El resultado de la operacion es: %f\n",res);
						fflush(stdin);
						}
						do
						{
						fflush(stdin);
						printf("\nUsar el resultado como valor para hacer otra division S/N: ");
						scanf("%c",&op);
						}
						while(op!='s' && op!='n');
					}
					while(op=='s');
 
}

