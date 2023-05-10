#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,int timer,vector<int> adj[],vector<int> &articulate){

    vis[node] = 1;
    tin[node] = low[node] = ++timer;

    int child = 0;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,node,vis,tin,low,timer,adj,articulate);
            low[node] = min(low[it],low[node]);
            if(low[it]>=tin[node] && parent!=-1){
                articulate[node] = 1;
            }
            child++;
        }else{
            low[node] = min(low[node],tin[it]);
        }
    }

    if(parent == -1 && child > 1){
        articulate[node] = 1;
    }
}

void print(vector<int> v){
    vector<int>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<*itr;
    }
}

int main(){
    int v,e;
    cin>>v;
    cin>>e;
    vector<int> adj[v+1];

    for(int i = 0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0;i<v;i++){
        cout<< i <<" ";
        print(adj[i]);
        cout<<endl;
    }

    vector<int> vis(v,0);
    vector<int> tin(v,-1);
    vector<int> low(v,-1);
    vector<int> articulate(v,-1);
    int timer = 0;

    for(int i = 0;i<v;i++){
        if(!vis[i]){
            dfs(i,-1, vis,tin,low,timer,adj,articulate);
        }
    }

    for(int i = 0;i<v;i++){
        if(articulate[i] == 1){
            cout<<i<<" ";
        }
    }

	return 0;
}
