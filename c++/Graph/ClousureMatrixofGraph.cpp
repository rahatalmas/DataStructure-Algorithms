#include<bits/stdc++.h>
using namespace std;
#define in std::cin
#define out std::cout 
#define nl std::endl
#define ll long long int
#define pb push_back
#define loop(i,a,b) for(auto i=(a);i<(b);i++)

class Graph{
  public:
    ll V;
    list<ll> *adj;
    Graph(ll V){
        this->V = V;
        adj = new list<ll>[V];
    }
    void add_edge(ll u,ll v){
        adj[u].pb(v);
    }
    void dfsHelper(ll src,ll dest,vector<vector<ll>>&tc){
        tc[src][dest]=1;
        for(auto x:adj[dest]){
            if(tc[src][x] == 0){
                tc[src][x]=1;
                dfsHelper(src,x,tc);
            }
        }
    }
    void dfs(){
        vector<vector<ll>>tc(V,vector<ll>(V,0));
        for(ll i=0;i<V;i++){
            dfsHelper(i,i,tc);
        }
        for(ll i=0;i<V;i++){
            for(ll j=0;j<V;j++){
                cout<<tc[i][j];
            }
            cout<<endl;
        }
  }
};

int main(){
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.dfs();
    return 0;
}

    
