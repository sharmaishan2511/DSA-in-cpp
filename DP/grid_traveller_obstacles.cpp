#include <bits/stdc++.h>
using namespace std;

int gridpathswhenobstacles(vector<vector<int>> &v,int n,int m){

    if(n>=0 && m>=0 && v[n][m]==-1) return 0;
    if(n==0 && m==0){
        return 1;
    }
    if(n<0 || m< 0) return 0;

    int left = gridpathswhenobstacles(v,n-1,m);
    int right = gridpathswhenobstacles(v,n,m-1);

    return left+right;
}

int gridpathswhenobstacles2(vector<vector<int>> &v,int n,int m,vector<vector<int>> &dp){

    if(n>=0 && m>=0 && v[n][m]==-1) return 0;
    if(n==0 && m==0){
        return 1;
    }
    if(n<0 || m< 0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];

    int left = gridpathswhenobstacles2(v,n-1,m,dp);
    int right = gridpathswhenobstacles2(v,n,m-1,dp);

    return dp[n][m] = left+right;
}

int main(){

    vector<vector<int>> v = {{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));

    cout<<gridpathswhenobstacles2(v,v.size()-1,v[0].size()-1,dp);
	return 0;
}
