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

void postorder(Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
    }
}

void postordernonr(Node *root){
    stack<Node*> st;
    Node *prev=NULL;
    do{
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        while(root==NULL && !st.empty()){
            root=st.top();
            if(root->right==NULL || root->right==prev){
                cout<<root->data;
                st.pop();
                prev = root;
                root=NULL;
            }else{
                root=root->right;
            }
        }
    }while(!st.empty());

}

int main(){

    Node *q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(3);

    q->left->left = new Node(4);
    q->left->right = new Node(5);

    q->right->left = new Node(6);
    q->right->right = new Node(7);

    postorder(q);cout<<endl;
    postordernonr(q);

    return 0;
}
