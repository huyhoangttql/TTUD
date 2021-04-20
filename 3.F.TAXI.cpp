#include<bits/stdc++.h>
using namespace std;
int n;
int c[1000][1000];
int chiphi = 0;
int minChiPhi =999999;
int X[1000];
bool appear[1000]={0};
int ans=9999999;

void input(){
    cin >> n;
    for(int i=1; i<=2*n+1;i++){
        for(int j=1;j<=2*n+1;j++){
            cin >> c[i][j];
            // if(i!=j){
            //     minChiPhi = min(minChiPhi,c[i][j]);
            // }
        }
    }
}
bool check(int v, int k){// xet X[k]=v xem co thoa man ko
    if(appear[v]) return 0 ;
    return 1;
}
void TRY(int k){
    for(int i=2; i<=n+1; i++){
        if(check(i,k)){
            X[k]=i;
            appear[i]=1;
            chiphi += c[X[k-1]+n][X[k]];
            chiphi += c[X[k]][X[k]+n];
            if(k==n+1){
                ans= min(ans, chiphi+ c[X[n+1]+n][1]);
            }
            else {if(ans > chiphi) TRY(k+1);}
            appear[i]=0;
            chiphi -= c[X[k-1]+n][X[k]];
            chiphi -= c[X[k]][X[k]+n];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    input();
    X[1]=1-n;
    TRY(2);
    cout<<ans;

}