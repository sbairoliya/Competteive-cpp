/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/27/2020 at 8:25 PM(UTC +5.5)
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
    string s;
    cin >> s;
    vl ones;
    vl zeros;
    char prev = s[0];
    ll count = 1;
    for (ll i = 1; i < n; ++i) {
        if (s[i] == prev) {
            count++;
        } else {
            if (prev == '1') {
                ones.push_back(count);
            } else {
                zeros.push_back(count);
            }
            count = 1;
            prev =s[i];
        }
    }
    if (prev == '1') {
        ones.push_back(count);
    } else {
        zeros.push_back(count);
    }
    ll oneSum = accumulate(ones.begin(), ones.end(), 0) - ones.size();
    ll zeroSum = accumulate(zeros.begin(), zeros.end(), 0) - zeros.size();
    cout << max(oneSum, zeroSum) << endl;
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

