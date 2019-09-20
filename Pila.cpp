#include<iostream> 
#include<string> 
#include "Node.cpp"
#ifndef PILA_CPP
#define NODE_CPP

using namespace std;

class Pila{
	
      private:
      	
        Node* head;
		                         
      public:
      	
        Pila(){	
		}
                         
        void Push(string value){
        	
        	Node* temp=new Node(value);
        	temp->setNext_Node(head);
        	head=temp;
        }
        
        Node* Pop(){
        	
            Node *temp=head;
            head->getNext_Node();
            return temp;
        }
		
		Node* Top(){
			
			return head;
		}
		
		bool isEmpty(){
			
			if(head==NULL){
				return true;
			}else{
				return false;
			}
		}
		
		~Pila(){}             
};
#endif
