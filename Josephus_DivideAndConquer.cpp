#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if(n==1){
        return 1;
    }
    else if(n%2==0){
        return 2*f(n/2)-1;
    }
    else{
        return 2*f((n-1)/2)+1;
    }
}
int main(){
    int n;
    cout<<"Enter number of people: ";
    cin>>n;
    cout<<"The Last person alive is: "<<f(n)<<endl;
    return 0;
}