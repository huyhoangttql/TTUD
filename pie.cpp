#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265359;
int n, f;
double r[10005];
bool check(double x) {
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += int((PI*r[i]*r[i])/x);
    return (sum >= (f+1));
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> f;
        double max_size = 0;
        for(int i = 0; i < n; ++i) {
            cin >> r[i];
            max_size = max(max_size, PI*r[i]*r[i]);
        }
        double low = 0, high = max_size;
        while(high-low > 1e-6) {
            double mid = (low+high)/2;
            if(check(mid))
                low = mid;
            else
                high = mid;
        }
        printf("%.6lf\n", low);
    }
    return 0;
}
