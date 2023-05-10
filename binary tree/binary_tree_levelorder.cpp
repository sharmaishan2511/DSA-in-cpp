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

void levelorder(Node *root){
    Node *temp;
    queue<Node*> q;
    if(!root)
        return;
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
}

void level_order_newline(Node *root){
    Node *temp;
    queue<Node*> q;

    if(!q.empty()){
        return;
    }

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            cout<<endl;
        }else{
            cout<<temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

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

    levelorder(q);

    return 0;
}
