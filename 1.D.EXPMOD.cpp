#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

unsigned long long power(unsigned long long a,unsigned long long b){
    if(b==0) return 1;
    if(b%2 == 0){
        return (((power(a,b/2))%mod)*((power(a,b/2))%mod))%mod;
    }
    else 
        return ((a%mod)*(power(a,b/2))%mod*(power(a,b/2))%mod)%mod;
    
}
int main(){
    unsigned long long a,b;
    cin>> a>> b;
    cout<< power(a,b);
    return 0;

}