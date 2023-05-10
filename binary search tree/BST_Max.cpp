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

Node *maxelementBST(Node *root){
    if(!root){return NULL;}
    else if(root->right == NULL){
        return root;
    }else{
        return maxelementBST(root->right);
    }
}

Node *maxelementnonrBST(Node *root){
    if(!root){return NULL;}

    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
int main(){

    Node *q = new Node(7);

    q->left = new Node(4);
    q->right = new Node(9);

    q->left->left = new Node(2);
    q->left->right = new Node(5);

    cout<<maxelementBST(q)->data<<endl;
    cout<<maxelementnonrBST(q)->data;
    return 0;
}
