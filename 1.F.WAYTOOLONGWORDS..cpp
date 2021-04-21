#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    string xau[n];
    for(int i=0; i<n; i++){
        cin>> xau[i];
    }
    for(int i=0; i<n; i++){
        if(xau[i].length()>10){
            cout<<xau[i][0]<<(xau[i].length() -2)<<xau[i][xau[i].length()-1];
            cout<< endl;}
        else
            cout<< xau[i]<<endl;;
    }
    return 0;
}