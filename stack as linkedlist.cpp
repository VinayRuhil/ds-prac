#include <iostream>
using namespace std;


class Node{
	public:
		int data;
		Node* next;
	Node(int val){
		data = val;
		next = NULL;
		
	}
	
};



class Stack{
	private:
		Node* top;
	public:
		Stack(){
			top = NULL;
		}
		
		
		
		
	void push(int value){
		Node* p = new Node(val);
		p->next = top;
		top = p;
	}
	
	
	
	int pop(){
		int value = top->data;
		Node* temp = top;
		top = top->next;
		delete top;
		return value;
	}
	
	
	
};
