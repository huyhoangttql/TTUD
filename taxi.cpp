#include<bits/stdc++.h>
using namespace std;
#define MAX 2000
int N;
int X[MAX];
bool visited[MAX]={0};

bool check(int v, int k){
	return !visited[v];
}

void solution(){
	for (int i=1; i<=N; i++){
		cout << X[i] << " "<< X[i] + N<< " ";
	}
	cout << endl;
}

void TRY(int k){// thu gia tri cho X[k]
	for (int v=1; v<=N;v++){
		if(check(v,k)){
			X[k]=v;
			visited[v]=1;
			if(k==N) solution();
			else TRY(k+1);
			visited[v]=0;
		}
	}
}
int main(){
	cin>>N;
	TRY(1);
}