#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int dp[n+1];
    memset(dp,-1,sizeof dp);


    dp[0] = 0;dp[1] = 1;
    for(long long int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
	return 0;
}
