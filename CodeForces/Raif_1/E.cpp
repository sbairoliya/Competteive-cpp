/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/17/2020 at 10:43 PM
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
#define read(arr, n) for(int i = 0; i < n; i++) cin>>arr[i]
#define read1(arr, n) for(int i = 1;i <= n; i++) cin>>arr[i]

/************************************* SOLUTION BELOW ***************************************/

void solve() {
    ll n, k;
    cin >> n >> k;
    ll array[n];
    read(array, n);
    priority_queue<ll> pq;
    for (ll i = 0; i < n; ++i) {
        pq.push(array[i]);
    }
    while (pq.size() != k) {
        ll x = pq.top();
        pq.pop();
        ll one = x / 2;
        ll two;
        if (x % 2 == 1) {
            two = one + 1;
        } else {
            two = one;
        }
        pq.push(one);
        pq.push(two);
    }
    ll sum = 0;
    while (!pq.empty()) {
        sum += (pq.top() * pq.top());
        pq.pop();
    }
    cout << sum << endl;
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
