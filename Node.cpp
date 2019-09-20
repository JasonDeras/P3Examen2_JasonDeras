#include<iostream> 
#include<string> 
#ifndef NODE_CPP
#define NODE_CPP

using namespace std;

class Node{
	
      private:
      	
        string value;
        Node* next_node;
		                         
      public:
      	
        Node(string value){
        	this->value=value;
        	next_node=NULL;
		}
                         
        void setValue(string value){
        	this->value=value;  
        }
        
        string getValue(){
            return value;
        }
		
		void setNext_Node(Node* next_node){
			this->next_node=next_node;
		}
		
		Node* getNext_Node(){
			return next_node;
		}
		
		void print(){
			cout<<"Valor: "<<value<<endl;;
			
		}
		
		~Node(){}             
};
#endif
