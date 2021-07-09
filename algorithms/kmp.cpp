#include<bits/stdc++.h>
using namespace std;

void kmp(string s,string p){
    int slength = s.length();
    int plength = p.length();
    int lps[plength];
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        string p;
        cin>>s;
        cin>>p;
        kmp(s,p);
    }
}