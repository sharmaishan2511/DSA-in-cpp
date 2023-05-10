#include<bits/stdc++.h>
using namespace std;


void print(vector<pair<int,int>> v){
    vector<pair<int,int>>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<"("<<(*itr).first<<","<<(*itr).second<<")"<<" ";
    }
}

int min_node(int dis[],int v,int vis[]){
    int minimum = INT_MAX,ind;

    for(int i = 0;i<v;i++){
        if(dis[i]<=minimum && !vis[i]){
            minimum = dis[i];
            ind = i;
        }
    }
    return ind;
}

int main(){
    int v,e;
    cin>>v;
    cin>>e;
    vector<pair<int,int>> adj[v+1];

    for(int i = 0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        //adj[v].push_back({u,wt});
    }

    for(int i = 0;i<v;i++){
        cout<< i <<" -> ";
        print(adj[i]);
        cout<<endl;
    }

    cout<<endl;

    //dijkstra
    int s = 0,n;
    //initial step
    int dist[v],vis[v];
    for(int i = 0;i<v;i++){
        dist[i]=INT_MAX;
        vis[i] = 0;
    }

    dist[s] = 0;
    for(int j = 0;j<v;j++){
        for(int k = 0;k<v;k++){
            n = min_node(dist,v,vis);
            vis[n] = 1;
            vector<pair<int,int>>::iterator itr1;
            for(itr1 = adj[n].begin();itr1!=adj[n].end();itr1++){
                if(dist[n]+(*itr1).second < dist[(*itr1).first]){
                    dist[(*itr1).first] = dist[n]+(*itr1).second;
                }
            }
        }
    }
    for(int j = 0;j<v;j++){
        cout<<dist[j]<<" ";
    }
    return 0;
}
