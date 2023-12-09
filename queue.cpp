5. Implement Queue as an ADT 

 

Sol:- 

 

#include <iostream> 

using namespace std; 

  

template<class T> 

  

class MyQueue{ 

T* q; 

int capacity,n,f,r; 

public: 

MyQueue(int c = 10){ 

capacity = c; 

q = new T[capacity]; 

f=r=-1; 

} 

void insert(T e){ 

if(capacity == r){ 

cout<<"Stack is full"<<endl; 

return; 

} 

r++; 

q[r] = e; 

if(f == -1){ 

f++; 

} 

} 

void display(){ 

if(f==-1){ 

cout<<"Stack is empty"<<endl; 

} 

for (int i = 0; i <= r; ++i) { 

            cout << q[i] << " "; 

        } 

        cout << endl; 

} 

void pop(){ 

if(f==-1 || f>r){ 

cout<<"Stack is empty"<<endl; 

return; 

} 

f++; 

} 

T peek(){ 

if(f==-1){ 

cout<<"Stack is empty"<<endl; 

return 0; 

}  

return q[f];  

} 

bool empty(){ 

if(f==-1 || f>r){ 

return true; 

} 

return false; 

} 

}; 

  

  

int main(){ 

 

MyQueue<int> q1; 

q1.insert(1); 

q1.insert(2); 

q1.insert(3); 

q1.insert(4); 

q1.insert(5); 

cout<<q1.peek()<<endl; 

q1.pop(); 

//q1.display(); 

cout<<q1.peek()<<endl; 

q1.pop(); 

cout<<q1.peek()<<endl; 

q1.pop(); 

cout<<q1.peek()<<endl; 

q1.pop(); 

cout<<q1.peek()<<endl; 

q1.pop(); 

cout<<q1.empty()<<endl; 

} 
