#include<iostream>
#include<queue>

using namespace std;

void dispq(queue<int> p){

    while(!p.empty()){
        cout<<p.front()<<" ";
        p.pop();
    }
    cout<<"\n";
}

int main(){

    queue<int> g;
    g.push(1);
    g.push(3);
    g.push(5);
    g.push(8);
    g.push(9);

    dispq(g);

    cout<< "front func "<< g.front()<<endl;
    cout<<"back func "<< g.back()<<endl;
    cout<<"size is "<<g.size()<<endl;

    g.pop();

    dispq(g);
    cout<<"size is "<<g.size()<<endl;

    return 0;
}
