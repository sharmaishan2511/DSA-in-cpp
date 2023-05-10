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

int level_with_max_sum(Node *root){
    Node *temp;
    int level = 1,maxlevel = 0;
    queue<Node*> q;
    int currentsum=0,maxsum=0;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp==NULL){
            if(currentsum>maxsum){
                maxsum = currentsum;
                maxlevel = level;
            }
            currentsum = 0;
            if(!q.empty()){
                q.push(NULL);
            }
            level++;

        }else{
            currentsum+=temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return maxlevel;
}

int main(){

    Node *q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(56);

    q->left->left = new Node(4);
    q->left->right = new Node(5);

    q->right->left = new Node(6);
    q->right->right = new Node(7);

    cout<<level_with_max_sum(q);
    return 0;
}
