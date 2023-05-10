#include <bits/stdc++.h>
using namespace std;

bool f(int ind,vector<int> &v,int cursum,int arr[],int n,int k){
    if(ind == n){
        if(cursum == k){
            for(auto it : v)cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    v.push_back(arr[ind]);

    cursum += arr[ind];

    if(f(ind+1,v,cursum,arr,n,k) == true){
        return true;
    }

    cursum -=arr[ind];
    v.pop_back();

    if(f(ind+1,v,cursum,arr,n,k) == true){
        return true;
    }
}

int main(){

	int arr[] = {1,2,1};
	int n = 3;
    int k = 2;int cursum= 0;
	vector<int> v;
    f(0,v,cursum,arr,n,k);
	return 0;
}
