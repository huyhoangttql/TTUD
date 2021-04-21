#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
int n;
long long x[MAX], y[MAX];

int main() {
    int t;
    cin >> t;
    int z = t;
    while(t--) {
        long long ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> y[i];
        }
        sort(x+1, x+n+1);
        sort(y+1, y+n+1);
        for (int i = 1; i <= n; i++) {
            ans += x[i]*y[n+1-i];
        }
        cout << "Case #" << z-t << ": " << ans << endl;
    }
    return 0;
}