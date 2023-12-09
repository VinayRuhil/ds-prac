6. Write a program to implement Binary Search Tree as an ADT which supports the following operations:  

i. Insert an element x  

ii. Delete an element x  

iii. Search for an element x in the BST  

iv. Display the elements of the BST in preorder, inorder, and postorder traversal 

 

Sol:- 

#include <iostream> 
using namespace std; 
template <class T> 
class Bst; 
template<class T> 
class bstnode{ 
T ele; 
bstnode * left; 
bstnode * right; 
bstnode * parent; 
public: 
bstnode(T e = "",bstnode * l = 0, bstnode * r = 0, bstnode * p = 0){ 
ele = e; 
left = l; 
right = r; 
parent = p; 
} 
~bstnode(){ 
} 
friend class Bst<T>;  
}; 
 

template <class T> 
class Bst{ 
bstnode<T> * root; 
int size; 
public: 
Bst(){ 
root = 0; 
size = 0; 
} 
void insert(T e){ 
bstnode<T> * p = new bstnode<T>(e); 
if(root == 0){ 
root  = p; 
size++; 
return; 
}else{ 
size++; 
bstnode<T> * q = root; 
bstnode<T> * r; 
while(q!=0){ 
if(e < q->ele){ 
r = q; 
q = q->left; 
}else if(e > q->ele){ 
r = q; 
q = q->right; 
} 
} 
if(e < r->ele){ 
r->left = p; 
}else if(e > r->ele){ 
r->right = p; 
} 
} 
} 
bstnode<T> * Root(){ 
return root; 
} 
bstnode<T>* search(T e){ 
bstnode<T> * p = root; 
while(p!=0){ 
if(p->ele==e){ 
return p; 
}else if(e<p->ele){ 
p = p->left; 
}else{ 
p = p->right; 
} 
} 
return 0; 
} 
void preT(bstnode<T> * p){ 
if(p!=0){ 
cout<<p->ele<<"  "; 
preT(p->left); 
preT(p->right);  
} 
} 
void inT(bstnode<T> * p){ 
if(p!=0){ 
inT(p->left); 
cout<<p->ele<<"  "; 
inT(p->right); 
} 
} 
void postT(bstnode<T> * p){ 
if(p!=0){ 
postT(p->left); 
postT(p->right); 
cout<<p->ele<<"  "; 
} 
} 
void delbyMer(T e){ 
bstnode<T> * temp,* todel = root; 
while(todel!=0 && todel->ele!=e){ 
temp = todel; 
if(e < todel->ele){ 
todel = todel->left; 
}else{ 
todel = todel->right; 
} 
} 
if(todel!=0){ 
if(todel->left==0 && todel->right==0){ 
if(todel==root){ 
root = 0; 
}else{ 
if(todel->ele < temp->ele){ 
temp->left = 0; 
}else{ 
temp->right = 0; 
} 
} 
} 
else if(todel->right==0){ 
if(todel==root){ 
root = 0; 
}else{ 
if(todel->ele < temp->ele){ 
temp->left = todel->left; 
}else{ 
temp->right = todel->left; 
} 
} 
 
} 
else if(todel->left==0){ 
if(todel==root){ 
root = 0; 
}else{ 
if(todel->ele < temp->ele){ 
temp->left = todel->right; 
}else{ 
temp->right = todel->right; 
} 
} 
} 
else{ 
bstnode<T> * leftmax = todel->left; 
while(leftmax->right!=0){ 
leftmax = leftmax->right; 
} 
leftmax->right = todel->right; 
if(todel==root){ 
root = todel->left; 
}else{ 
if(todel->ele < temp->ele){ 
temp->left = todel->left; 
}else{ 
temp->right = todel->left; 
} 
} 
} 
//now deleting the node 
delete todel; 
} 
else{ 
cout<<"\nNode is not present\n"; 
} 
} 
}; 
 

int main(){ 
Bst<int> bt; 
cout<<"BINARY SEARCH TREE"<<endl; 
int ch; 
do{ 
cout<<"\n1. Insert"<<endl; 
cout<<"2. Preorder traversal"<<endl; 
cout<<"3. Inorder traversal"<<endl; 
cout<<"4. Postorder traversal"<<endl; 
cout<<"5. Search a node"<<endl; 
cout<<"6. Delete a node"<<endl;; 
cout<<"0. Exit"<<endl; 
cout<<"Enter your choice : "; 
cin>>ch; 
switch(ch){ 
case 1:{ 
int ele; 
cout<<"Enter an integer : "; 
cin>>ele; 
bt.insert(ele); 
break; 
} 
case 2:{ 
bt.preT(bt.Root()); 
cout<<endl; 
break; 
} 
case 3:{ 
bt.inT(bt.Root()); 
cout<<endl; 
break; 
} 
case 4:{ 
bt.postT(bt.Root()); 
cout<<endl; 
break; 
} 
case 5:{ 
int node; 
cout<<"\nEnter an integer to search : "; 
cin>>node; 
if(bt.search(node)!=0){ 
cout<<node<<" is present"<<endl; 
}else{ 
cout<<node<<" is not present"<<endl; 
} 
break; 
} 
case 6:{ 
int node; 
cout<<"\nWhich node do you want to delete : "; 
cin>>node; 
bt.delbyMer(node); 
break; 
} 
case 0:{ 
break; 
} 
default:{ 
cout<<"\nError : Invalid choice"<<endl; 
break; 
} 
} 
}while(ch!=0); 
return 0; 
} 
