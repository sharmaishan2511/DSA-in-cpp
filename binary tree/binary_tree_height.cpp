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

int height(Node *root){
    int l,r;

    if(root==NULL){
        return 0;
    }else{
        l=height(root->left);
        r=height(root->right);
        if(l>r){
            return l+1;
        }else{
            return r+1;
        }
    }

}

int heightnonr(Node *root){
    int level = 0;
    queue<Node*> q;

    if(!root)
        return -1;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        root=q.front();
        q.pop();
        if(root==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            level++;
        }else{
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);

        }
    }
    return level;
}
int main(){

    Node *q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(3);

    q->left->left = new Node(4);
    q->left->right = new Node(5);

    q->right->left = new Node(6);
    q->right->right = new Node(7);

    cout<<heightnonr(q);
    return 0;
}
