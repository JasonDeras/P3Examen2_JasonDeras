#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<string.h>
#include<fstream>
#include"Pila.cpp"

using namespace std;

int main(){
	
	int r=1;
	
	while (r==1){
		
		string expresion;
		cout<<"Ingrese una expresion aritmetica: ";
		cin>>expresion;
		
		Pila* pila=new Pila();
		int contador=0;
		
		string temporal;
		
		for (int i=0; i<expresion.size(); i++){
			
			temporal="";
			while (expresion[i]!='+' && expresion[i]!='-' && expresion[i]!='*' && expresion[i]!='/' && i<expresion.size()){
				
				temporal+=expresion[i];
				i++;
				
			}//Fin del primer while
			
			if (temporal!=""){
				
				pila->Push(temporal);
				temporal="";
				contador++;
				
			}//Fin del primer if
			
			if (expresion[i]=='-'){
				
				pila->Push("+");
				contador++;
				temporal+=expresion[i];
				i++;
				
				while (expresion[i]!='+' && expresion[i]!='-' && expresion[i]!='*' && expresion[i]!='/' && i<expresion.size()){
					
					temporal+=expresion[i];
					i++;
					
				}//Fin del segundo while
				
			}//Fin del segundo if
			
			if (temporal!=""){
				
				pila->Push(temporal);
				temporal="";
				contador++;
				
			}//Fin del tercer if
			
			if (expresion[i]=='+' || expresion[i]=='*' || expresion[i]=='/'){
				
				temporal+=expresion[i];
				
			}//Fin del cuarto if
			
			if (temporal!=""){
				
				pila->Push(temporal);
				temporal="";
				contador++;
				
			}//Fin del quinto if
			
		}//Fin del for 
		
		//Escritura del archivo
		int contador1=0;
		int contador_temporal=contador;
		int result;
		ofstream escribir;
        escribir.open("./salida.txt", ios::app);
        escribir<<"Nueva operacion"<<endl;
        
		while (contador1<contador){
			
			int contador2=0;
			Node* node_temporal=pila->Top();
			
			while (contador2<contador_temporal){
				
				node_temporal->print();
				escribir<<node_temporal->getValue();
				node_temporal=node_temporal->getNext_Node();
				contador2++;
			}
			
			cout<<endl;
			
			escribir<<endl;
			
			int numero1= atoi(pila->Pop()->getValue().c_str());
			string operador=pila->Pop()->getValue();
			int numero2=atoi(pila->Pop()->getValue().c_str());
			
			if (operador=="+"){
				
				result=numero1+numero2;
				stringstream conversion;
				conversion << result;
				string temp_resultado = conversion.str();
				pila->Push(temp_resultado);
				
			}else{//If de la suma
				
				if (operador=="*"){
					
					result=numero1*numero2;
					stringstream conversion;
					conversion << result;
					string temp_resultado = conversion.str();
					pila->Push(temp_resultado);
					
				}else{//If de la multiplicacion
					
					if (operador=="/"){
						
						result=numero2/numero1;
						stringstream conversion;
						conversion << result;
						string temp_resultado = conversion.str();
						pila->Push(temp_resultado);
						
					}//If de la division
				}
			}//Fin de los ifs anidados
			
			contador1+=3;
			contador_temporal-=2;
			
		}//Fin del while
		
		//Impresion y limpieza de memoria
		pila->Top()->print();
		escribir<<pila->Top()->getValue();
		cout<<endl;
		
		//Escritura del archivo
		escribir<<endl<<endl;
		escribir.close();
		pila->~Pila();
		
		cout<<"Volver al menu?1. Si,2.No: ";
		cin>>r;
		system("cls");
		
	}//Fin del while
	
	system("pause");
	return 0;

}//Fin del main
