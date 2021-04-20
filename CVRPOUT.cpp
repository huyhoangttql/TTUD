#include <iostream>
#define MAX 100
using namespace std;
int n, K, Q, d[MAX], c[MAX][MAX], x[MAX], y[MAX], segement = 0, f=0, ans = 999999999, visited[MAX] = {0}, load[MAX];

void input(){
	cin >> n >> K >> Q;
	for(int i=1; i<=n; i++){
		cin >> d[i];
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			cin >> c[i][j];
		}
	}
}

void solution(){
	ans = min(ans, f);
//	for(int i=1; i<=K; i++){
//		cout << "0 ";
//		for(int j = y[i]; j!= 0; j=x[j]){
//			cout << j << " ";
//		}
//		cout << 0 << endl;
//	}
}

bool checkX(int v, int k){
	if(v>0){
		if(visited[v]) return false;
		if(load[k] + d[v] >Q) return false;
	}
	return true;
}

void TRYX(int s, int k){
	for(int v=0; v<=n; v++){
		if(checkX(v, k)){
			x[s] = v;
			segement++;
			load[k] += d[v];
			f+=c[s][v];
			visited[v] = 1;
			if(v==0){
				if(k==K){
					
					if(segement == (n+K)) solution();
				}
				else TRYX(y[k+1], k+1);
			}
			else TRYX(v, k);
			segement--;
			f-=c[s][v];
			load[k]-=d[v];
			visited[v] = 0;
		}
	}
}

bool checkY(int v, int k){
	if(visited[v]) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void TRYY(int k){
	for(int v=y[k-1]+1; v<=n; v++){
		if(checkY(v, k)){
			y[k] = v;
			segement++;
			load[k]+=d[v];
			f+=c[0][v];
			visited[v] = 1;
			if(k==K) TRYX(y[1], 1);
			else TRYY(k+1);
			segement--;
			load[k] -= d[v];
			f-=c[0][v];
			visited[v] = 0;
		}
	}
}

int main(){
	input();
	y[0] = 0;
	TRYY(1);
	cout << ans;
}