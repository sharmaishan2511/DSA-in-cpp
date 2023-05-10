#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,vector<vector<int>> &dp){
    int n = s1.size();
    int m = s2.size();

    for(int i = 0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j = 0;j<=m;j++){
        dp[0][j]=0;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main(){

    string s1 = "ACGTTCGA";
    string s2 = "BCTBBCA";
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int i = 0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j = 0;j<=m;j++){
        dp[0][j]=0;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int lcsval = dp[n][m];

    string s3 = "";

    for(int i = 0;i<lcsval;i++){
        s3+='$';
    }

    int i = n;
    int j = m;

    int index = lcsval-1;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s3[index] = s1[i-1];
            index--;
            i--;j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    cout<<s3;
	return 0;
}
