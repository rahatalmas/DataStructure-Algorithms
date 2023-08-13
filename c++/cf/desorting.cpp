#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll>v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int fidx,sidx=0;
        int mindiff = INT_MAX;
        bool flag = true;
        for(int i=1;i<n;i++){
            if(v[i]<v[i-1]){
                flag = false;
                break;
            }
            if(v[i]-v[i-1] < mindiff){
                mindiff = v[i]-v[i-1];
                fidx = i;
                sidx = i-1;
            }        
        }
        if(flag){
            int mid = (v[fidx]-v[sidx])/2;
            cout << mid+1 << endl;
        }else{
            cout << 0 << endl;
        }
    }    
}