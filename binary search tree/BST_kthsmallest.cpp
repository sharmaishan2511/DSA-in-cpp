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
int c=0;
Node* kthsmallestelement(Node *root, int k){

    if(!root){return NULL;}

    Node *left = kthsmallestelement(root->left,k);

    if(left)
        return left;
    c++;
    if(c==k)
        return root;

   return kthsmallestelement(root->right,k);
}

int main(){

    Node *q = new Node(7);

    q->left = new Node(4);
    q->right = new Node(9);

    q->left->left = new Node(2);
    q->left->right = new Node(5);

    cout<<kthsmallestelement(q,2)->data;
    return 0;
}
