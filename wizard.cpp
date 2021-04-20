#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
int t,n;
int A[MAX];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1) cout << 9<<endl;
		if(n==2) cout << 98<<endl;
		if(n==3) cout << 989<<endl;
		if(n>=4){
			for(int i=0;i<=9; i++){
				A[i]=i;
			}
			int c = (n-3)/10;
			int d = (n-3)%10 -1;
			cout << 989;
			for(int i=1; i<= c; i++){
				for(int j=0; j<=9; j++){
					cout<< j;
				}
			}
			for(int i=0;i<=d;i++){
				cout << i;
			}
			cout<<endl;
		}

		

	}
}