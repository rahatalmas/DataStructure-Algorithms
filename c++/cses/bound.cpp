#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 5;
    int b = 9;
    int *itr = &a;
    int *itr1 = &b;
    cout << itr1 - itr << endl;
}
