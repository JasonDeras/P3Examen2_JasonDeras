#include<iostream>
#include<string.h>
#include"Pila.cpp"
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int main(){
	
	while(true){
		
		cout<<"1. Ingresar una cadena\n\n";
		cout<<"2. Salir\n\n";
		cout<<"Ingrese una opcion: ";
		int opcion;
		cin>>opcion;
		
		cout<<"\n\n\n";
		
		switch(opcion){
			
			case 1:{
				
				string delimiter="";
				
				cout<<"Ingrese la cadena: ";
				string cadena;
				cin>>cadena;
				
				for(int i=0;i<cadena.size();i++){
						
					Pila* pila=new Pila();
					delimiter+=cadena.at(i);
						
					if(cadena.at(i)=='-'){
						delimiter=delimiter.size()-1;
						pila->Push(delimiter);
						pila->Push("-");
					}
						
					if(cadena.at(i)=='+'){
						delimiter=delimiter.size()-1;
						pila->Push(delimiter);
						pila->Push("+");
						delimiter="";
					}
						
					if(cadena.at(i)=='*'){
						delimiter=delimiter.size()-1;
						pila->Push(delimiter);
						pila->Push("*");
						delimiter="";
					}
						
					if(cadena.at(i)=='/'){
						delimiter=delimiter.size()-1;
						pila->Push(delimiter);
						pila->Push("/");
						delimiter="";
					}
	
				}//Fin del for
				
				system("pause");
				system("cls");
				break;
				
			}//Fin del caso 1
			
			case 2:
				exit(0);	
			break;
			
			default:
				cout<<"Opcion no valida\n\n\n";
			break;
				
		}//Fin de las opciones del menu
		
		
	}//Fin del while repetitivo
	
    system("pause");
    return 0;

}//Fin del main
