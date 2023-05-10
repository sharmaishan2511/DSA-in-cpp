#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void push(Node **head,int val){
    Node *ptr=new Node();

    ptr->next = *head;
    ptr->data=val;
    *head=ptr;
}

void lltrav(Node *head){
    Node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

Node *merging(Node *a,Node *b){
    Node *result=NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);


    if(a->data <= b->data){
        result = a;
        result->next = merging(a->next,b);
    }else{
        result = b;
        result->next = merging(a,b->next);
    }

    return result;
};

void splitting(Node *source,Node **frontside,Node **backside){
    Node *slow=source;
    Node *fast=source->next;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }

    *frontside=source;
    *backside=slow->next;
    slow->next = NULL;
}

void mergesort(Node **headref){
    Node *head = *headref;
    Node *a;
    Node *b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    splitting(head,&a,&b);

    mergesort(&a);
    mergesort(&b);

    *headref = merging(a,b);
}

int main(){
    Node *head=NULL;

    push(&head,4);
    push(&head,67);
    push(&head,12);
    push(&head,23);
    push(&head,1);
    push(&head,9);

    lltrav(head);
    mergesort(&head);
    lltrav(head);

    return 0;
}
