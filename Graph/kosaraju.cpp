#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " ";
    vis[node] = 1;
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose);
        }
    }
}

void print(vector<int> v){
    vector<int>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<*itr;
    }
}

int main() {
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

	stack<int> st;
	vector<int> vis(v+1, 0);
	for(int i = 0;i<v;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj);
	    }
	}

	vector<int> transpose[v+1];

	for(int i = 0;i<v;i++) {
	    vis[i] = 0;
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i);
	    }
	}



	while(!st.empty()) {
	    int node = st.top();
	    st.pop();
	    if(!vis[node]) {
	        cout << "SCC: ";
	        revDfs(node, vis, transpose);
	        cout << endl;
	    }
	}


	return 0;
}
