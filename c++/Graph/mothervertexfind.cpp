#include<bits/stdc++.h>
using namespace std;

class Graph{
  public:
    int V;
    list<int> *adj;
    Graph(int V){
      this->V=V;
      adj = new list<int>[V];
    }
    void add_edge(int u,int v);
    void DfsUtil(int src,vector<bool>&visited);
    int FindMother();
};

void Graph :: add_edge(int u,int v){
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

void Graph :: DfsUtil(int src,vector<bool>&visited){
    visited[src]=true;
    for(auto neighbour:adj[src]){
      if(!visited[neighbour]){
        DfsUtil(neighbour,visited);
      }
    }
}

int Graph :: FindMother(){
    vector<bool>visited(V,false);
    int n = 0;
    for(int i=0;i<V;i++){
      if(!visited[i]){
        DfsUtil(i,visited);
        n=i;
      }
    }
    fill(visited.begin(),visited.end(),false);
    DfsUtil(n,visited);
    for(auto x:visited){
      if(x!=true){
        return n;
        break;
      }
    }
    return n;
}

int main(){
  int size;
  cout<<"enter number of vertices : ";
  cin>>size;
  Graph g(size);
  int u,v;
  for(int i=0;i<=size;i++){
     cin>>u>>v;
     g.add_edge(u,v);
  }
  int motherVertex = g.FindMother();     
  if(motherVertex == -1){
    cout<<"no mother vertex found"<<endl;
  }
  else{
    cout<<"mother Vertex is: "<<motherVertex<<endl;
  }
}