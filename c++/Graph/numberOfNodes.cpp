#include<bits/stdc++.h>
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