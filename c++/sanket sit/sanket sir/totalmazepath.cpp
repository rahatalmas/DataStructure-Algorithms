#include<bits/stdc++.h>
#define in  std::cin
#define out std::cout
#define ll long long int 
#define nl std::endl
#define str std::string

ll totalPath=0;
void mazePath(ll i,ll j, ll n, ll m,str osf){
    if(i==n-1 && j==m-1){
        totalPath+=1;
        out<<osf<<nl;
    }
    if(i>=n || j>=m){
        return;
    }
    mazePath(i,j+1,m,n,osf+"R");
    mazePath(i+1,j,m,n,osf+"D");
}
int main(int argc, const char** argv) {
    ll t;
    in>>t;
    while(t--){
        ll n,m;
        in>>n>>m;
        mazePath(0,0,n,m,"");
        out<<totalPath<<nl;
    }
    return 0;
}