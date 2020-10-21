/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/20/2020 at 8:03 PM(UTC +5.5)
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
    ll n;
    cin >> n;
    ll array[n];
    read(array, n);
    ll first1 = 0;
    for (ll i = 0; i < n; ++i) {
        if (array[i] == 1) {
            first1 = i;
            break;
        }
    }
    for (ll i = first1 + 1; i < n; ++i) {
        if (array[i] == 1) {
            first1++;
        } else {
            break;
        }
    }
    bool check = false;
    for (ll i = first1 + 1; i < n; ++i) {
        if (array[i] == 1) {
            check = true;
            break;
        }
    }
    if (!check) {
        cout << 0 << endl;
        return;
    }
    ll last1 = n;
    for (ll i = n - 1; i > first1; --i) {
        if (array[i] == 1) {
            last1 = i;
            break;
        }
    }
    ll count = 0;
    for (ll i = first1 + 1; i < last1; ++i) {
        if (array[i] == 0) {
            count++;
        }
    }
    cout << count << endl;

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
