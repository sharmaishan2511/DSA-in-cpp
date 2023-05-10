#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void lltrav(Node *n){
    while(n!=NULL){
        cout<< n->data << " ";
        n=n->next;
    }
}
int main(){

    Node *head = new Node();
    Node *sec = new Node();
    Node *thi = new Node();

    head->data=1;
    head->next = sec;

    sec->data=3;
    sec->next=thi;

    thi->data = 8;
    thi->next = NULL;

    lltrav(head);
    return 0;
}
