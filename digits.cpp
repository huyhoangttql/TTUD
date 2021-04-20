#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
int N;
int Q=0;
int X[MAX];
bool visited[MAX]={0};

bool check(int v, int k){
	//thu gia tri X[k]=v
    return !visited[v];

}
void solution(){
	if(X[1]*100+10*X[2]+X[3]-100*X[7]-62+X[4]*1000+100*X[5]+10*X[6]+X[3]==N){
		Q++;
	}
}
void TRY(int k){
	for (int v=1; v<=9;v++){
		if(check(v,k)){
			X[k]=v;
			visited[v]=1;
			if(k==7){
				solution();
			}
			else TRY(k+1);
			visited[v]=0;

		}
	}
}

int main(){
	cin>>N;
	TRY(1);
	cout<<Q;
}