#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,string>mp;
    int a,i;
    string b;
    for(i=0;i<5;i++){
        getline(cin,b);
        mp.insert({i,b});
    }
    for(auto x:mp){
        cout << x.first << " " << x.second << endl;
    }
}