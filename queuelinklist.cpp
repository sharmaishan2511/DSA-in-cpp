#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *fron=NULL;
Node *rear=NULL;

struct Queue{
    Node *fron;
    Node *rear;
    Queue(){
        fron=rear=NULL;
    }

    void enq(int v){
        Node *ptr= new Node();
        ptr->data=v;
        ptr->next=NULL;

        if(fron==NULL){
            fron=ptr;
            rear=ptr;
        }
        else{
            rear->next=ptr;
            rear=ptr;
        }
    }
    void deq(){
        if(fron==NULL){
            return;
        }
        Node *ptr = fron;
        fron=fron->next;

        if(fron==NULL){
            rear=NULL;
        }
        delete (ptr);

        }
};


int main(){

    Queue q;
    q.enq(4);
    q.enq(6);
    q.enq(12);
    q.enq(23);
    q.enq(8);
    q.enq(90);

    q.deq();

    cout<<(q.fron)->data<<endl;
    cout<<(q.rear)->data<<endl;
    return 0;
}
