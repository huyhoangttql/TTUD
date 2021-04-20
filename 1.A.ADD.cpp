#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long a,b,c,a1,a2,b1,b2,d,e;
    cin>>a>>b;
    a2 = a%10;
    b2 = b%10;
    a1 = (a-a2)/10;
    b1 = (b-b2)/10;
    c = (a2 +b2)%10;
    d = (a2 + b2 - c)/10;
    e = a1 +b1 +d;
    if (e>0) cout <<e;
    cout<< c;
}