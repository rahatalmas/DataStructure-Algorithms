#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long long 
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define v vector
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ump unordered_map

void naiveSolution(ll arr[],ll n){
    loop(i,0,n){
            for(ll j=0;j<n;j++){
                if(arr[j]==i){
                swap(arr[i],arr[j]);
                break;
                }
            }
        }
        loop(i,0,n){
            if(arr[i]!=i){
                arr[i]=-1;
            }
        }
}

void hashSetApproach(ll arr[],ll n){
    ump<ll,ll>table;
    loop(i,0,n){
        table[i]++;
    }
    loop(i,0,n){
        if(table.count(i)>=1){
            arr[i]=i;
        }else{
            arr[i]=-1;
        }
    }
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    loop(i,0,n){
        cin>>arr[i];
    }
    //naiveSolution(arr,n);
    hashSetApproach(arr,n);
    loop(i,0,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}