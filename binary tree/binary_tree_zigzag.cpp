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

void zigzag(Node *root){
    Node *temp;
    int left_to_right = 1;
    stack<Node*> currlevel;
    stack<Node*> nextlevel;

    if(!root){
        return;
    }

    currlevel.push(root);

    while(!currlevel.empty()){
        temp = currlevel.top();
        currlevel.pop();

        if(temp){
            cout<<temp->data;
            if(left_to_right){
                if(temp->left)
                    nextlevel.push(temp->left);
                if(temp->right)
                    nextlevel.push(temp->right);
            }else{
                if(temp->right)
                    nextlevel.push(temp->right);
                if(temp->left)
                    nextlevel.push(temp->left);
            }
        }
        if(currlevel.empty()){
            left_to_right = 1- left_to_right;
            swap(currlevel,nextlevel);
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

    zigzag(q);
    return 0;
}
