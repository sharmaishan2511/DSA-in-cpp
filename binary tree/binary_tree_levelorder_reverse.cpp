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

void revlot(Node *root){
    Node *temp;
    queue<Node*> q;
    stack<Node*> s;

    if(!root){
        return;
    }

    q.push(root);

    while(!q.empty()){
        temp=q.front();
        q.pop();

        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        s.push(temp);
    }

    while(!s.empty()){
        cout<<s.top()->data;
        s.pop();
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

    revlot(q);
    return 0;
}
