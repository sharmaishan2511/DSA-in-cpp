#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> &arr,int ind,int k){
    if(k==0) return true;
    if(ind==0){
        if(arr[0] == k){
            return true;
        }else{
            return false;
        }
    }

    bool nottake = f(arr,ind-1,k);
    bool take = false;
    if(k>=arr[ind])
        take = f(arr,ind-1,k-arr[ind]);

    return take|nottake;
}

int main(){
    vector<int> v = {3,4,9,8,23,2};
    int n = v.size();

    cout<<f(v,n-1,10);
	return 0;
}
