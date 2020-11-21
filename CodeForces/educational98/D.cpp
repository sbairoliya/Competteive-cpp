/*
 * Developed By : Shivam Bairoliya
 * Created on   : 11/19/2020 at 8:37 PM(UTC +5.5)
 */

//#define ONLINE_JUDGE
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

#define vi vector<int>
#define vl vector<long long>
#define pll pair<long long, long long>
#define MOD 998244353
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read(arr, n) for(int i = 0; i < n; i++) cin>>arr[i];
#define read1(arr, n) for(int i = 1;i <= n; i++) cin>>arr[i];

/************************************* SOLUTION BELOW ***************************************/

ll power(ll x, ll y = MOD - 2, ll p = MOD) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modMultiply(ll x, ll y, ll p = MOD) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll modSum(ll x, ll y, ll p = MOD) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    ll temp = max((ll) 4, n);
    ll array[temp + 1];
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 2;
    ll evenSum = 2;
    ll oddSum = 3;
    for (ll i = 4; i <= n; ++i) {
        if (i % 2 == 0) {
            array[i] = oddSum;
            evenSum = modSum(evenSum, array[i]);
        } else {
            array[i] = evenSum;
            oddSum = modSum(oddSum, array[i]);
        }
    }
    ll divide = power(2, n);
    ll yInverse = power(divide);
    cout << modMultiply(array[n], yInverse) << endl;;

}

int32_t main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.in", "w", stderr);
    auto start = high_resolution_clock::now();
#endif
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken for execution: "
         << duration.count() << " ms" << endl;
#endif
}
