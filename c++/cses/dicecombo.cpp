#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll combo(ll n,vector<ll>&v){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(v[n-1]!=-1){
        return v[n];
    }
    ll count = 0;
    for(int i=1;i<=6;i++){
        count += combo(n-i,v);
    }
    return v[n] = count%mod;
}

int main(){
    ll n;
    cin >> n;
    vector<ll>v(n+1,-1);
    cout << combo(n,v) << endl;
}
