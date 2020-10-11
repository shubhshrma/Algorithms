#include<bits/stdc++.h>
using namespace std;
class DSU{
   int comp; // no of components
   vector<int> par; // parent
    public:
   DSU(int n){
       comp=n;
       for(int i=0; i<n;i++){
           par.push_back(i);
       }
    }
    int find(int x){ 
        while(x!=par[x]){
            par[x]=par[par[x]];
            x=par[x];
        } 
        return x;
    }
    bool merge(int x, int y){
        int xp=find(x);
        int yp=find(y);
        if(xp==yp) return false;
        par[xp]=yp;
        comp--;
        return true;
    }
    int getComp(){
        return comp;
    }
};