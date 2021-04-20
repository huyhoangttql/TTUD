#include<bits/stdc++.h>
using namespace std;
#define MAX 200001
int n,b;
int a[MAX];
int maxtrai[MAX],maxphai[MAX];
int ans[MAX];
int best=-1;
int main(){
    cin>>n>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    maxtrai[1]=-1;
    maxphai[n]=-1;
    for(int i=2;i<=n-1;i++){
        maxtrai[i]=max(maxtrai[i-1],a[i-1]);
    }
    for(int i=n-1;i>=2;i--){
        maxphai[i]=max(maxphai[i+1],a[i+1]);
    }
    for(int i=1;i<=n;i++){
        if((maxtrai[i]-a[i]>=b)&&(maxphai[i]-a[i]>=b)){
        ans[i]= maxtrai[i] + maxphai[i]-2*a[i];
        best = best > ans[i] ? best : ans[i];
    }}
    cout<<best;
}