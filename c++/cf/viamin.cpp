#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll,ll>m;
        ll en = (n*(n-1))/2;
        for(ll i=0;i<en;i++){
            ll a;
            cin >> a;
            m[a]++;
            //cout << m[a] << "count" << endl;
        }
        vector<ll>v;
        //cout << m[3] <<"m"<<endl;
        int mitr = n;
        for(auto x:m){
            //cout << x.first << " " <<x.second <<" map" <<endl;
            if(x.second == mitr){
                v.push_back(x.first);
                v.push_back(x.first);
                mitr-=2;
            }else if(x.second > mitr){
                int diff = x.second-mitr;
                for(int i=0;i<diff;i++){
                    v.push_back(x.first);
                    mitr--;
                }
            }else{
                v.push_back(x.first);
                mitr--;
            }
        }

        while(mitr--){
            v.push_back(INT_MAX);
        }
        for(auto x:v){
            cout << x << " ";

        }
        cout << endl;
    }
}