#include <bits/stdc++.h>
using namespace std;

int ninja_training(vector<vector<int>> &task,int day,int last){
    if(day==0){
        int maxi=0;
        for(int i = 0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,task[0][i]);
            }
        }
        return maxi;
    }

    int maxi=0;
    for(int i = 0;i<3;i++){
        if(i!=last){
            int point = task[day][i] + ninja_training(task,day-1,i);
            maxi = max(maxi,point);
        }
    }

    return maxi;
}

int ninja_training2(vector<vector<int>> &task,int day,int last,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i = 0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,task[0][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi=0;
    for(int i = 0;i<3;i++){
        if(i!=last){
            int point = task[day][i] + ninja_training2(task,day-1,i,dp);
            maxi = max(maxi,point);
        }
    }

    dp[day][last] = maxi;
    return maxi;
}


int ninja_training3(vector<vector<int>> &task,int day,int last,vector<vector<int>> &dp){
    dp[0][0] = max(task[0][1],task[0][2]);
    dp[0][1] = max(task[0][0],task[0][2]);
    dp[0][2] = max(task[0][1],task[0][0]);

    int a = max(task[0][1],task[0][2]);
    dp[0][3] = max(task[0][0],a);

    int maxi = 0;

    for(int i = 1;i<day+1;i++){
        for(int j = 0;j<4;j++){
            dp[day][last] = 0;
            for(int k = 0;k<3;k++){
                if(k!=last){
                    int point = task[day][i] + dp[day-1][i];
                    dp[day][last] = max(dp[day][last],point);
                }
            }

        }
    }

    return dp[day][last];
}

int main(){

    vector<vector<int>> v = {{10,50,1},
                             {5,100,11}};
    int n = v.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout<<ninja_training3(v,n-1,3,dp);
	return 0;
}
