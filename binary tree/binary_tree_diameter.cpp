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

int maxi(int a , int b){
    return (a>b)? a:b;
}

int height(Node *root){
    int l,r;
    if(root==NULL)
        return 0;
    else
        l=height(root->left);
        r=height(root->right);

        return maxi(l,r)+1;

}

int diameter(Node *root){
    int lefth,righth,leftd,rightd;
    if(!root)
        return 0;

    lefth=height(root->left);
    righth = height(root->right);

    leftd=diameter(root->left);
    rightd = diameter(root->right);

    return maxi(lefth + righth + 1, maxi(leftd,rightd));
}
int main(){

    Node *q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(3);

    q->left->left = new Node(4);
    q->left->right = new Node(5);

    q->right->left = new Node(6);
    q->right->right = new Node(7);

    cout<<diameter(q);
    return 0;
}
