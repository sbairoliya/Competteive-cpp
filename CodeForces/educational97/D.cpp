/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/27/2020 at 9:35 PM(UTC +5.5)
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

void solve() {
    ll n;
    cin >> n;
    ll count = 1;
    ll array[n];
    queue<ll> q;
    read(array, n);
    q.push(1);
    for (ll i = 1; i < n - 1; ++i) {
        if (array[i + 1] < array[i]) {
            q.push(count);
            count = 1;
        } else {
            count++;
        }
    }
    q.push(count);
    ll out = 0;
    ll prev = 1;
    while (!q.empty()) {
        ll sum = 0;
        for (ll i = 0; i < prev && (!q.empty()); ++i) {
            sum += q.front();
            q.pop();
        }
        out++;
        prev = sum;
    }
    cout << out  - 1 << endl;
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
