1. Write a program to implement singly linked list as an ADT that supports the following operations: 

 i. Insert an element x at the beginning of the singly linked list 

 ii. Insert an element x at ith position in the singly linked list 

 iii. Remove an element from the beginning of the singly linked list  

iv. Remove an element from ith position in the singly linked list.  

v. Search for an element x in the singly linked list and return its pointer 

 

Sol:-      

 

#include <iostream> 

using namespace std; 

  

class Node{ 

public: 

int elem; 

Node* next; 

Node (int n){ 

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

Node* p = new Node(val); 

if(head==NULL){ 

head = p; 

return; 

} 

Node* temp = head; 

while(temp->next!=NULL){ 

temp = temp->next; 

} 

temp->next = p; 

} 

  

void insertathead(int val){ 

Node* p = new Node(val); 

if(head == 0){ 

head = p; 

} 

p->next = head; 

head = p; 

} 

 

void insertAtIthPosition(int val, int position) { 

    Node* p = new Node(val); 

  

    if (position == 0) { 

        p->next = head; 

        head = p; 

    } else { 

        Node* current = head; 

        for (int i = 0; i < position - 1 && current != nullptr; ++i) { 

            current = current->next; 

        } 

  

        if (current != nullptr) { 

            p->next = current->next; 

            current->next = p; 

        } else { 

            cout << "Invalid position.\n"; 

            delete p;  

        } 

    } 

} 

 

  

void display(){ 

Node* temp = head; 

cout<<"Linked List = "; 

while(temp!=NULL){ 

cout<<temp->elem<<" "; 

temp = temp->next; 

} 

cout<<endl<<endl; 

} 

}; 

   

  

void deletionathead(Node* &head){ 

Node* p = head; 

head = head->next; 

delete p; 

} 

 

 

void removeAtIthPosition(int position) { 

    if (head == nullptr) { 

        cout << "List is empty.\n"; 

        return; 

    } 

  

    if (position == 0) { 

       

        Node* temp = head; 

        head = head->next; 

        delete temp; 

        return; 

    } 

  

    Node* current = head; 

    Node* previous = nullptr; 

  

    for (int i = 0; i < position && current != nullptr; ++i) { 

        previous = current; 

        current = current->next; 

    } 

  

    if (current == nullptr) { 

        cout << "Invalid position.\n"; 

        return; 

    } 

  

    previous->next = current->next; 

    delete current; 

} 

  

   

  

  

int search(Node* head, int k){ 

Node* p = head; 

if(p == NULL){ 

cout<<"List is empty\n"; 

} 

else{ 

while(p!=NULL){ 

if(p->elem == k) 

return 1; 

p = p->next; 

} 

return 0;  

} 

} 

  

  

  

int main(){ 

int choice , val , a , b , n; 

linkedlist l1; 

l1.insertatlast(2); 

l1.insertatlast(1); 

l1.insertatlast(4); 

l1.insertatlast(5); 

l1.insertatlast(3); 

l1.display(); 

do { 

        cout << "Menu:\n"; 

        cout << "1. Insertion at begining\n"; 

        cout << "2. Insertion at a position\n"; 

        cout << "3. Deletion at head\n"; 

        cout << "4. Deletion at a position\n"; 

        cout << "5. Searching\n"; 

        cout << "6. Exit\n"<<endl; 

        cout << "Enter your choice: "; 

        cin >> choice; 

  

        switch (choice) { 

            

 case 1: 

            cout<<"Enter element to be inserted : "; 

            cin>>val; 

            l1.insertathead(val); 

cout<<endl; 

l1.display();  

break; 

 

 

case 2: 

cout<<"Enter element to be inserted : "; 

 cin>>val; 

cout<<"Enter position  : "; 

 cin>>pos; 

 

 l1.insertAtIthPosition(val,pos); 

cout<<endl; 

l1.display();  

break; 

 

 

 

             

case 3: 

           l1.display(); 

deletionathead(l1.head); 

l1.display(); 

break; 

 

             

Case 4: 

             cout<<"Enter position to be removed : "; 

            cin>>val; 

            l1.removeAtIthPosition(val); 

cout<<endl; 

l1.display();  

break; 

 

             

case 5: 

                if(search(l1.head, 13)){ 

                cout<<"Element found\n"<<endl; 

} 

else{ 

cout<<"Element not found\n"<<endl; 

} 

                break; 

                             

case 6: 

                cout<<"Exiting the program.\n"; 

                break; 

            default: 

                cout<<"Invalid choice. Please try again.\n"; 

        } 

    } while (choice != 6); 

  

} 
