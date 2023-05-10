#include <bits/stdc++.h>
using namespace std;

void f(int arr[],int n,vector<int> &v,int k){
    if(k==0){
        for(auto it : v){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    if(k<0) return;

    for(int i = 0;i<n;i++){
        int rem = k-arr[i];
        v.push_back(arr[i]);
        f(arr,n,v,rem);
        v.pop_back();
    }
}

int main(){
    int arr[] = {3,1,5};
    int n = 3;
    int k = 6;
    vector<int> v;

    f(arr,n,v,k);

	return 0;
}
