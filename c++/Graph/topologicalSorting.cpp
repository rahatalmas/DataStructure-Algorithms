#include<bits/stdc++.h>
#define pb push_back

class Graph{
   public:
     int V;
     std::list<int>*adj;
     Graph(int V){
         this->V=V;
         adj = new std::list<int>[V];
     }
     void add_edge(int u,int v);
#define vi std::vector
#define pb push_back
#define eb emplace_back

vi<vi <int>> adj(3);

void add_edge(int u,int v){
   adj[u].pb(v);
   adj[v].pb(u);
}
void numberOfNoder(){

}
void print(){
    for(auto x:adj){
        for(auto y:x){
            std::cout<<y<<" ";
        }
    }
}
int main(){
   add_edge(1,2);
   add_edge(1,3);
   print();
}

     void topologicalSort(int src, std::vector<bool>&visited,std::stack<int>&st){
       visited[src]=true;
       for(auto neighbour:adj[src]){
         if(!visited[neighbour]){
             topologicalSort(neighbour,visited,st);
         }
       }
       st.push(src);
     }
};

void Graph :: add_edge(int u,int v){
    adj[u].pb(v);
}

int main(){
    Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    std::vector<bool>visited(6,false);
    std::stack<int>st;
    for(int i=0;i<6;i++){
        if(!visited[i]){
           g.topologicalSort(i,visited,st);
        }
    }
    while(!st.empty()){
        std::cout<<st.top()<<" ";
        st.pop();
    }
}