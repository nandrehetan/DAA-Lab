#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout<<"Enter number of people: ";
    cin>>n;
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    int cnt=n;
    int kill=0;
    int rounds=0;
    while(cnt!=1){
        rounds++;
        cout<<"Iteration "<<rounds<<":"<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]!=-1){
                if(kill==0){
                    kill++;
                }
                else{
                    cout<<"Person Killed: "<<arr[i]<<endl;
                    arr[i]=-1;
                    kill=0;
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=-1){
                c++;
            }
        }
        cnt=c;
    }
    cout<<"Total Rounds: "<<rounds<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
            cout<<"The Last person alive is: "<<arr[i]<<endl;
            break;
        }
    }
    return 0;
}