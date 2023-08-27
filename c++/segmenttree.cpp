#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>&v,int s,int e,vector<int>&segTree,int tidx){
    if(s==e){
        segTree[tidx] = v[s];
        return;
    }
    int mid = (s+e)/2;
    buildTree(v,s,mid,segTree,2*tidx+1);
    buildTree(v,mid+1,e,segTree,2*tidx+2);
    segTree[tidx] = segTree[2*tidx+1] + segTree[2*tidx+2];
}

void updateTree(vector<int>&v,vector<int>&segTree,int s,int e,int tidx,int idx, int value){
    if(s==e){
        v[idx] += value;
        segTree[tidx] += value;
        return;
    }
    int mid = (s+e)/2;
    if(mid>idx){
       updateTree(v,segTree,s,mid,2*tidx+1,idx,value);
    }else{
      updateTree(v,segTree,mid+1,e,2*tidx+2,idx,value);
    }
    segTree[tidx] = segTree[2*tidx+1] + segTree[2*tidx+2];
}

int rangeSum(vector<int>&segTree,int tl,int tr,int tridx,int ql,int qr){
    if(tl > qr || tr < ql){ // tr < ql || tl > ql
      return 0;
    }
    if(tl>=ql && tr<=qr){
      return segTree[tridx];
    }
    int mid = (tl+tr)/2;
    return rangeSum(segTree,tl,mid,2*tridx+1,ql,qr) + rangeSum(segTree,mid+1,tr,2*tridx+2,ql,qr);
}

int main(){
   int n;
   cin >> n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
     cin >> v[i];
   }
   vector<int>segTree(4*n);
   buildTree(v,0,n-1,segTree,0);
   for(auto x:v){
      cout << x << " ";
   }
   cout << endl;
   for(auto x:segTree){
      cout << x << " " ;
   }
   cout << endl;
   //updateTree(v,segTree,0,n-1,0,3,10);
   for(auto x:v){
      cout << x << " ";
   }
   cout << endl;
   cout << rangeSum(segTree,0,n-1,0,4,5) << endl;
}
