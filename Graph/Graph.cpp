#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
   public:
     unordered_map<T, list<T>> adj;
     void addEdge(T u,T v,bool bidir=true){
        adj[u].push_back(v);
         if(bidir){
             adj[v].push_back(u);
         }
     }
     void print(){
         for(auto i:adj){
             cout<<i.first<<"-> ";
             for(auto j:i.second){
                 cout<<j<<" ";
             }
             cout<<endl;
         }
     }
     void bfs(T src){
         std::vector<bool>visited(3,false);
         std::queue<T>q;
         q.push(src);
         visited[src]=true;
         while(!q.empty()){
             T node= q.front();
             q.pop();
             cout<<node<<" ";
             for(auto x:adj[node]){
                if(!visited[x]){
                q.push(x);
                visited[x]=true;
                }
             }
         }
     }
};

int main(){
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
   // g.print();
   g.bfs(1);
}