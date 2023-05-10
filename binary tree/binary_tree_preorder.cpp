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

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void preordernonr(Node * root){
    stack<Node*> st;
    while(1){
        while(root!=NULL){
            cout<<root->data;
            st.push(root);
            root=root->left;
        }
        if(st.empty()){
            break;
        }
        root=st.top();
        st.pop();
        root=root->right;
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

    preorder(q);

    cout<<endl;
    preordernonr(q);
    return 0;
}
