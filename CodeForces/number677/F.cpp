/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/20/2020 at 8:53 PM(UTC +5.5)
 */

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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll array[n][m];
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> array[i][j];
        }
    }
    ll dp[70][70][70][36];
    for (ll i = 0; i < 70; ++i) {
        for (ll j = 0; j < 70; ++j) {
            for (ll l = 0; l < 70; ++l) {
                for (ll i1 = 0; i1 < 36; ++i1) {
                    dp[i][j][l][i1] = -1;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            for (ll l = 0; l < k; ++l) {
                for (ll i1 = 0; i1 < m / 2 + 1; ++i1) {

                }
            }
        }
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
