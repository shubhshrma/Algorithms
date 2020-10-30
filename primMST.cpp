//Prim's algo for adjacency matrix representation

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int spanningTree(int V, int E, vector<vector<int>> &graph) {
 int src=0;
 priority_queue<pii, vector<pii>, greater<pii>> pq;
 pq.push({0, src});
 vector<int> parent(V, INT_MAX);
 vector<int> dist(V, INT_MAX);
 unordered_set<int> vis;
 vis.insert(src);
 while(!pq.empty()){
     int u = pq.top().second;
     pq.pop();
     for(int v=0; v<V; v++){
        if(graph[u][v]!=INT_MAX){
            if(dist[v] > graph[u][v] && vis.count(v)==0){
                dist[v] = graph[u][v];
                parent[v] = u;
                if(!vis.count(v)) pq.push({dist[v], v}); 
            }
        }
     }
     vis.insert(u);
 }
 int ans=0;
 for(int x=1; x<V; x++){
     //cout<<x<<" "<<parent[x]<<"\n";
     ans += graph[x][parent[x]];
 }
 return ans;
}
