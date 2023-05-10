#include<iostream>
#include<queue>
#include<string>

using namespace std;



int main(){

    string arr[7]={"aa","ab","aaa","baa","bb","ba","babb"};

    for(int i = 0;i<7;i++){
        string s = arr[i];
        if(s[0]=='b'){
            cout<<i<<endl;
        }
    }

    return 0;
}
