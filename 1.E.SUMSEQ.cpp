#include<bits/stdc++.h>
using namespace std;
#define c 1000000007
int main(){
    unsigned long long n,s=0;
    cin>> n;
    unsigned long long a[n],b[n];
    for(int i = 0; i< n; i++){
        cin >> a[i];
        b[i]= a[i]%c;
        s=(s + b[i])%c;
    }
    cout<< s;
}