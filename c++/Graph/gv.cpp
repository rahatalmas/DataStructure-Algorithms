#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int,int>>v;
    v[0].push_back(1);
    v[1].push_back(0);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << endl;
        }
    }
}