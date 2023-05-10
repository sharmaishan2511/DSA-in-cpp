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

int sumele(Node *root){
    if(!root){return 0;}


    return root->data+sumele(root->left)+sumele(root->right);
}

void sumtree(Node *root){
    if(!root){return;}
    Node * temp;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        temp->data = sumele(temp)-temp->data;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void preorder(Node *root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){

    Node *q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(3);

    q->left->left = new Node(4);
    q->left->right = new Node(5);

    q->right->left = new Node(6);
    q->right->right = new Node(7);

    sumtree(q);
    preorder(q);
    return 0;
}
