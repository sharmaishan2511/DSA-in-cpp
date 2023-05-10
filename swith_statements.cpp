#include<iostream>

using namespace std;


class emp{
public:
    string name;
    string id;
    int floor;
    int sales;
    int bonus;
    emp(){
        cin>>name;
        cin>>id;
        cin>>floor;
        cin>>sales;
        bonus = 0;
    }
    friend void calc(emp);
};

void calc(emp o){
    if(o.sales >= 60000){
        o.bonus+=o.sales/100;
    }
    if(o.sales >= 800000){
        o.bonus+=3*o.sales/100;
    }
    if(o.sales >= 100000){
        o.bonus+=5*o.sales/100;
    }
    cout<<o.name<<endl;
    cout<<o.id<<endl;
    cout<<o.floor<<endl;
    cout<<o.sales<<endl;
    cout<<o.bonus<<endl;
}

int main(){
    emp e1;
    calc(e1);
    return 0;
}
