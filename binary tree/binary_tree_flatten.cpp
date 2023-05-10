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

void flatten(Node *root){
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    if(root->left){
        flatten(root->left);
        Node *temp = root->right;
        root->right=root->left;
        root->left = NULL;

        Node* t = root->right;
        while (t->right != NULL){
            t = t->right;
        }
        t->right = temp;

    }
    flatten(root->right);

}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
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

    inorder(q);
    flatten(q);
    inorder(q);
    return 0;
}
