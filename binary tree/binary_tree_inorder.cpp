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

void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}

void inordernonr(Node *root){
    stack<Node*> st;
    while(1){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }

        if(st.empty()){
            break;
        }
        root=st.top();
        st.pop();

        cout<<root->data;
        root=root->right;
    }

}

int main(){

    Node *q = new Node(3);

    q->left = new Node(2);
    q->right = new Node(3);

    //q->left->left = new Node(0);
    q->left->right = new Node(3);

    //q->right->left = new Node(6);
    q->right->right = new Node(1);

    inorder(q);cout<<endl;
    inordernonr(q);

    return 0;
}
