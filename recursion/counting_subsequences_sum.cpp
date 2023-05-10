#include <bits/stdc++.h>
using namespace std;

int f(int ind,int arr[],int cursum,int n ,int k){
    if(ind == n){
        if(k==cursum){
            return 1;
        }
        return 0;
    }

    cursum+=arr[ind];
    int l = f(ind+1,arr,cursum,n,k);

    cursum-=arr[ind];
    int r = f(ind+1,arr,cursum,n,k);

    return l+r;
}

int main(){

	int arr[] = {1,2,1};
	int n = 3,k=2;

    cout<<f(0,arr,0,n,k);
	return 0;
}
