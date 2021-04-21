#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
	cin >> n;
	int a[n];
	int doi =0, thunglung = 0;
	for ( int i =1; i<=n;i++) {
		cin >> a[i];
	}
		
	int d1[n], d2[n], t1[n], t2[n];//d1 la doi xet tu chieu di, d2 la doi xet tu chieu ve, t1 la thung lung xet tu chieu di, t2 la thung lung xet tu chieu ve
	d1[1] = 0; t1[1] = 0;
	d2[n] = 0; t2[n] = 0;
	
	for ( int i =2; i <= n ;i++) {
		if ( a[i]<a[i-1]) 
			t1[i] = 1 + t1[i-1];
		else t1[i] = 0;
		
		if( a[i] > a[i-1]) 
			d1[i] = 1  + d1[i-1];
		else d1[i] = 0;
	}
	
	for ( int i = n-1 ; i>=1;i--) {
		if( a[i] > a[i+1])
			d2[i] = 1 + d2[i+1]; 
		else d2[i] = 0;
		
		if(a[i] < a[i+1])
			t2[i] = 1 + t2[i+1];
		else t2[i] = 0;
		
			
	}
	 
	for ( int i =1; i <= n; i ++ ){
		thunglung = max ( thunglung, min (t1[i], t2[i]));
	 	doi = max( doi, min( d1[i], d2[i])); 
	}
	cout << doi << " "<< thunglung;
}