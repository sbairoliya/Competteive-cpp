/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/12/2020 at 5:08 PM
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
bool possible(pair<pll, ll> f, pair<pll, ll> s) {
    return ((abs(f.first.first - s.first.first) +
             abs(f.first.second - s.first.second) + f.second) <= s.second);
}

void solve() {
    ll n, r;
    cin >> r >> n;
    vector<pair<pll, ll>> celebs;
    celebs.emplace_back(make_pair(1, 1), 0);
    for (int i = 1; i <= n; ++i) {
        ll t, x, y;
        cin >> t >> x >> y;
        celebs.emplace_back(make_pair(x, y), t);
    }
    ll negInf = 1e5 + 2;
    vl dp(n + 1, -negInf);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (possible(celebs[0], celebs[i])) {
            dp[i] = 0;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= min(n, i + 4 * r) && dp[i] >= 0; ++j) {
            if (possible(celebs[i], celebs[j])) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    ll t = *max_element(dp.begin(), dp.end());
    cout << t << endl;
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
    // cin >> t;
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
