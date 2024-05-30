#include <bits/stdc++.h>
using namespace std;

int cnt=1;
void recur(vector<vector<int>>&a,int i,int j,int i2,int j2){
    if (i2-i==1 && j2-j==1){
        for (int x=i;x<=i2;x++){
            for (int y=j;y<=j2;y++){
                if (a[x][y]==0){
                a[x][y]=cnt;
            }

            }

        }
        cnt++;
        return;


    }
    else{
        vector<int>dx={0,0,1,1};
        vector<int>dy={0,1,0,1};
        int ch=-1;
        int x_md=(i+i2)/2;
        int y_md=(j+j2)/2;
        for (int x=i;x<=x_md;x++){
            for (int y=j;y<=y_md;y++){
                if (a[x][y]!=0){
                    ch=0;
                }
            }
        }

        for (int x=x_md+1;x<=i2;x++){
            for (int y=y_md+1;y<=j2;y++){
                if (a[x][y]!=0){
                    ch=3;
                }
            }
        }

        for (int x=i;x<=x_md;x++){
            for (int y=y_md+1;y<=j2;y++){
                if (a[x][y]!=0){
                    ch=1;
                }
            }
        }

        for (int x=x_md+1;x<=i2;x++){
            for (int y=j;y<y_md;y++){
                if (a[x][y]!=0){
                    ch=2;
                }
            }
        }

        for (int d=0;d<4;d++){
            if (ch==d){

            }
            else{
                a[x_md+dx[d]][y_md+dy[d]]=cnt;
            }
        }
        cnt++;
        for (int d=0;d<4;d++){
            int new_i=i;
            int new_j=j;
            int new_i2=i2;
            int new_j2=j2;
            if (d==0){
                new_i2=x_md;
                new_j2=y_md;
            }
            if (d==1){
                new_j=y_md+1;
                new_i2=x_md;
            }
            if (d==2){
                new_j2=y_md;
                new_i=x_md+1;

            }
            if (d==3){
                new_i=x_md+1;
                new_j=y_md+1;
            }
            recur(a,new_i,new_j,new_i2,new_j2);

        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n+1,vector<int>(n+1,0));
    int x,y;
    cin>>x>>y;
    a[x][y]=-1;
    recur(a,1,1,n,n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
 
return 0;
}