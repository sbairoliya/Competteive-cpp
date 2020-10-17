/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/17/2020 at 7:48 PM
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
    ll array[n + 1];
    read1(array, n);
    vector<pll > twos;
    vector<pll > threes;
    for (ll i = 1; i <= n; ++i) {
        ll first = 0, second = 0;
        if (array[i] == 2) {
            first = i;
            for (ll j = i + 1; j <= n; ++j) {
                if (array[j] == 1) {
                    second = j;
                    array[j] = 0;
                    break;
                }
            }
            if (second == 0) {
                cout << -1 << endl;
                return;
            } else {
                twos.emplace_back(first, second);
            }
        }
        if (array[i] == 3) {
            first = i;
            for (ll j = i + 1; j <= n; ++j) {
                if (array[j] == 1) {
                    second = j;
                    array[j] = 0;
                    break;
                }
            }
            if (second == 0) {
                cout << -1 << endl;
                return;
            } else {
                threes.emplace_back(first, second);
            }
        }
    }
    vector<pll > targets;
    for (pll temp: twos) {
        ll col = min(temp.first, temp.second);
        targets.emplace_back(col, temp.first);
        targets.emplace_back(col, temp.second);
    }
    for (pll temp: threes) {
        ll col = min(temp.first, temp.second);
        ll col2 = max(temp.first, temp.second);
        targets.emplace_back(col, temp.first);
        targets.emplace_back(col, temp.second);
        targets.emplace_back(col2, temp.second);
    }
    for (ll i = 1; i <= n; ++i) {
        if (array[i] == 1) {
            targets.emplace_back(i, i);
        }
    }
    cout << targets.size() << endl;
    for (pll temp: targets) {
        cout << temp.first << " " << temp.second << endl;
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
