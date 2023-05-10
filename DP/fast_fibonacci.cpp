#include <bits/stdc++.h>
using namespace std;

long long int fib(long long int n,long long int dp[]){
    if(dp[n] != -1) return dp[n];
    if(n<=1) return n;

    dp[n] = fib(n-1,dp) +fib(n-2,dp);
    return dp[n];
}

long long int fibo(long long int n , map<long long int,long long int> &mp){
    if(mp.find(n) != mp.end()) return mp[n];

    if(n<=2) return 1;
    mp[n] = fibo(n-1,mp) + fibo(n-2,mp);
    return mp[n];
}

long long int fibo2(long long int n){
    if(n<=2) return 1;

    return fibo2(n-1) + fibo2(n-2);
}

int main()
{
    map<long long int,long long int> mp;
	cout<<fibo(50,mp)<<endl;

    long long int n;
    cin>>n;
    long long int dp[n+1];
    memset(dp,-1,sizeof dp);
    cout<<fib(n,dp);

	return 0;
}
