#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll i = 1;
        ll j = 0;
        while(j<=n){
            j+=i;
            i++;
        }
        cout << i-1 << " " << j << endl;
    }
}