#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
 
int main(){
    int n,x;
    cin >> n >> x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll dp[n+1][x+1];
    for(int i=1;i<x+1;i++){
        dp[0][i] = INT_MAX;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<x+1;j++){
            if(v[i-1]<=j){
                dp[i][j] = min((j/v[i-1]) + dp[i][j%v[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    /*for(int i=0;i<n+1;i++){
        for(int j=0;j<x+1;j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }*/
    if(dp[n][x]==INT_MAX){
        cout << -1 << endl;
    }else{
        cout << dp[n][x] << endl;
    }
    //dp[n][x]==INT_MAX?cout << -1 <<endl:cout << dp[n][x] << endl;
}