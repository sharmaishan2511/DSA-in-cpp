#include<iostream>
#include<queue>

using namespace std;

void display_pq(priority_queue<int> p){
    priority_queue<int> q = p;

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

void display_pq_2(priority_queue<int, vector<int>,greater<int>> p){
    priority_queue<int,vector<int>,greater<int>> q = p;

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    //priority queue normally
    priority_queue<int> q;

    q.push(10);
    q.push(30);
    q.push(20);
    q.push(5);
    q.push(1);

    display_pq(q);

    //priority queue minimum heap
    priority_queue<int , vector<int>,greater<int>> q1;

    q1.push(10);
    q1.push(30);
    q1.push(20);
    q1.push(5);
    q1.push(1);

    display_pq_2(q1);
    return 0;
}
