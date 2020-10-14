#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> pii;

void addEdge(vector<pii> adj[], int u, int v, int wt) 
{ 
    adj[u].push_back({v, wt}); 
    adj[v].push_back({u, wt}); 
} 

void shortestPath(vector<pii> adj[], int V, int src){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> dist(V, INF);
    pq.push({0, src});
    dist[src]=0;

    while(!pq.empty()){
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        for(auto nb: adj[u]){
            int weight = nb.second;
            int v = nb.first;
            if(dist[v] > dist[u]+weight){
                dist[v] = dist[u]+weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout<<"Distance of all from source: ";
    for(int i=0; i<V; i++){
        cout<<"Node "<<i<<": "<<dist[i]<<"\n";
    }
}

int main(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int V=9;
    vector<pii> adj[V];
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 
  
    shortestPath(adj, V, 0);
    return 0;
}
