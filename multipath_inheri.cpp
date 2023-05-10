#include<iostream>

using namespace std;

class A{
public:
    A(){cout<<"Im from class A"<<endl;}
    void put(){cout<<"put function from A"<<endl;}
};

class B:virtual public A{
public:
    B(){cout<<"Im from class B"<<endl;}
    void put(){cout<<"put function from B"<<endl;}
};

class C:virtual public A{
public:
    C(){cout<<"Im from class C"<<endl;}
    void put(){cout<<"put function from C"<<endl;}
};

class D:public B,public C{
public:
    D(){cout<<"Im from class D"<<endl;}
    void put(){cout<<"put function from D"<<endl;}

};


int main(){
    D d1;
    d1.A::put();

    return 0;
}
