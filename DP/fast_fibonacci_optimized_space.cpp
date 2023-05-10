#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,prev1,prev2,curri;
    cin>>n;

    prev1 = 1;prev2 = 0;

    for(long long int i = 2;i<=n;i++){
        curri = prev1 +prev2;
        prev2 = prev1;
        prev1 = curri;
    }

    cout<<prev1;
	return 0;
}
