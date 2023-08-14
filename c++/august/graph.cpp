#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>g;

void add_edge(int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(vector<bool>&visited,int v){
   visited[v] = true;
   cout << v <<"->";
   for(auto x:g[v]){
        if(!visited[x]){
           dfs(visited,x);
        }
   }
}

void bfs(vector<bool>&visited,int v){
   queue<int>q;
   visited[v] = true;
   q.push(v);
   while(!q.empty()){
      int crnt = q.front();
      cout << crnt << "->";
      q.pop();
      for(auto x:g[crnt]){
          if(!visited[x]){
            visited[x] = true;
            q.push(x);
          }
      }
   }
}

void traverse(){
    vector<bool>visited(n,false);
    int o;
    cout << "Choose a traverse method: \n";
    cout << " 1: dfs: \n";
    cout << " 2: bfs: \n";
    cin >> o;
    if(o==1){
        dfs(visited,0);
    }else if(o==2){
        bfs(visited,0);
    }
}
int main(){
   int t;
   cin >> t;
   while(t--){
        cin >> n;
        g.resize(n);
        int a,b;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            add_edge(a,b);
        }
        traverse();
   }
}