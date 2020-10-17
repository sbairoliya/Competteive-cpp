/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/17/2020 at 6:48 PM
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
    string s;
    cin >> s;
    ll countG = 0;
    ll countL = 0;
    ll countD = 0;
    for (char i: s) {
        if (i == '>') {
            countG++;
        } else if (i == '<') {
            countL++;
        } else {
            countD++;
        }
    }
    ll collison = 0;
    for (ll i = 0; i < n - 1; ++i) {
        if (s[i] == '>' && s[i + 1] == '<') {
            collison++;
        }
    }
    if (s[n - 1] == '>' && s[0] == '<') {
        collison++;
    }
    if (countL > 0 && countG > 0) {
        set<ll> temp;
        for (ll i = 0; i < n - 1; ++i) {
            if (s[i] == '-') {
                temp.insert(i);
                temp.insert(i + 1);
            }
        }
        if (s[n - 1] == '-') {
            temp.insert(0);
            temp.insert(n - 1);
        }
        cout << temp.size() << endl;
        return;
    }

    cout << n << endl;

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
