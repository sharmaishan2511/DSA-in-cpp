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

Node *insertion(Node *root,int data){
    if (!root) {
        return new Node(data);
    }

    if (data > root->data) {
        root->right = insertion(root->right, data);
    }
    else {
        root->left = insertion(root->left, data);
    }
    return root;
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){

    Node *q = new Node(7);

    q->left = new Node(4);
    q->right = new Node(9);

    q->left->left = new Node(2);
    q->left->right = new Node(5);

    inorder(q);
    q = insertion(q,1);
    inorder(q);
    return 0;
}
