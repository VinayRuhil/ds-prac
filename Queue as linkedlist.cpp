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



class Queue{
	private:
		Node* front;
		Node* rear;
	public:
		Queue(){
			front = NULL;
			rear = NULL;
		}
		
		
		
	bool isempty(){
		return front==NULL;
		
	}
	
	void enque(int val){
		Node* p = new Node(val);
		if(isempty()){
			front = rear = p;
		}
		else{
			rear->next = p;
			rear = p;
		}
		
	}
	
	int dequeue(){
		int val = front->data;
		Node* p = front;
		front = front->next;
		delete p;
		return val;
	}
	
	void display(){
    Node* p = front;
    if(isempty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue: ";
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

	
	
};


int main(){
	
	Queue q1;
	
	q1.enque(2);
	q1.enque(1);
	q1.enque(6);
	q1.enque(4);
	q1.enque(3);
	
	q1.display();
	
	q1.dequeue();
	q1.display();
	
}
