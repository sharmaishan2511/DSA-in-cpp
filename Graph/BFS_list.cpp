#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    vector<int>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<*itr;
    }
}

int main(){
    // BFS Implementation

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

    int i = 0,node;
    int vis[v];
    for(int i = 0;i<v;i++){
        vis[i]=0;
    }


    queue<int> q;
    q.push(i);
    vis[i]=1;

            //repeating steps
    while(!q.empty()){
        node = q.front();
        q.pop();
        cout<<node;
        vector<int>::iterator itr1;
        for(itr1=adj[node].begin();itr1!=adj[node].end();itr1++){
            if(vis[*itr1] == 0){
                vis[*itr1]  = 1;
                q.push(*itr1);
            }
        }
    }


    return 0;
}
