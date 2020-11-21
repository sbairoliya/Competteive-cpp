/*
 * Developed By : Shivam Bairoliya
 * Created on   : 11/21/2020 at 8:24 PM(UTC +5.5)
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
    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    ll arrayA[26];
    ll arrayB[26];
    for (ll i = 0; i < 26; ++i) {
        arrayA[i] = 0;
        arrayB[i] = 0;
    }
    for (char x: a) {
        arrayA[x - 'a']++;
    }
    for (char x: b) {
        arrayB[x - 'a']++;
    }
    for (ll i = 0; i < 26; ++i) {
        ll t = min(arrayA[i], arrayB[i]);
        arrayA[i] -= t;
        arrayB[i] -= t;
    }
    ll left = 0;
    bool check = true;
    for (ll i = 0; i < 26; ++i) {
        if (arrayB[i] > 0) {
            if (arrayB[i] % k != 0 || arrayB[i] > left) {
                check = false;
                break;
            }
            left -= arrayB[i];
        }
        left += arrayA[i];
        if (left % k != 0) {
            check = false;
            break;
        }
    }
    cout << ((check)? "Yes":"No") << endl;
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
