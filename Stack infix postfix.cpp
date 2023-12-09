4. Implement Stack as an ADT and use it to evaluate a prefix/postfix expression. 

 

Sol:- 

 


#include <iostream> 

using namespace std; 

  

  

template<class T> 

  

class Stack{ 

public: 

T* arr; 

int top; 

int capacity; 

Stack() 

{ 

capacity = 10; 

top = -1; 

arr = new T[capacity]; 

} 

void push(T x) 

{ 

if(top==capacity-1){ 

cout<<"Stack is full"<<endl; 

return; 

} 

top++; 

arr[top] = x; 

} 

void pop(){ 

if(top==-1){ 

cout<<"No element to pop"<<endl; 

return; 

} 

top--; 

} 

T Top(){ 

if(top==-1){ 

cout<<"No element in stack"<<endl; 

return 0; 

} 

return arr[top]; 

} 

bool empty(){ 

return top==-1; 

} 

void display(){ 

if(top==-1){ 

cout<<"Stack is empty"<<endl; 

} 

cout<<"Stack = "; 

for (int i = 0; i <= top; ++i) { 

            cout << arr[i] << " "; 

        } 

        cout << endl; 

} 

int size(){ 

return top+1; 

}

};

  

int prec(char ch) { 

    if (ch == '^') 

        return 3; 

    else if (ch == '/' || ch == '*') 

        return 2; 

    else if (ch == '+' || ch == '-') 

        return 1; 

    else 

        return -1; 

} 

  

string infixToPostfix(const string& infix) { 

    Stack<char> stack; 

    string postfix = ""; 

  

   for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];

        if (isalnum(ch)) { 

            postfix += ch; 

        } else if (ch == '(') { 

            stack.push(ch); 

        } else if (ch == ')') { 

            while (!stack.empty() && stack.Top() != '(') { 

                postfix += stack.Top(); 

                stack.pop(); 

            } 

            stack.pop(); // Pop '(' from the stack 

        } else { 

            while (!stack.empty() && prec(ch) <= prec(stack.Top())) { 

                postfix += stack.Top(); 

                stack.pop(); 

            } 

            stack.push(ch); 

        } 

    } 

  

    while (!stack.empty()) { 

        postfix += stack.Top(); 

        stack.pop(); 

    } 

  

    return postfix; 

} 

  

int main() {
    Stack<string> s;
    string ele, s1;
    int choice;

    s.push("A");
    s.push("B");
    s.push("C");
    s.push("D");
    s.display();
    cout << endl;

    do {
        cout << "Menu:\n";
        cout << "1. Push an Element\n";
        cout << "2. Pop last Element\n";
        cout << "3. Size\n";
        cout << "4. Element at top\n";
        cout << "5. Inflix to Postfix\n";
        cout << "6. Exit\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Enter element to be pushed : ";
                cin >> ele;
                cout << endl;
                s.push(ele);
                cout << endl;
                s.display();
                break;
            case 2:
                s.display();
                cout << endl;
                s.pop();
                s.display();
                cout << s.Top() << endl;
                break;
            case 3:
                cout << "Size of Stack = " << s.size() << endl
                     << endl;
                break;
            case 4:
                cout << "Element at Top = " << s.Top() << endl
                     << endl;
                break;
            case 5:
                cout << "Enter infix expression: ";
                cin >> ele;
                cout << "Postfix expression: " << infixToPostfix(ele) << endl
                     << endl;
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;  
    
}

  

 
