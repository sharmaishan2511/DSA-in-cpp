#include<bits/stdc++.h>

using namespace std;
#define MAX 100

class Stack{
    int top;

public:
    int a[MAX];

    Stack(){top=-1;}
    bool push(int x);
    int pop();
    int peek();
    bool isempty();

};

bool Stack::push(int x){
    if(top>=MAX-1){
        cout<<"Stack Overflow";
        return false;
    }else{
        a[++top]=x;
        cout<<x<<" is pushed"<<endl;
        return true;
    }
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack empty";
        return 0;
    }else{
        int x = a[top--];
        return x;
    }

}

int Stack::peek(){
    if(top<0){
        cout<<"Stack empty";
        return 0;
    }else{
        int x = a[top];
        return x;
    }
}

bool Stack::isempty(){
    if(top<0){
        return true;
    }else{
        return false;
    }
}

int main(){
    class Stack s;
    s.push(2);
    s.push(9);
    s.push(14);
    s.push(23);
    s.push(45);

    s.pop();

    while(s.isempty()!=true){
        cout<<s.peek()<<" ";
        s.pop();
    }
    return 0;
}
