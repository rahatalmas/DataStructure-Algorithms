#include<bits/stdc++.h>
#define ll long long int 
#define in std::cin
#define out std::cout
#define str std::string 
#define vi std::vector 
#define pb push_back
#define loop(i,a,b) for(ll i=(a);i<=(b);i++)
#define nl std::endl

void allDiecePath(ll n,ll i,str osf){
    if(i==n-1){
        out<<osf<<nl;
    }
    if(i>=n){
        return;
    }
    loop(j,1,6){
        allDiecePath(n,i+j,osf+std::to_string(j)+"->");
    }
}

int main(int argc, const char** argv) {
    ll t;
    in>>t;
    while(t--){
        ll n;
        in>>n;
        allDiecePath(n,0,"");
    }
    return 0;
}