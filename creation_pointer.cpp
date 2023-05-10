#include<iostream>
using namespace std;

class test{
private:
    int a;
public:
    test(){
        cout<<"default constructor"<<endl;
        a=10;
    }
    void disp(){cout<<"The value of a = "<<a++<<endl;}

};


int main(){

    cout<<"test t1 is created"<<endl;
    test t1;
    t1.disp();

    cout<<"ptr is created"<<endl;
    test *ptr;
    ptr=&t1;
    ptr->disp();

    cout<<"test t2 is created"<<endl;
    test t2;
    ptr=&t2;
    ptr->disp();

    cout<<"\tdynamic object created"<<endl;
    ptr=new test();
    ptr->disp();
    delete ptr;
    return 0;

}
