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
    map<ll, ll> m;
    for (ll i = 0; i < n; i++) {
        cin >> tim[i];
        m[tim[i]]++;
    }
    ll ans = 0;
    vector<bool> check(n + 1);
    for (auto x:m) {
        for (ll i = 0; i < x.second; i++) {
            int found = 0;
            ll forward = x.first + 1, backward = x.first - 1, mid = x.first;
            while (!found) {
                if (!check[mid]) {
                    check[mid] = true;
                    ans += (abs(x.first - mid));
                    found = 1;
                    continue;
                } else if (backward > 0 && !check[backward]) {
                    check[backward] = true;
                    ans += (abs(x.first - backward));
                    found = 1;
                    continue;
                } else if (!check[forward]) {
                    check[forward] = true;
                    ans += (abs(x.first - forward));
                    found = 1;
                }
                forward += 1;
                backward -= 1;
            }
        }
    }
    cout << ans << "\n";
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
