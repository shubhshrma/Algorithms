#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; 
# define INF 0x3f3f3f3f 
class Solution {
public:
    int find(int par[], int x){
        while(par[x]!=x){
            x=par[x];
        }
        return x;
    }
    bool merge(int par[], int x, int y){
        int xp=find(par,x);
        int yp=find(par,y);
        if(xp==yp) return false;
        par[xp]=yp;
        return true;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int i, j, n=points.size();
        vector< pair< int, pii> > edges;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                edges.push_back({(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])), {
                               i,j}});
            }
        }
        sort(edges.begin(), edges.end());
        int par[n];
        for(i=0;i<n;i++){
            par[i]=i;
        }
        int c=0,ans=0;
        for(auto e: edges){
            int u=e.second.first;
            int v=e.second.second;
            if(merge(par,u,v)){
                c++;
                ans+=e.first;
                if(c==n-1){
                    break;
                }
            }
            
        }
        return ans;
        
        
    }
};