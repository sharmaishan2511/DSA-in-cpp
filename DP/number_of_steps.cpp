#include <bits/stdc++.h>
using namespace std;

long long int steps(int n){
    if(n<=2) return n;

    return steps(n-1) + steps(n-2);
}

//steps memoization

long long int steps2(long long int n,long long int dp[]){
    if(dp[n] != -1) return dp[n];
    if(n<=2) return n;

    dp[n]  = steps2(n-1,dp) + steps2(n-2,dp);
    return dp[n];
}

//steps tabulation

long long int steps3(long long int n,long long int dp2[]){
    dp2[1] = 1;dp2[2] = 2;

    for(long long int i = 3;i<=n;i++){
        dp2[i] = dp2[i-1] + dp2[i-2];
    }
    return dp2[n];
}

long long int steps_optimal(long long int n){
    long long int curri,prev1,prev2;
    prev2 = 1;prev1 = 2;

    for(long long int i = 3;i<=n;i++){
        curri = prev1+prev2;
        prev2=prev1;
        prev1=curri;
    }
    return curri;
}
int main(){
    long long int n;
    cin>>n;

    cout<<steps(n)<<endl;

    long long int dp[n+1];
    memset(dp,-1,sizeof dp);

    cout<<steps2(n,dp)<<endl;

    long long int dp2[n+1];
    memset(dp2,-1,sizeof dp);

    cout<<steps3(n,dp2)<<endl;
    cout<<steps_optimal(n);
	return 0;
}
