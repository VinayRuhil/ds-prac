3. Write a program to implement circular linked list as an ADT which supports the following operations:  

i. Insert an element x in the list  

ii. Remove an element from the list 

 iii. Search for an element x in the list and return its pointer  

 

Sol:- 

 

#include <iostream> 

using namespace std; 

  

class Node{ 

public: 

int elem; 

Node* next; 

Node (const int n){ 

elem = n; 

next = NULL; 

} 

}; 

  

class linkedlist{ 

public: 

Node* head; 

linkedlist(){ 

head = NULL; 

} 

void insertatlast(int val){ 

if(head==NULL){ 

insertathead(val); 

return; 

} 

Node* p = new Node(val); 

Node* temp = head; 

while(temp->next!=head){ 

temp = temp->next; 

} 

temp->next = p; 

p->next = head; 

} 

  

  

  

  

void deletion(int pos){ 

if(pos==1){ 

deleteathead(); 

return; 

} 

Node* temp = head; 

int count = 1; 

while(count!=pos-1){ 

temp=temp->next; 

count++; 

} 

Node* todelete = temp->next; 

temp->next = temp->next->next;  

  

delete todelete; 

} 

  

int search(Node* head, int k) { 

    if (head == nullptr) { 

        std::cout << "List is empty\n"; 

        return 0; 

    } 

  

    Node* p = head; 

    do { 

        if (p->elem == k) { 

            return 1;  

        } 

        p = p->next; 

    } while (p != head); 

  

    return 0;  

} 

  

  

void display(){ 

Node* temp=head; 

cout<<"Circular Linked List = "; 

do{ 

cout<<temp->elem<<" "; 

temp=temp->next; 

}while(temp!=head  ); 

cout<<endl<<endl; 

} 

  

}; 

  

  

  

int main(){ 

int val , a , b , choice , subchoice; 

linkedlist l1; 

l1.insertatlast(1); 

l1.insertatlast(2); 

l1.insertatlast(3); 

l1.insertatlast(4); 

l1.display(); 

do { 

        cout << "Menu:\n"; 

        cout << "1. Insertion\n"; 

        cout << "2. Deletion\n"; 

        cout << "3. Searching\n"; 

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

            l1.insertatlast(val); 

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

cout<<"2. Deleting a specific element\n"; 

cout<<"3. Exit\n"; 

cout<<"\nEnter your choice : "; 

cin>>subchoice; 

switch(subchoice){ 

case 1: 

l1.deleteathead(); 

cout<<endl; 

l1.display(); 

break; 

case 2: 

cout<<"Enter position of element to be deleted  : "; 

            cin>>val; 

            l1.deletion(val); 

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

                if(search(l1.head, 3)){ 

                cout<<"Element found\n"<<endl; 

} 

else{ 

cout<<"Element not found\n"<<endl; 

} 

                break;    

                 

                 

        case 4: 

                cout<<"Exiting the program.\n"; 

                break; 

            default: 

                cout<<"Invalid choice. Please try again.\n"; 

        } 

    } while (choice != 4); 

} 
