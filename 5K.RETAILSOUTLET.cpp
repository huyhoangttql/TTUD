#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Q = 1e9+7;
int n, m;
int a[105];
ll mem[105][505];
ll sum[105];
/*
ll solve(int x, int y) {
    if(mem[x][y] != -1)
        return mem[x][y];
    if(x == 0) {
        if(y%a[0] == 0) {
            mem[0][y] = 1;
            return 1;
        }
        else {
            mem[0][y] = 0;
            return 0;
        }
    }
    ll res = 0;
    y = y-a[x];
    while(y >= sum[x-1]) {
        res += solve(x-1, y)%Q;
        y = y-a[x];
    }
    mem[x][y] = res%Q;
    return res%Q;
}
*/
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) {
            sum[0] = a[0];
        }
        else
            sum[i] = sum[i-1]+a[i];
    }
    for(int j = 1; j <= m; j++)
        if(j%a[0] == 0) mem[0][j] = 1;
        else mem[0][j] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            int k = j-a[i];
            while(k >= sum[i-1]) {
                mem[i][j] += mem[i-1][k]%Q;
                k = k-a[i];
            }
        }
    }
    cout << mem[n-1][m]%Q;
    return 0;
}
