#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    vector<int>::iterator itr;

    for(itr = v.begin();itr!=v.end();itr++){
        cout<<*itr;
    }
}

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q;
	    vector<int> indegree(N, 0);
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++;
	        }
	    }

	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
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
    vector<int> res = obj.topo(v, adj);

    cout << "Toposort of the given graph is:" << endl;
    for(auto it : res){
        cout<<it<<" ";
    }

    return 0;
}
