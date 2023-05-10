#include<iostream>

using namespace std;

class Test{
    int a;
    public:
        int b;
        Test(){a=10;b=20;}
        void print_data(){cout<<"the value of a = "<<a<<"\t"<<"the value of b = "<<b<<endl;}
        friend void print_data_1(Test);                          //allows you to use private a value

};
void print_data_1(Test temp){cout<<"Not a memberr of class "<<temp.a<<"  "<<temp.b<<endl;}
int main(){
    Test t1;
    //t1.print_data();
    print_data_1(t1);
    return 0;
}
