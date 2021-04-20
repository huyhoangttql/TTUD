//Cach 1 do phuc tap thoi gian On^3
//duyet tat ca cac day con
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int *a;
//     for(int i=0; i< n ; i++){
//         cin >> a[i];
//     }
//     long max1 = a[0];
//     for(int d = 0; d<n; d++){
//         for(int j=d; j<n; j++){
//             long s = 0;
//             for(int k=d; k<=j; k++){
//                 s = s + a[k];
            
//             max1 = max(max1,s);
//         }
//     }}
//     cout << max1;
//     return 0;
// }

//Cach 2 Do phuc tap thoi gian On^2
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     for( int i = 0; i<n; i++){
//         cin >> a[i];
//     }
//     int max = a[0];
//     for(int i=0; i< n; i++){
//         long s=0;
//         for(int j=i; j<n; j++){
//             s= s + a[j];
//             max= max < s ? s : max;
//         }
//     }
//     cout<<max;
//     return 0;

// }

//Cach 3: Chia de tri do phuc tap O(nlog(n))
// #include<bits/stdc++.h>
// using namespace std;

// int main(){

// }

//Cach 4: Quy hoach dong 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >>m;
    int a[n];
    for(int i=0; i<n ; i++){
        cin >> a[i];
    }
    int s[n];
    double tbc[n];
    double tbcMax;
    double count=1;
    int max = a[0];
    tbc[0]= (double)((double)a[0]/count);
    for(int i=1; i<n; i++){
        if(s[i-1]>0) {
            s[i]=s[i-1]+a[i];
            count++;}// s la tong cua day thu i
        else s[i]=a[i];
        max = max < s[i] ? s[i] : max;
        tbcMax = (double) ((double)max/count);
    }
    cout<< tbcMax;
    
}