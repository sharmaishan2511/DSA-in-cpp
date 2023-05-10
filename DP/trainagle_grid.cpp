#include <bits/stdc++.h>
using namespace std;

int triangle_grid(vector<vector<int>> &v,int i,int j,int n){

    if(i==n-1){
        return v[n-1][j];
    }

    int up = v[i][j]+triangle_grid(v,i+1,j,n);
    int diag = v[i][j]+triangle_grid(v,i+1,j+1,n);

    return min(up,diag);
}

int triangle_grid2(vector<vector<int>> &v,int i,int j,int n,vector<vector<int>> &dp){

    if(i==n-1){
        return v[n-1][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int up = v[i][j]+triangle_grid2(v,i+1,j,n,dp);
    int diag = v[i][j]+triangle_grid2(v,i+1,j+1,n,dp);

    return dp[i][j]=min(up,diag);
}

int triangle_grid3(vector<vector<int>> &v,int i,int j,int n,vector<vector<int>> &dp){

    for(int j=0;j<n;j++){
        dp[n-1][j] = v[n-1][j];
    }

    for(int i = n-2;i>=0;i--){
        for(int j = i;j>=0;j--){
            int d = v[i][j] + dp[i+1][j];
            int dg = v[i][j] + dp[i+1][j+1];
            dp[i][j] = min(d,dg);
        }
    }
    return dp[0][0];
}

int triangle_grid4(vector<vector<int>> &v,int i,int j,int n){

    vector<int> front(n,0),curr(n,0);
    for(int j=0;j<n;j++){
        front[j] = v[n-1][j];
    }

    for(int i = n-2;i>=0;i--){
        for(int j = i;j>=0;j--){
            int d = v[i][j] + front[j];
            int dg = v[i][j] + front[j+1];
            curr[j] = min(d,dg);
        }
        front = curr;
    }
    return front[0];
}

int main(){
    vector<vector<int>> v = {{1},
                            {2,3},
                            {3,6,7},
                            {8,9,6,10}};
    int n = v.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<triangle_grid4(v,0,0,n);
	return 0;
}
