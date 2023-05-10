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

void insertion(Node *root,int d){
    Node *temp;
    Node *newnode = new Node(d);
    queue<Node*> q;
    if(!newnode){
        cout<<"Memory error"<<endl;
    }

    if(!root){
        root=newnode;
        return;
    }

    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }else{
            temp->left=newnode;
            while(!q.empty()){
                q.pop();
            }
            return;
        }
        if(temp->right){
            q.push(temp->right);
        }else{
            temp->right=newnode;
            while(!q.empty()){
                q.pop();
            }
            return;
        }

    }
}

void lot(Node *root){
    Node *temp;
    queue<Node*> q;

    if(!root){
        return;
    }

    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        cout<<temp->data;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}

int main(){

    Node *q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(3);

    q->left->left = new Node(4);
    q->left->right = new Node(5);

    q->right->left = new Node(6);
    q->right->right = new Node(7);

    lot(q);
    insertion(q,8);
    lot(q);

    return 0;
}
