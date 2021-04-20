#include <bits/stdc++.h>
using namespace std;
int n, K;
int a[3005], c[3005];
int dp[3005][3005];
int main()
{
    //memset(dp, INT_MIN, sizeof(dp));
    for(int i = 0; i < 3005; i++) {
        for(int j = 0 ; j < 3005; j++)
            dp[i][j] = INT_MIN;

    }
    int d = 0, ans = -1;
    cin >> n >> K;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d = max(d, a[i]);
    }
    for(int i = 0; i <= n; i++)
        dp[i][0] = INT_MIN;
    for(int k = 1; k <= K+1; k++)
        dp[1][k] = c[1];
    for(int i = 2; i <= n; i++) {
        for(int k = 1; k <= K+1; k++) {
            for(int j = i-1; j >= max(0, i-d); j--) {
                if(a[j]+j >= i) {
                    dp[i][k] = max(dp[i][k], dp[j][k-1]+c[i]);
                }
            }
        }

    }
    for(int k = 1; k <= K+1; k++) {
        ans = max(ans, dp[n][k]);
    }
    if(ans <= 0)
        cout << "-1";
    else cout << ans;
    return 0;
}
