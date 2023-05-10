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
    cout<<endl;
}

Node *insertatfirst(Node *head,int val){
    Node *ptr=new Node();

    ptr->data=val;
    ptr->next=head;

    return ptr;
}

Node *insertafternode(Node *head,int val,Node *prev){
    Node *p=new Node();

    p->next=prev->next;
    prev->next = p;
    p->data = val;

    return head;
}

Node *insertatend(Node *head,int val){
    Node *ptr=head;
    Node *q=new Node();

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    ptr->next=q;
    q->next = NULL;
    q->data=val;
    return head;
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
    head = insertatend(head,7);
    lltrav(head);
    return 0;
}
