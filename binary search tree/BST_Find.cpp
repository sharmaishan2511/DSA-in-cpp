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

Node *FindingBST(Node *root,int data){
    if(root==NULL)
        return NULL;
    if(data<root->data)
        return FindingBST(root->left,data);
    else if(data>root->data)
        return FindingBST(root->right,data);
    return root;
}

Node *FindingnonrBST(Node *root,int data){
    if(root==NULL)
        return NULL;

    while(root){
        if(data<root->data)
            root=root->left;
        else if(data>root->data)
            root=root->right;
        else
            return root;
    }
    return NULL;
}

int main(){

    Node *q = new Node(7);

    q->left = new Node(4);
    q->right = new Node(9);

    q->left->left = new Node(2);
    q->left->right = new Node(5);

    cout<<FindingnonrBST(q,2)->data;
    return 0;
}
