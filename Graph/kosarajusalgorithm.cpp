#include<bits/stdc++.h>
class Graph{
  public:   
   int V;
   std::list<int>* adj;
   Graph(int V){
       this->V=V;
       adj = new std::list<int>[V];
   }
   void add_edge(int u,int v){
       adj[u].push_back(v);
   }
   void dfsHelper(int src,std::vector<bool>&visited);
   void stackPushandDfs(int src,std::vector<bool>&visited,std::stack<int>&st);
   Graph transpose(){
       Graph gT(V);
       for(int i=0;i<V;i++){
           for(auto neighbour : adj[i]){
               gT.adj[neighbour].push_back(i);
           }
       }
       return gT;
   }
   void sccg();
};

void Graph :: dfsHelper(int src,std::vector<bool>&visited){
   visited[src]=true;
   std::cout<<src<<" ";
   for(auto neighbour:adj[src]){
       if(!visited[neighbour]){
           dfsHelper(neighbour,visited);
       }
   }
}

void Graph :: stackPushandDfs(int src,std::vector<bool>&visited,std::stack<int>&st){
   visited[src]=true;
   for(auto neighbour:adj[src]){
       if(!visited[src]){
           stackPushandDfs(neighbour,visited,st);
       }
   }
   st.push(src);
}

void Graph :: sccg(){
    std::vector<bool>visited(V,false);
    std::stack<int>st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            stackPushandDfs(i,visited,st);
        }
    }
    Graph gT = transpose();
    fill(visited.begin(),visited.end(),false);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
           gT.dfsHelper(node,visited);
           std::cout<<std::endl;
        }
    }
}

int main(){
    Graph g(5);
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);
    g.sccg();
}