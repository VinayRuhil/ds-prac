2. Write a program to implement doubly linked list as an ADT that supports the following operations: 

 i. Insert an element x at the beginning of the doubly linked list 

 ii. Insert an element x at the end of the doubly linked list 

 iii. Remove an element from the beginning of the doubly linked list  

 iv. Remove an element from the end of the doubly linked list 

 

 

Sol:- 

 

#include <iostream> 

using namespace std; 

  

class Node{ 

public: 

int elem; 

Node* next; 

Node* prev; 

Node (const int n){ 

elem = n; 

next = NULL; 

prev = NULL; 

} 

}; 

  

class linkedlist{ 

public: 

Node* head; 

linkedlist(){ 

head = NULL; 

} 

  

void insertathead(int val){ 

Node* p = new Node(val); 

p->next = head; 

if(head!=NULL){ 

head->prev = p; 

} 

head = p; 

  

} 

  

  

void insertattail(int val){ 

if(head==NULL){ 

insertathead(val); 

return; 

} 

Node* p = new Node(val); 

Node* temp = head; 

while(temp->next!=NULL){ 

temp = temp->next; 

} 

temp->next = p; 

p->prev = temp; 

} 

  

void deletionathead(){ 

Node* todelete = head; 

head = head->next; 

head->prev = NULL; 

delete todelete; 

} 

  

  

  

  

void deletionatEnd() { 

    if (head == nullptr) { 

        cout << "List is empty.\n"; 

        return; 

    } 

  

    if (head->next == nullptr) { 

        delete head; 

        head = nullptr; 

        return; 

    } 

  

    Node* current = head; 

    while (current->next != nullptr) { 

        current = current->next; 

    } 

  

     

    if (current->prev != nullptr) {  

        current->prev->next = nullptr; 

    } else { 

        head = nullptr; 

    } 

  

    delete current; 

} 

  

void display(){ 

Node* temp = head; 

cout<<"Doubly Linked List = "; 

while(temp!=NULL){ 

cout<<temp->elem<<" "; 

temp =temp->next; 

} 

cout<<endl<<endl;  

} 

  

}; 

  

int main(){ 

int val , a , b , choice , subchoice; 

linkedlist l1 ; 

l1.insertattail(1); 

l1.insertattail(2); 

l1.insertattail(3); 

l1.insertattail(4); 

l1.insertattail(5); 

l1.display(); 

do { 

        cout << "Menu:\n"; 

        cout << "1. Insertion\n"; 

        cout << "2. Deletion\n"; 

        cout << "3. Exit\n"<<endl; 

        cout << "Enter your choice: "; 

        cin  >> choice; 

  

        switch (choice) { 

            case 1: 

                do{ 

cout<<"1. Insertion at last\n"; 

cout<<"2. Insertion at head\n"; 

cout<<"3. Exit\n"; 

cout<<"\nEnter your choice : "; 

cin>>subchoice; 

cout<<endl; 

switch(subchoice){ 

case 1: 

l1.display(); 

cout<<"Enter element to be inserted : "; 

            cin>>val; 

            l1.insertattail(val); 

cout<<endl; 

l1.display(); 

cout<<endl; 

break; 

case 2: 

l1.display(); 

cout<<"Enter element to be inserted : "; 

            cin>>val; 

            l1.insertathead(val); 

            cout<<endl; 

            l1.display(); 

            cout<<endl; 

break; 

case 3: 

cout<<"Returning to Main Menu \n"<<endl; 

break; 

default: 

cout<<"Invalid choice. Try again...... \n"; 

} 

}while(subchoice != 3); 

                break;  

case 2: 

do{ 

cout<<"1. Deletion at head\n"; 

cout<<"2. Deleting at end\n"; 

cout<<"3. Exit\n"; 

cout<<"\nEnter your choice : "; 

cin>>subchoice; 

switch(subchoice){ 

case 1: 

l1.deletionathead(); 

cout<<endl; 

l1.display(); 

break; 

case 2: 

l1.deletionatEnd(); 

cout<<endl; 

l1.display(); 

break; 

case 3: 

cout<<"Returning to Main Menu \n"<<endl; 

break; 

default: 

cout<<"Invalid choice. Try again...... \n"; 

} 

}while(subchoice != 3); 

                break; 

                 

        case 3: 

                cout<<"Exiting the program.\n"; 

                break; 

            default: 

                cout<<"Invalid choice. Please try again.\n"; 

        } 

    } while (choice != 3); 

  

} 
