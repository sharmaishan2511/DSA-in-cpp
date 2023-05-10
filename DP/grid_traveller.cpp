#include <bits/stdc++.h>
using namespace std;

int gridTraveller(int n,int m){
    if(n==0 || m==0){
        return 0;
    }

    if(n==1 && m==1){
        return 1;
    }

    return gridTraveller(n-1,m) + gridTraveller(n,m-1);
}

long long int gridTraveller2(int n,int m,map<pair<int,int>,long long int> &mp){
    if(mp.find({n,m}) != mp.end()) return mp[{n,m}];

    if(n==1 && m==1) return 1;
    if(n==0 || m==0) return 0;

    mp[{n,m}] = gridTraveller2(n-1,m,mp) + gridTraveller2(n,m-1,mp);
    return mp[{n,m}];
}

int main(){
    map<pair<int,int>,long long int> mp;
    cout<<gridTraveller2(18,18,mp);
	return 0;
}
