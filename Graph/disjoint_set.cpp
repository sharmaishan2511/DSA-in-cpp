#include <bits/stdc++.h>
using namespace std;

void makeset(int n,vector<int> &ranks,vector<int> &parent){
    for(int i = 1;i<=n;i++){
        ranks[i]=0;
        parent[i]=i;
    }
}

int findparent(int node,vector<int> &parent){
    if(node==parent[node]){
        return node;
    }

    return parent[node] = findparent(parent[node],parent);
}

void unioner(int u,int v,vector<int> &ranks,vector<int> &parent){
    u= findparent(u,parent);
    v= findparent(v,parent);

    if(ranks[u]<ranks[v]){
        parent[u] = v;
    }else if(ranks[v]<ranks[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        ranks[u]++;
    }
}
int main(){
    int n = 7;
    vector<int> ranks(n+1);
    vector<int> parent(n+1);
    makeset(n,ranks,parent);

    unioner(1,2,ranks,parent);
    unioner(2,3,ranks,parent);
    unioner(4,5,ranks,parent);
    unioner(6,7,ranks,parent);
    unioner(5,6,ranks,parent);
    unioner(3,7,ranks,parent);

    cout<<parent[7];
	return 0;
}
