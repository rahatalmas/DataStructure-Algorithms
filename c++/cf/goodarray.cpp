#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
  ll t;
  cin >> t;
  while(t--){
    bool flag = true;
    ll n;
    cin >> n;
    vector<ll>v(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin >> v[i];
        sum+=v[i];
    }
    //cout << sum << endl;
    ll crnt = sum;
    for(ll i=0;i<n;i++){
        if(v[i] == 1){
           crnt-=(v[i]-v[i])+2;
        }else{
           crnt-=(v[i]-v[i])+1;
           //cout << sum << i << endl;
        }
        if(crnt <= 0){
            flag = false;
            break;
        }
    }
    crnt += (sum-crnt);
    if(crnt > sum){
        flag = false;
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl; 
    }
  }
}

//1 2 2 1 1 
//2 1 1 2 1

