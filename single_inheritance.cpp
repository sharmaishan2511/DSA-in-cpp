#include<iostream>

using namespace std;

class Base{
    private:
        int b1;
    protected:
        int b2;
    public:
        int b3;
        Base(){
            cout<<"Base class constructor"<<endl;
            b1=10;
            b2=20;
            b3=30;
        }

};

class Derived:public Base{
    private:
        int d1;
    protected:
        int d2;
    public:
        int d3;
        Derived(){
            cout<<"Derived constructor\n";
            d1=100;
            d2=200;
            d3=300;
        }
        void disp(){
            cout<<"Basse class\n";
            cout<<b2<<"\t"<<b3<<endl;
            cout<<"Derived class\n";
            cout<<d1<<"\t"<<d2<<"\t"<<d3<<endl;
        }

};



int main(){
    Derived d;
    d.disp();



    return 0;
}
