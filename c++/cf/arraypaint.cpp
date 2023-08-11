#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
   ll n;
   cin >> n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin >> v[i];
   }
   int coin = 0;
   for(int i=0,j=1;i<n;i++){
    if(v[i] == 1 || v[j] == 1){
        coin ++;
        i = j+1;
        j+=2
        ;
    }
    if(v[i] == 2 ){

    }
   }
}