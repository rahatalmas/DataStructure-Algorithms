#include<bits/stdc++.h>
void rearrangeevenodd(std::vector<int>&v,std::vector<int>&temp){
    int size = v.size();
    int evenp=size/2;
    int oddp=size-evenp;
    int j=oddp-1;
    for(int i=0;i<size;i+=2){
       v[i]=temp[j];
       j--;
    }
    j=oddp;
    for(int i=1;i<size;i+=2){
        v[i]=temp[j];
        j++;
    }
}
int main(){
    int n;
    std::cin>>n;
    std::vector<int>v(n);
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    std::vector<int>temp(v);
    rearrangeevenodd(v,temp);
    for(auto x:v){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}