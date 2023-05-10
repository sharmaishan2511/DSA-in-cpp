#include<bits/stdc++.h>

using namespace std;


class Queue{
public:
    int fron,rear,siz;
    unsigned capacity;
    int *arr;
};

Queue* createq(unsigned capacity){
    Queue *queu = new Queue();
    queu->capacity = capacity;
    queu->siz = 0;
    queu->fron = 0;
    queu->rear = capacity-1;
    queu->arr = new int[queu->capacity];
    return queu;
}

bool isfull(Queue *q){
    if(q->siz==q->capacity){
        return true;
    }else{
        return false;
    }
}

bool isempty(Queue *q){
    if(q->siz==0){
        return true;
    }else{
        return false;
    }
}

void enqueue(Queue *q,int v){
    if(isfull(q)){
        return;
    }
    q->rear = (q->rear+1)%q->capacity;
    q->arr[q->rear]=v;
    q->siz=q->siz+1;
    cout<<v<<" enqueued in the queue\n";
}

int dequeue(Queue *q){
    if(isempty(q))
        return INT_MIN;
    int item = q->arr[q->fron];
    q->fron = (q->fron+1) % q->capacity;
    q->siz=q->siz-1;
    return item;
}

int frontitem(Queue *q){
    if (isempty(q))
        return INT_MIN;
    return q->arr[q->fron];
}

int rearitem(Queue *q){
    if (isempty(q))
        return INT_MIN;
    return q->arr[q->rear];
}

int main(){

    Queue* q=createq(100);

    enqueue(q,23);
    enqueue(q,25);
    enqueue(q,36);
    enqueue(q,41);
    enqueue(q,99);

    cout<<"\n"<<frontitem(q)<<" front item before op\n";
    cout<<rearitem(q)<<" rear item before op\n\n";

    cout<<dequeue(q)<<" dequed from the queue\n\n";

    cout<<frontitem(q)<<" front item after op\n";
    cout<<rearitem(q)<<" rear item after op\n";

    return 0;
}
