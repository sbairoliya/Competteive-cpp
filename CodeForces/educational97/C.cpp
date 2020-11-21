/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/27/2020 at 8:34 PM(UTC +5.5)
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
#define read(arr, n) for(int i = 0; i < n; i++) cin>>arr[i]
#define read1(arr, n) for(int i = 1;i <= n; i++) cin>>arr[i]

/************************************* SOLUTION BELOW ***************************************/

void solve() {
    ll n;
    cin >> n;
    vector<ll> tim(n);
    for (ll i = 0; i < n; i++) {
        cin >> tim[i];
    }
    sort(tim.begin(), tim.end());
    vector<vl > dp(n + 1, vl(2 * n, MOD));
    dp[0][0] = 0;
    for (ll i = 0; i < n + 1; ++i) {
        for (ll j = 0; j < 2 * n - 1; ++j) {
            if (dp[i][j] < MOD) {
                if (i != n) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(tim[i] - j));
                }
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    cout << dp[n][2 * n - 1] << endl;
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
