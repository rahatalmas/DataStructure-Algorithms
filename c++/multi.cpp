/*#include<bits/stdc++.h>
using namespace std;

int recurMultiply(int a,int b){
    if(b==0){
        return 0;
    }
    if(b==1){
        return a;
    }
    return a += recurMultiply(a,b-1);
}

int main(){
    int a,b;
    cin >> a >> b;
    if(b==0){
        cout << 0 << endl;
    }else{
        cout << recurMultiply(a,b) << endl;
    }
}*/

#include<bits/stdc++.h>
using namespace std;

int mul(int a, int b)
{
	if(b == 0) return 0;
	else{
		return a + mul(a, b-1);
	}
}

int main()
{
	int a, b;
	cin>>a>>b;
	cout<<mul(a, b);
	return 0;
}