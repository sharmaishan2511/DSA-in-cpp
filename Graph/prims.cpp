#include<bits/stdc++.h>
using namespace std;


void print(vector<pair<int,int>> v){
    vector<pair<int,int>>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<"("<<(*itr).first<<","<<(*itr).second<<")"<<" ";
    }
}

int minKey(int key[], int mstSet[],int v)
{
    int mini = INT_MAX, min_index;

    for (int i = 0; i < v; i++)
        if (mstSet[i] == 0 && key[i] < mini)
            mini = key[i], min_index = i;

    return min_index;
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
        adj[v].push_back({u,wt});
    }

    for(int i = 0;i<v;i++){
        cout<< i <<" -> ";
        print(adj[i]);
        cout<<endl;
    }

    cout<<endl;

    int key[v],vis[v],parent[v];
    for(int i = 0;i<v;i++){
        key[i]=INT_MAX;
        vis[i] = 0;
    }

    key[0] = 0;
    parent[0]= -1;

    for(int i = 0;i<v-1;i++){

        int ind = minKey(key,vis,v);
        vis[ind] = 1;

        vector<pair<int,int>>::iterator it;
        for(it = adj[ind].begin();it!=adj[ind].end();it++){
            if(!vis[(*it).first] && (*it).second < key[(*it).first]){
                key[(*it).first] = (*it).second;
                parent[(*it).first] = ind;
            }
        }

    }

    for(int i = 0;i<v;i++){
        if(parent[i]==-1){
            continue;
        }
        cout<<parent[i]<<" - "<< i<<endl;
    }


    return 0;
}
