#include <bits/stdc++.h>
using namespace std;

int cnt=0;

bool check(int i,int j,int i1,int j1){
    return ((i==i1) || (j==j1) || (abs(i-i1)==abs(j-j1)));
}
void recur(int i,int n,vector<int>a){
    if (i==n){
        char v[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (j==a[i]){
                    v[j][i]='*';
                }
                else{
                    v[j][i]='-';
                }
                
            }
        }
        cnt++;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n\n\n\n";
        return;
    }
    for (int id=0;id<n;id++){
        bool found=true;
        for (int j=0;j<i;j++){
            if (check(j,a[j],i,id)){
                found=false;
                break;
                
            }
        }
        if (found){
            a.push_back(id);
            recur(i+1,n,a);
            a.pop_back();
        }
        
    }
    
    
}

int main() {
    int n;
    cin>>n;
    vector<int>a;
    recur(0,n,a);
    cout << "found " << cnt << endl;

    return 0;
}