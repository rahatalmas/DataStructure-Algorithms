#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum+=v[i];
        }
        if(sum%2==0){
            cout << "YES" <<endl;
        }else{
            cout << "NO" << endl;
        }
    }
}