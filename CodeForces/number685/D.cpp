/*
 * Developed By : Shivam Bairoliya
 * Created on   : 11/21/2020 at 8:51 PM(UTC +5.5)
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
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read(arr, n) for(int i = 0; i < n; i++) cin>>arr[i];
#define read1(arr, n) for(int i = 1;i <= n; i++) cin>>arr[i];

/************************************* SOLUTION BELOW ***************************************/
ll d, k;

bool isValid(ll x, ll y) {
    return (d * d) >= ((x * x) + (y * y));
}

void solve() {
    cin >> d >> k;
    double m = floor(((double) d) / sqrt(2));
    ll x = (ll) m;
    ll f;
    if (x % k == 0) {
        f = x;
    } else {
        f = x - (x % k);
    }
    ll tempD = f * f * 2;
    if ((f * f) + ((f + k) * (f + k)) <= (d * d)) {
        cout << "Ashish" << endl;
    } else {
        cout << "Utkarsh" << endl;
    }
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
    cin >> t;
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
