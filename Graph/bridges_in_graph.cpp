#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<int> &parent,vector<int> &vis,vector<int> &disc,vector<int> &low,vector<int> adj[]){

    static int timer = 0;
    vis[node] = 1;
    disc[node] = low[node] = ++timer;

    for(auto it : adj[node]){
        if(!vis[it]){
            parent[it] = node;
            dfs(it,parent,vis,disc,low,adj);
            low[node] = min(low[it],low[node]);
            if(low[it]>disc[node]){
                cout<< node <<" "<<it<<endl;
            }
        }else if(it!=parent[node]){
            low[node] = min(low[node],disc[it]);
        }
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
    vector<int> disc(v,0);
    vector<int> low(v,0);
    vector<int> parent(v,0);

    for(int i = 0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent, vis,disc,low,adj);
        }
    }



	return 0;
}
