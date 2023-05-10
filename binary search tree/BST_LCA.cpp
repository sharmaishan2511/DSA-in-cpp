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

Node* LCA(Node *root, int n1, int n2)
{
   if(!root){return NULL;}

   if(root->data > n1 && root->data > n2){
       return LCA(root->left,n1,n2);
   }

   if(root->data < n1 && root->data < n2){
       return LCA(root->right,n1,n2);
   }

   return root;
}

int main(){

    Node *q = new Node(7);

    q->left = new Node(4);
    q->right = new Node(9);

    q->left->left = new Node(2);
    q->left->right = new Node(5);

    return 0;
}
