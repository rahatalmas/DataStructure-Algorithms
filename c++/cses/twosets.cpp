#include<bits/stdc++.h>
using namespace std;

bool df(int half,vector<int>v,int n,unordered_map<int,bool>ump){
    if(half == 0 || n == 0){
        ump[n] = true;
        return true;
    }
    if(ump[n]){
        return true;
    }
    return (df(half-v[n-1],v,(n-1),ump) || df(half-v[n-1],v,(n-1),ump));
}

int main(){
    int n;
    cin >> n;
    vector<int>v;
    unordered_map<int,bool> ump;
    int sum = 0;
    for(int i=1;i<=n;i++){
        v.push_back(i);
        sum+=i;
    }
    if(sum%2 != 0){
        cout << "NO\n";
    }else{
        int half = sum/2;
        bool flag =df(half,v,n,ump);
    }
}