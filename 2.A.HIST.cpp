#include<bits/stdc++.h>
using namespace std;
#define N 1000000
long long h[N];
int main(){
    while(true){
        long long n;
        long long maxS=0;
        cin>>n;
        if(n==0) break;
        for(int i=0; i<n;i++){
            cin >>h[i];
        }
        for(int i = 0; i<n; i++){
            long long MINchieucao= h[i];
            for(int j=i;j<n;j++){
                MINchieucao = MINchieucao < h[j] ? MINchieucao : h[j];
                long long dientich = MINchieucao *(j-i+1);
                maxS= maxS < dientich ? dientich : maxS;
    
            }
        }
        cout<<maxS<<endl;
    }
}