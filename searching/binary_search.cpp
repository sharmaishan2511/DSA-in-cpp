#include<bits/stdc++.h>

using namespace std;

//recursive binary search
int binarysearch(int arr[],int lo,int hi,int x){

    int mid = (lo+hi)/2;

    if(lo<=hi){
        if(x==arr[mid]){
            return mid;
        }

        if(x>arr[mid]){
            return binarysearch(arr,mid+1,hi,x);
        }

        if(x<arr[mid]){
            return binarysearch(arr,lo,mid-1,x);
        }
    }
    return -1;
}

//iterative binary search
int binarysearch_iterative(vector<int> v,int x){
    int lo = 0;
    int hi = v.size();

    int mid;

    while(hi-lo > 1){
        mid = (hi+lo)/2;

        if(v[mid]<x){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }

    if(v[lo] == x){
        return lo;
    }
    if(v[hi] == x){
        return hi;
    }else{
        return -1;
    }
}

int main(){
    int arr[] = { 2, 3, 4, 10, 40 };
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(10);
    v.push_back(40);

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<binarysearch(arr,0,n-1,10)<<endl;
    cout<<binarysearch_iterative(v,10)<<endl;
    return 0;
}
