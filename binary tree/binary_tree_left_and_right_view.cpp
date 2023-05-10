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

void leftview(Node *root){
    Node *temp;
    queue<Node*> q;
    if(!root){return;}

    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i = 1;i<=n;i++){
            temp= q.front();
            q.pop();

            if(i==1){
                cout<<temp->data;
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

    }
}

void rightview(Node *root){
    if(!root){
        return;
    }
    Node *temp;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i = 1;i<=n;i++){
            temp = q.front();
            q.pop();

            if(i==n){
                cout<<temp->data;
            }

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

    leftview(q);
    rightview(q);
    return 0;
}
