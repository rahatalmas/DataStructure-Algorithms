#include<bits/stdc++.h>
#define ll long long int 
#define in std::cin
#define out std::cout
#define str std::string 
#define vi std::vector 
#define pb push_back
#define loop(i,a,b) for(ll i=(a);i<(b);i++)
#define nl std::endl
#define li std::list
#define qu std::queue
class Graph{
    public:
      ll V;
      li<ll> *adj;
      Graph(ll V){
          this->V=V;
          adj = new li<ll>[V];
      }
      void add_edge(ll u,ll v){
          adj[u].pb(v);
      }
      void topologicalSort(){
         vi<ll>indegree(V,0);
         qu<ll>q;
         vi<ll>sortedGraph;
         ll visitcount =0 ;
         loop(i,0,V){
             for(auto neighbour:adj[i]){
                 indegree[neighbour]++;
             }
         }
         loop(i,0,V){
             if(indegree[i]==0){
                 q.push(i);
             }
         }
         while(!q.empty()){
             ll node = q.front();
             q.pop();
             sortedGraph.pb(node);
                 for(auto neighbour:adj[node]){
                     if(--indegree[neighbour]==0){
                         q.push(neighbour);
                     }
                 }
             visitcount++;
         }
         if(visitcount != V){
             out<<"topological sort not possible"<<nl;
         }
         else{
             for(auto x:sortedGraph){
                 out<<x<<" ";
             }
             out<<nl;
         }
      }
};

int main()
{
    Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    out << "Following is a Topological Sort of\n";
    g.topologicalSort();
 
    return 0;
}