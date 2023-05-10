#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data=d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *minelementBST(Node *root){
    if(!root){return NULL;}
    else if(root->left == NULL){
        return root;
    }else{
        return minelementBST(root->left);
    }
}

Node *minelementnonrBST(Node *root){
    if(!root){return NULL;}

    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
int main(){

    Node *q = new Node(7);

    q->left = new Node(4);
    q->right = new Node(9);

    q->left->left = new Node(2);
    q->left->right = new Node(5);

    cout<<minelementBST(q)->data<<endl;
    cout<<minelementnonrBST(q)->data;
    return 0;
}
