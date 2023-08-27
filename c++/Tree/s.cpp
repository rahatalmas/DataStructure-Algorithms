#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
void buildTree(std::vector<ll>&v,std::vector<ll>&segTree,ll s,ll e,ll tidx){
   if(s==e){
       segTree[tidx] = v[s];
       return;
   }
   ll mid = (s+e)/2;
   buildTree(v,segTree,s,mid,2*tidx);
   buildTree(v,segTree,mid+1,e,2*tidx+1);
   segTree[tidx] = segTree[2*tidx]+segTree[2*tidx+1];
}

void update(std::vector<ll>&v,std::vector<ll>&segTree,ll s,ll e,ll tidx,ll idx,ll value){
   if(s==e){
       v[idx]=value;
       segTree[tidx]=value;
       return;
   }
   ll mid = (s+e)/2;
   if(idx>mid){
       update(v,segTree,mid+1,e,2*tidx+1,idx,value);
   }else{
       update(v,segTree,s,mid,2*tidx,idx,value);
   }
   segTree[tidx]=segTree[2*tidx]+segTree[2*tidx+1];
}

ll querry(std::vector<ll>&segTree,ll s,ll e,ll tidx,ll l,ll r){
   if(s>r || e<l){
       return 0;
   }
   if(s>=l && e<=r){
       return segTree[tidx];
   }
   ll mid = (s+e)/2;
   ll a1=querry(segTree,s,mid,2*tidx,l,r);
   ll a2=querry(segTree,mid+1,e,2*tidx+1,r,l);
   return a1+a2;
}

int main(){
   ll n;
   std::cin>>n;
   std::vector<ll>v(n);
   for(ll i=0;i<n;i++){
       std::cin>>v[i];
   }
   std::vector<ll>segTree(4*n);
   buildTree(v,segTree,0,n-1,0);
   for(auto x:segTree){
    cout << x << endl;
   }
   ll q;
   std::cin>>q;
   while(q--){
       int type;
       std::cin>>type;
       if(type == 1){
         ll l,r;
         std::cin>>l>>r;
         std::cout<<querry(segTree,0,n-1,1,l,r);
       }else{
         ll i,val;
         std::cin>>i>>val;
         update(v,segTree,0,n-1,1,i,val);
       }
   }
}