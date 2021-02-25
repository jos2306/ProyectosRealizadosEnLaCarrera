#include<stdio.h>
#include<iostream>
using namespace std;
void creaarbol(struct nodo*);
void preorden(struct nodo*);
void inorden(struct nodo*);
void posorden(struct nodo*);
//void busqueda(struct abb nodo*);

struct nodo
{
	char info;
	struct nodo *izq,*der;
};

main()
{
	
	struct nodo *raiz;
	raiz=new(nodo);
	creaarbol(raiz);
	cout<<"\n recorrido pre-orden\n";
	preorden(raiz);
	cout<<"\n recorrido in orden\n";
	inorden(raiz);
	cout<<"\n un recorrido pos orden\n";
	posorden(raiz);	
	cout<<"\n busqueda: ";
	cin>>n;
}

void creaarbol(struct nodo*raiz)
{
	struct nodo*nuevo;
	int resp;
	cout<<"dato: ";
	cin>>raiz->info;
	cout<<"\n existe nodo por la izquierda de "<<raiz->info<<":";
	cin>>resp;
	if(resp==1)
	{
		nuevo=new(nodo);
		raiz->izq=nuevo;
		creaarbol(nuevo);
	}
	else
    raiz->izq=NULL;
    cout<<"\n existe nodo por la derecha de "<<raiz->info<<":";
    cin>>resp;
    if(resp==1)
    {
    	nuevo=new(nodo);
    	raiz->der=nuevo;
    	creaarbol(nuevo);
	}
		else
		raiz->der=NULL;
	
}

void preorden(struct nodo*raiz)
{
	if( raiz != NULL)
	{
		cout<<raiz->info<<" ";
		preorden(raiz->izq);
		preorden(raiz->der);
		
	}
}

void inorden(struct nodo*raiz)
{
	if(raiz != NULL)
	{
		inorden(raiz->izq);
		cout<<raiz->info<<" ";
		inorden(raiz->der);
		
	}
}

void posorden(struct nodo*raiz)
{
	if(raiz !=NULL)
	{
		posorden(raiz->izq);
		posorden(raiz->der);
		cout<<raiz->info<<" ";
	}
} 

/*void buscar(stryct nodo*raiz,char n)
{
	int resp=0;
	if(raiz->info !=n)
	{
		buscar(raiz->der,n);
		buscar(raiz->izq,n);
	}
	 else
	 resp++;
	 if(resp != 0)
	 cout<<"no esta: "<< n <<" en el arbol";
	 else
	 cout<<"si esta"<<n<<"en el arbol";*/
	 
}
