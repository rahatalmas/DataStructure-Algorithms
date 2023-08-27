#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        if(s[0] != '('){
            cout << "YES\n";
            for(int i=0;i<n;i++){
               cout << "()";
            }
            cout << "\n";
        }else{
            int fcount = 0;
            int scount = 0;
            for(int i=0;i<n;i++){
                if(s[i] == '('){
                    fcount ++;
                }else{
                    scount++;
                }
            }
            if(fcount == scount){
                cout << "NO\n";
            }else{
                    cout << "YES\n";
                    for(int i=0;i<n;i++){
                        cout << "()";
                    }
                    cout << endl;
                }
            }
        }
}