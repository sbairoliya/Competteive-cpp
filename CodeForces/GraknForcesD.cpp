/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/8/2020 at 5:33 PM
 */

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

#define vi vector<int>
#define vl vector<long long>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}

/************************************* SOLUTION BELOW ***************************************/
bool comparePairs(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
        return a.second >= b.second;
    }
    return a.first > b.first;
}

void solve() {
    vector<pair<ll, ll>> robbers;
    vector<pair<ll, ll>> lights;
    ll n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        robbers.emplace_back(x, y);
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        lights.emplace_back(x, y);
    }
    vector<ll> xCoordintes(10e6 + 2, -1);

    for (auto light: lights) {
        for (auto robber :robbers) {
            ll xMov = light.first - robber.first;
            ll yMov = light.second - robber.second;
            if (xMov >= 0 && yMov >= 0) {
                xCoordintes[xMov] = max(xCoordintes[xMov], yMov);
            }
        }
    }
    ll maxY = -1;
    ll ans = INT_MAX;
    for (int i = 10e6 + 1; i >= 0; --i) {
        maxY = max(maxY, xCoordintes[i]);
        ans = min(ans, maxY + i + 1);
    }
    ans = min(ans, maxY + 1);
    cout << ans << endl;

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
    //cin >> t;
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
