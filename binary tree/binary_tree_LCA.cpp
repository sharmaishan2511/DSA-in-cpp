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

Node *LCA(Node *root,Node *a,Node *b){
    Node *l,*r;
    if(root==NULL){
        return root;
    }
    if(root == a || root == b){
        return root;
    }

    l = LCA(root->left,a,b);
    r = LCA(root->right,a,b);

    if(l && r)
        return root;
    else
        return (l!= NULL)? l:r;

}

int main(){

    Node *q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(3);

    q->left->left = new Node(4);
    q->left->right = new Node(5);

    q->right->left = new Node(6);
    q->right->right = new Node(7);

    cout<<LCA(q,q->right->right,q->right->left)->data;
    return 0;
}
