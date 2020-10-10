/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/10/2020 at 8:28 PM
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
#define int long long

/************************************* SOLUTION BELOW ***************************************/
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity
void solve() {
    ll n, k;
    cin >> n >> k;
    ll top = k;
    string s;
    cin >> s;
    ll w = 0, l = 0;
    vl weight, value;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W')
            w++;
        else
            l++;
    }
    if (k >= l) {
        cout << (1 + ((n - 1) * 2)) << endl;
        return;
    }
    if (w == 0 && k == 0) {
        cout << 0 << endl;
        return;
    }
    if (w == 0) {
        cout << (1 + ((k - 1) * 2)) << endl;
        return;
    }
    ll startL = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            startL++;
        } else {
            break;
        }
    }
    ll weght = 0;
    for (int i = startL; i < n; ++i) {
        if (s[i] == 'W') {
            if (weght != 0) {
                weight.push_back(weght);
                weght = 0;
            }
        } else {
            weght++;
        }
    }
    int end = weght;
    ll wcount = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            if (wcount != 0) {
                sum += ((2 * wcount) - 1);
                wcount = 0;
            }
        } else {
            wcount++;
        }
    }
    if (wcount != 0) {
        sum += ((wcount * 2) - 1);
    }
    sort(weight.begin(), weight.end());
    int i = 0;
    int oneCOunt = 0;
    for (; i < weight.size(); ++i) {
        if (weight[i] <= k) {
            if (weight[i] == 1)
                oneCOunt++;
            k -= weight[i];
        } else {
            break;
        }
    }
    sum += (((top - k) * 2) + i);
    sum += k * 2;
    cout << sum <<endl;
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
