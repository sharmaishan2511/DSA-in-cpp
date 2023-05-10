#include<bits/stdc++.h>

using namespace std;

class StackNode{
public:
    int data;
    StackNode *next;
};

StackNode *newnode(int val){
    StackNode *stackNode=new StackNode();
    stackNode -> data = val;
    stackNode -> next = NULL;
    return stackNode;
}

int isEmpty(StackNode *root){
    return !root;
}

void push(StackNode **root,int v){
    StackNode *stackNode=newnode(v);
    stackNode->next=*root;
    *root=stackNode;
    cout<< v << " is pushed\n";
}

int pop(StackNode **root){
    if(isEmpty(*root))
        return INT_MIN;
    StackNode *temp = *root;
    (*root)= (*root) -> next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(StackNode **root){
    if(isEmpty(*root))
        return INT_MIN;
    return (*root)->data;
}

int main(){

    StackNode *root=NULL;

    push(&root,34);
    push(&root,65);
    push(&root,14);
    push(&root,98);

    cout<<pop(&root)<<" is popped\n";

    while(!isEmpty(root)){
        cout<<peek(&root)<<" ";
        pop(&root);
    }
    return 0;
}
