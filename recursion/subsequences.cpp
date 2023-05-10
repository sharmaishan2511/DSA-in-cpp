#include <bits/stdc++.h>
using namespace std;

void printing(int ind,vector<int> &v,int arr[],int n){
    if(ind == n){
        for(auto it : v){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    v.push_back(arr[ind]);
    printing(ind+1,v,arr,n);
    v.pop_back();
    printing(ind+1,v,arr,n);

}

int main(){

	int arr[] = {3,1,2};
	int n = 3;

	vector<int> v;
	printing(0,v,arr,n);
	return 0;
}
