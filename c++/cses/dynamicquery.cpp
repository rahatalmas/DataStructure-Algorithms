#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void buildTree(vector<ll>&v,vector<ll>&segTree,ll s,ll e,ll root){
   if(s==e){
      segTree[root] = v[s];
      return;
   }
   ll mid = (s+e)/2;
   buildTree(v,segTree,s,mid,2*root+1);
   buildTree(v,segTree,mid+1,e,2*root+2);
   segTree[root] = segTree[2*root+1] + segTree[2*root+2];
}

void updateTree(vector<ll>&v,vector<ll>&segTree,ll uidx,ll value,ll te,ll ts=0,ll root=0){
   if(ts == te){
      v[uidx] = value;
      segTree[root] = value;
      return;
   }
   ll mid = (ts+te)/2;
   if(mid > uidx){
      updateTree(v,segTree,uidx,value,mid,ts,2*root+1);
   }else{
      updateTree(v,segTree,uidx,value,te,mid+1,2*root+2);
   }
   segTree[root] = segTree[2*root+1] + segTree[2*root+2];
}

ll rangeSum(vector<ll>&segTree,ll qs, ll qe,ll te,ll ts=0, ll root=0){
    if(ts>qe || te < qs){
          return 0;
    }
    if(qs<=ts && qe>=te){
      return segTree[root];
    }
    ll mid = (ts+te)/2;
    return rangeSum(segTree,qs,qe,mid,ts,2*root+1) + rangeSum(segTree,qs,qe,te,mid+1,2*root+2);
}

int main(){
   ll n,q;
   cin >> n >> q;
   vector<ll>v(n);
   vector<ll>segTree(4*n,0);
   for(ll i=0;i<n;i++){
      cin >> v[i];
   }
   buildTree(v,segTree,0,n-1,0);
   while(q--){
     int qkey,a,b;
     cin >> qkey >> a >> b;
     if(qkey == 1){
        updateTree(v,segTree,a-1,b,n-1);
     }else{
        cout << rangeSum(segTree,a-1,b-1,n-1) << endl;
     }
   }
}