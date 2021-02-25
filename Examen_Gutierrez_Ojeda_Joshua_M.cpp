/*entradatrada de un par de variables r y N, de modo que de forma recursiva se
obtengan los N coeficientes solicitados, usando la siguiente expresión.

Elaborado por: Joshua Gutierrez Ojeda
*/

#include<stdio.h>


int recursividad(int r,int x,int n){

	if((x - 1) == 0){                             //
		return 0;
	}else{
		int fN = 0,fX = 0,res=0 ,fRes = 0, B = 0;
		res = n - x;
		for(int i = 0;i <= x; i++){
			if(i == 0){
				fX = 1;  //
			}else{
				fX = fX * i;
			}
		}
		for(int i = 0;i <= n; i++){
			if(i == 0){
				fN = 1;
			}else{
				fN = fN * i;
			}
		}
		for(int i = 0;i <= res; i++){
			if(i == 0){
				fRes = 1;
			}else{
				fRes = fRes * i;
			}
		}
		B = fN/(fX*fRes);

	}

}
int main(){
	int r,n,s;
	do{
		printf("\n r: ");
		scanf("%d",&r);
	}while(r < 0);
	do{
		printf("\n n: ");
		scanf("%d",&n);
	}while(n < 2);
	for(int i = 0; i <= n; i++){
		s = recursividad(r,i,n);
		printf("%d , ",s);
	}
	return 0;
}
