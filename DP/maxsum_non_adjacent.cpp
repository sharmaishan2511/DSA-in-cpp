#include <bits/stdc++.h>
using namespace std;

int non_adj_subsequence_sum(int arr[],int ind){
    if(ind==0) return arr[ind];
    if(ind<0) return 0;

    int pick = arr[ind]+non_adj_subsequence_sum(arr,ind-2);
    int notpick = non_adj_subsequence_sum(arr,ind-1);
    return max(pick,notpick);
}

int non_adj_subsequence_sum2(int arr[],int ind,vector<int> &dp){
    if(ind==0) return arr[ind];
    if(ind<0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind]+non_adj_subsequence_sum2(arr,ind-2,dp);
    int notpick = non_adj_subsequence_sum2(arr,ind-1,dp);

    dp[ind] = max(pick,notpick);
    return dp[ind];
}

int non_adj_subsequence_sum3(int arr[],int ind,vector<int> &dp){
    dp[0]=arr[0];

    for(int i = 1;i<ind+1;i++){
        int pick = arr[i];
        if(i>1){
            pick+=dp[i-2];
        }
        int notpick = dp[i-1];
        dp[i] = max(pick,notpick);
    }

    return dp[ind];
}

int non_adj_subsequence_sum4(int arr[],int ind){
    int prev = arr[0];
    int prev2 = 0;
    int curri;

    for(int i = 1;i<ind+1;i++){
        int pick = arr[i];
        if(i>1){
            pick+=prev2;
        }
        int notpick = prev;
        curri = max(pick,notpick);

        prev2=prev;
        prev=curri;
    }
    return prev;
}

int main(){
    int arr[] = {2,1,4,9};
    int n = 4;

    vector<int> dp(n,-1);
    vector<int> dp2(n,-1);

    cout<<non_adj_subsequence_sum(arr,n-1)<<endl;
    cout<<non_adj_subsequence_sum2(arr,n-1,dp)<<endl;
    cout<<non_adj_subsequence_sum3(arr,n-1,dp2)<<endl;
    cout<<non_adj_subsequence_sum4(arr,n-1)<<endl;

	return 0;
}
