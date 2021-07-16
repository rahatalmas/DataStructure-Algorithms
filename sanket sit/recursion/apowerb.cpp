#include<bits/stdc++.h>

int recursion(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    return a*recursion(a,b-1);
}

int optimizesolutionRecursive(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int temp = optimizesolutionRecursive(a,b/2);
    if(b%2==0){
        return temp*temp;
    }else{
        return a*temp*temp;
    }
}

int main(int argc, const char** argv) {
    int a,b;
    std::cin>>a>>b;
    std::cout<<recursion(a,b);
    std::cout<<std::endl;
    std::cout<<optimizesolutionRecursive(a,b);
    std::cout<<std::endl;
    return 0;
} 