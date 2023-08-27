#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void buildTree(vector<ll>&v,vector<ll>&segTree,ll ts,ll te,ll root){
    if(ts == te){
        segTree[root] = v[ts];
        return;
    }
    ll mid = (ts+te)/2;
    buildTree(v,segTree,ts,mid,2*root+1);
    buildTree(v,segTree,mid+1,te,2*root+2);
    segTree[root] = segTree[2*root+1] + segTree[2*root+2];
}

ll rangeSum(vector<ll>&segTree,ll root,ll ts,ll te,ll qs,ll qe){
    if(qs>te || qe < ts){
        return 0;
    }
    if(qs<=ts && qe>=te){
        return segTree[root];
    }
    ll mid = (ts+te)/2;
    return rangeSum(segTree,2*root+1,ts,mid,qs,qe) + rangeSum(segTree,2*root+2,mid+1,te,qs,qe);
}

void update(vector<ll>&v,vector<ll>&segTree,ll ts,ll te,ll root,ll idx,ll value){
    if(ts == te){
        v[idx] = value;
        segTree[root] = value;
        return;
    }
    ll mid = (ts+te)/2;
    if(idx<=mid){
        update(v,segTree,ts,mid,2*root+1,idx,value);
    }else{
        update(v,segTree,mid+1,te,2*root+2,idx,value);
    }
    segTree[root] = segTree[2*root+1] + segTree[2*root+2];
}

int main(){
    ll n,q;
    cin >> n >> q;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<ll>segTree(4*n,0);
    buildTree(v,segTree,0,n-1,0);
    while(q--){
        ll t,a,b;
        cin >> t >> a >> b;
        if(t==1){
            update(v,segTree,0,n-1,0,a-1,b);
        }else{
            cout << rangeSum(segTree,0,0,n-1,a-1,b-1) << endl;
        }
    }
}