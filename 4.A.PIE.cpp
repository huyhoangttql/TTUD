#include<bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897932384626433
int count(double mid, double r[], int n){
    int k=0;
    for(int i=0; i< n; i++){
        k +=(int)( r[i]*r[i]*pi/mid);
    }
    return k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,n,f;
    cin >>a;
    while(a--){
        double left =0;
        cin>>n>>f;
        double r[n+1];
        double right1=1000000000;
        for(int i=0; i<n;i++){
            cin >> r[i];
            // right1 += r[i]*r[i]*pi/f;
        }
        double mid = (right1 + left)/2;
        while(right1 -left > 1e-7 ){
            mid= (left+right1)/2;
            if(count(mid,r,n)> f ) left = mid;
            else right1= mid;

        }
        mid = (left + right1)/2;
        cout<< fixed;
        cout.precision(6);
        cout<< mid<<endl;
    }
    


}