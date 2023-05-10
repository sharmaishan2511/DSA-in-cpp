#include<bits/stdc++.h>

using namespace std;

class Hash{
    int a;
    list<int> *table;
public:
    int hashfunc(int key){
        return key%a;
    }
    Hash(int v){
        this->a = v;
        this->table = new list<int>[a];
    }

    void insertItem(int key){
        int index = hashfunc(key);
        table[index].push_back(key);
    }

    void deleteItem(int key){
        int index = hashfunc(key);

        list<int>::iterator i;
        for(i = table[index].begin();i!=table[index].end();i++){
            if(*i == key){
                break;
            }
        }

        if(i != table[index].end()){
            table[index].erase(i);
        }
    }

    void displayhash(){

        for(int i = 0;i<a;i++){
            cout<<i;
            for(auto it : table[i]){
                cout<<" --> "<<it;
            }
            cout<<endl;
        }
    }
};

int main(){
    int arr[] { 8,13,3,78,9,18,55,23,5,90};
    int n = sizeof(arr)/sizeof(arr[0]);

    Hash h(10);

    for(int i = 0;i<n;i++){
        h.insertItem(arr[i]);
    }

    h.deleteItem(78);

    h.displayhash();

    return 0;
}
