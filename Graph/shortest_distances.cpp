#include<bits/stdc++.h>
using namespace std;


void print(vector<int> v){
    vector<int>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<*itr;
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
    int i = 0,node;

    queue<int> q;
    q.push(i);
    vis[i] = 1;

    while(!q.empty()){
        node = q.front();
        q.pop();

        cout<<node;

        vector<int>::iterator itr;
        for(itr = adj[node].begin();itr != adj[node].end();itr++){
            if(!vis[*itr]){
                vis[*itr]=1;
                q.push(*itr);
            }
        }
    }
    cout<<endl;
    //path lengths from given node

    int s = 0,dis[v],n;
    queue<int> qu;
    qu.push(s);

    for(int i = 0;i<v;i++){
        dis[i]=-1;
    }
    dis[s]=0;

    while(!qu.empty()){
        n = qu.front();
        qu.pop();

        //for every adjacent neighbour of n
        vector<int>::iterator it;
        for(it = adj[n].begin();it != adj[n].end();it++){
            if(dis[*it]==-1){
                dis[*it] = dis[n]+1;
                qu.push(*it);
            }
        }
    }

    for(int j = 0;j<v;j++){
        cout<<dis[j]<<" ";
    }
    return 0;
}
