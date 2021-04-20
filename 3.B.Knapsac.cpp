#include<bits/stdc++.h>
using namespace std;
int n,b,a[100], c[100], best = 0,ans= 0, X[100],weight=0;

bool check(int k,int i){
    if((weight + a[k])>b && i==1) return 0;
    return 1;
}
void solution(){
    best=0;
    for(int i=1; i<=n;i++){
        best += X[i]*c[i];
    }
    ans = max(ans,best);
}
void tryX(int k){
    for(int i=0; i<=1; i++){
    if(check(k,i)){
        X[k]=i;
        weight += a[k]*X[k];
        if(k==n){
            solution();
        }
        else tryX(k+1);
        weight -= a[k]*X[k];

    }
}}


int main(){
    cin >> n >>b;
    for(int i=1;i<=n;i++){
        cin >>a[i] >> c[i];
    }
    tryX(1);
    cout<<ans;

}
