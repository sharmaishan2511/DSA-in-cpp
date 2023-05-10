#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    vector<int>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<*itr;
    }
}

class Solution {
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1;

        for (auto it: adj[node]) {
            if (!vis[it]) {
                findTopoSort(it, vis, st, adj);
            }
        }
    st.push(node);
}
    public:
        vector <int> topoSort(int N, vector <int> adj[]) {
            stack < int > st;
            vector < int > vis(N, 0);
            for (int i = 0; i < N; i++) {
                if (vis[i] == 0) {
                    findTopoSort(i, vis, st, adj);
                }
            }
            vector < int > topo;
            while (!st.empty()) {
                topo.push_back(st.top());
                st.pop();
            }
            return topo;
        }
};

int main() {

    int v,e;
    cin>>v;
    cin>>e;
    vector<int> adj[v+1];

    for(int i = 0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    for(int i = 0;i<v;i++){
        cout<< i <<" ";
        print(adj[i]);
        cout<<endl;
    }

    Solution obj;
    vector<int> res = obj.topoSort(v, adj);

    cout << "Toposort of the given graph is:" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}
