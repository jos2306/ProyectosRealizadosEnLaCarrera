//Programa para comprar boletos de autobus, este marca los asientos ocupados con un "1" y los desocupados con "0", si un asiento ya se ha vendido, el programa lo señalara, tambien respetando limites en los mismos.


#include <stdio.h> 
#include <conio.h> 
main() 
{ 
int asiento[40]={0}; 
int x, y; 
printf("Los estados de los asientos son: \n\t\t\tLIBRE=0, VENDIDO=1.n" ); 
do 
{ 
printf("\n\t\t\t\tCual asiento quieres comprar?:\n " ); 
scanf("%d",&y); 
if(y==0)break; 
else if(y<=0 || y>=41) 
printf("Asiento fuera del rango del autobus.\n" ); 
else if(asiento[y-1]==1) 
printf("Asiento ya vendido\n" ); 
else 
{ 
asiento[y-1]=1; 
{ 
for(x=0; x<40; x++) 
{ 
if(!(x%4)) 
printf("Asiento %d= %d\n",x+1,asiento[x] ); 
else printf("Asiento %d= %d\n",x+1,asiento[x] ); 
} 
} 
} 
} 
while(1); 
if(asiento[40]==1) 
printf(" Todos los asientos se han vendido.\n" ); 
else printf("Gracias por usar este programa.\n" ); 
getch(); 
return 0; 
} 
