#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

//Prototipos
void menu();
Nodo *craerNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);

Nodo *arbol=NULL;

int main(){
	menu();
	
	getch();
	return 0;
}

//funcion de menu
void menu(){
	int dato,opcion,contador=0;
	do{
		cout<<" \t.:MENU:."<<endl;
		cout<<"1.- Insertar un nuevo nodo"<<endl;
		cout<<"2.- Mostrar arbol completo"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<"Elige una opcion: "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Digita un numero: ";
				cin>>dato;
				insertarNodo(arbol,dato);//insertamos un nuevo nodo
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"\nMostrando el arbol compketo:\n\n";
				mostrarArbol (arbol,contador);
				cout<<"\n";
				system ("pause");
				break;
		}
		system ("cls");
	}while(opcion !=3);
}

//funcion para crear un nuevo nodo
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo=new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	return nuevo_nodo;
}

//funccion para insertar elementos en el arbol
void insertarNodo (Nodo *&arbol,int n){
	if (arbol==NULL){//si el arbol esta vacio
		Nodo *nuevo_nodo=crearNodo(n);
		arbol=nuevo_nodo;
	}else{//si el arbol tiene un nodo o mas
		int valorRaiz=arbol->dato;//obtenemos el valor de la raiz
		if(n<valorRaiz){//si el elemento es menor a las raiz, insertamos en izq
			insertarNodo (arbol->izq,n);
		}else if(n>valorRaiz){//si el elemnto es mayor a la raiz, insertamos en der
			insertarNodo (arbol->der,n);
		}else if(n==valorRaiz){
			cout<<"Numero repetido";//no imprime nada solo omite el nodo que se repite
		}
	}
}

//funcion para mostrar el arbol completo 
void mostrarArbol(Nodo *arbol,int cont){
	if (arbol==NULL){//siel arbol esta vacio
		return;
	}else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}
