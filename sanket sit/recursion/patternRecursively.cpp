#include<bits/stdc++.h>
void patternPrint(int n){
    if(n==0){
        return ;
    }
    std::cout<<"*"<<std::endl;
    patternPrint(n-1);
}

int main(){
    int n;
    std::cin>>n;
    patternPrint(n);
}