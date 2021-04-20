#include <iostream>
#define MAX 10005
using namespace std;
int n, K, Q;
int d[MAX];
int load[MAX] = {0};
int x[MAX];
int y[MAX];
int appear[MAX] = {0};
int segement;
int ans = 0;

void input(){
	cin >> n >> K >> Q;
	for(int i=1; i<=n; i++){
		cin >> d[i];
	}
}

void solution(){
	ans ++;
	// for(int i=1; i<=K; i++){
	// 	cout << "Route " << i << ":" << "0 ";
	// 	for(int j = y[i]; j!=0 ; j = x[j]){
	// 		cout << j << " ";
	// 	}
	// 	cout << 0 << endl;
	// }
	// for(int i=0; i<=n; i++){
	// 	cout << load[i] << " ";
	// }
	// cout << endl;
}

bool checkx(int v, int k){
	if(v>0) {
		if(appear[v]) return false;
		if(load[k] + d[v] > Q) return false;
	}
	return true;
}

void tryx(int s, int k){
	//thu gia tri X[s] cho lo trinh cua xe k
	for(int v=0; v<=n; v++){
		if(checkx(v, k)){
			x[s] = v;//diem tiep theo cua kiem s la diem v
			segement++;
			appear[v] = true;
			load[k]+= d[v];
			if(v==0){
				//xe quay ve diem dau
				if(k==K){
					if(segement == (n+k)) solution();
				}
				else tryx(y[k+1], k+1);//duyet tiep cho doan k+1, bat dau tu Y[k+1]
			}
			else tryx(v, k);
			segement--;
			load[k]-= d[v]; // recover
			appear[v] = false;
		}
	}
}

bool checky(int v, int k){
	if(appear[v] ) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void tryy(int k){
	for(int v = y[k-1] + 1; v<= n; v++){
		if(checky(v, k)){
			y[k] = v;

			segement++;
			load[k] += d[v];
			appear[v] = 1;
			if(k==K){
				tryx(y[1], 1);
			}
			else tryy(k+1);
			segement--;
			load[k] -= d[v];
			appear[v] = 0;
		}
	}
}

int main(){
	input();
	segement = 0;
	y[0] = 0;
	tryy(1);
	cout << ans;
}
