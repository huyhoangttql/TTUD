#include <bits/stdc++.h>

#define st first
#define nd second
#define pb push_back
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e3 + 5;

ll n, m, k;
pair<int, int> a[N];

void Solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);
    ll res = 0;
    int i = n + 1, tmp = k;
    while (a[i - 1].first >= 0 && i > 0)
    {
        i--;
        if (tmp < k)
        {
            int rem = min(tmp, a[i].second);
            tmp -= rem;
            a[i].second -= rem;
            if (tmp)
                continue;
        }
        res += 2ll * a[i].first * (a[i].second / k);
        a[i].second %= k;
        if (a[i].second)
        {
            tmp = k - a[i].second;
            res += 2ll * a[i].first;
        }
        else
            tmp = k;
    }

    i = 0;
    tmp = k;
    while (a[i + 1].first < 0 && i <= n)
    {
        i++;
        if (tmp < k)
        {
            int rem = min(tmp, a[i].second);
            tmp -= rem;
            a[i].second -= rem;
            if (tmp)
                continue;
        }
        res -= 2ll * a[i].first * (a[i].second / k);
        a[i].second %= k;
        if (a[i].second)
        {
            tmp = k - a[i].second;
            res -= 2ll * a[i].first;
        }
        else
            tmp = k;
    }

    cout << res << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;}