#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll totalcount = 0;
bool isItsafe(ll i,ll j,ll n,vector<vector<bool>>&visited){
    return i<n && j<n && visited[i][j] == false;
}
void counthelper(ll i,ll j,ll n,vector<vector<ll>>&maze,vector<vector<bool>>&visited){
    if(i==n-1 && j==n-1){
        totalcount+=1;
        return;
    }
    if(!isItsafe(i,j,n,visited)){
        return;
    }
    visited[i][j]=true;
    if(i+1<n && maze[i][j]==0){
        counthelper(i+1,j,n,maze,visited);
    }
    if(i-1>=0 && maze[i][j]==0){
        counthelper(i-1,j,n,maze,visited);
    }
    if(j+1<n && maze[i][j]==0){
        counthelper(i,j+1,n,maze,visited);
    }
    if(j-1>=0 && maze[i][j]==0){
        counthelper(i,j-1,n,maze,visited);
    }
    visited[i][j]=false;
    return;
}
ll totalpath(vector<vector<ll>>&maze){
    ll n = maze.size();
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    counthelper(0,0,n,maze,visited);
    return totalcount;
}
int main(){
   ll n;
   cin>>n;
   vector<vector<ll>>maze(n,vector<ll>(n,0));
   for(ll i=0;i<n;i++){
       for(ll j=0;j<n;j++){
           cin>>maze[i][j];
       }
   }
   cout<<totalpath(maze)<<endl;
}