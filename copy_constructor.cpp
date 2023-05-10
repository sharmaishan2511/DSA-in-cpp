#include<iostream>

using namespace std;

class Test{
    private:
        int *i;
    public:
        Test();
        Test(const &temp);
        void print_data();
};

Test::Test(){i = new int(100);}
void Test::print_data(){
    cout<<"The address of i = "<<&i<<endl;
    cout<<"The value at addrress of i = "<<*i<<endl;
    cout<<"The content of i = "<<i<<endl;           //the content is same in this case and hence is called shallow copy
}

int main(){
    cout<<"t1 object\n";
    Test t1;
    t1.print_data();
    cout<<"t2 object\n";
    Test t2(t1);
    t2.print_data();
    return 0;
}
