#include<bits/stdc++.h>
using namespace std;

int v;

void print(vector<int> v){
    vector<int>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<*itr;
    }
}

void DFS(int v,int vis[],vector<int> adj[])
{

    vis[v] = 1;
    cout << v << " ";

    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!vis[*i])
            DFS(*i,vis,adj);
}

bool check_cycle(int node,int parent,int vis[],vector<int> adj[]){
    vis[node] = 1;
    vector<int>::iterator it;
    for(it = adj[node].begin();it !=  adj[node].end(); it++){
        if(vis[*it]== 0){
            if(check_cycle(*it,node,vis,adj)){
                return true;
            }
        }else if( (*it) != parent){
            return true;
        }
    }
    return false;
}

bool is_cycle(int v,vector<int> adj[],int vis[]){
    for(int i = 0;i<v;i++){
        if(!vis[i]){
            if(check_cycle(i,-1,vis,adj))
                return true;
        }
    }
}

int main(){
    // DFS Implementation

    // first adjacency list
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

    int vis[v];
    for(int i = 0;i<v;i++){
        vis[i]=0;
    }
    DFS(4,vis,adj);
    cout<<"\n";
    int ans = (is_cycle(v,adj,vis))?99:8;
    cout<<ans;
    return 0;
}
