//3-A.TSP
#include <iostream>
#define MAX 100
using namespace std;
int a[MAX][MAX] = {0}, visited[MAX] = {0}, m, n, ans =999999999, f = 0, minz = 999999999, x[MAX], b[MAX][MAX] = {0};

void input(){
	cin  >> n >> m;
	///neu khong co duong di thi a[i][j] = inf
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			a[i][j] = 999999999;
		}
	}
	while(m--){
		int i, j, c;
		cin >> i >> j >> c;
		a[i][j] = c; //khoang cach tu thanh pho i den thanh pho j la c
		b[i][j] = 1; // co duong di tu i den j
	}
}

bool check(int v, int k){
	//neu da tham thanh pho v thi khong duyet nua 
	if(visited[v]) return false; 
	//neu khong co duong di tu x[k-1] den v thi khong duyet
	if(b[x[k-1]][v] == 0) return false;
	return true;
}


//cap nhat ket qua
void solution(){
	ans = min(ans, f+a[x[n]][1]);
//	for(int i=1; i<=n; i++){
//		cout << x[i] << " ";
//	}
//	cout << endl;
}

void TRY(int k){
	for(int v = 2; v<=n; v++){
		if(check(v, k)){
			x[k] = v;
			f+= a[x[k-1]][x[k]];
			visited[v] = 1;
			if(k==n) solution();
			else{
				//nhanh can
				
				if(f+ (n-k+1)* minz < ans) TRY(k+1);
			}
			
			//tra de quy
			f-= a[x[k-1]][x[k]];
			visited[v] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	x[1] = 1;
	for(int i=1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			// tim khoang cach min tu i den j
			minz = min(minz, a[i][j]);
		}
	}
	TRY(2);
	cout << ans;
}