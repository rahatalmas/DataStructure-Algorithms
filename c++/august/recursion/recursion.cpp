#include<bits/stdc++.h>
using namespace std;

void outputV(vector<int>v,int n){
    
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v.emplace_back(i);
    }
    outputV(v,n);
}