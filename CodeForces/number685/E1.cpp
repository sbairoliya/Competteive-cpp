/*
 * Developed By : Shivam Bairoliya
 * Created on   : 11/22/2020 at 5:18 PM(UTC +5.5)
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
    cout <<"AND 1 2" << endl;
    cout.flush();
    ll a12, a13, a23;
    cin >> a12;
    cout <<"AND 1 3" << endl;
    cout.flush();
    cin >> a13;
    cout <<"AND 2 3" << endl;
    cout.flush();
    cin >> a23;
    ll arrayXOR[n + 1];
    for (ll i = 2; i <= n; ++i) {
        cout << "XOR 1 " << i << endl;
        cout.flush();
        cin >> arrayXOR[i];
    }
    // a1 + a2 = x
    ll x = arrayXOR[2] + 2 * a12;
    // a1 + a3 = y;
    ll y = arrayXOR[3] + 2 * a13;
    // a2 + a3 = z;
    ll z = (arrayXOR[2] ^ arrayXOR[3]) + 2 * a23;
    ll finArray[n + 1];
    finArray[1] = (x + y - z) / 2;
    for (ll i = 2; i <= n; ++i) {
        finArray[i] = (arrayXOR[i] ^ finArray[1]);
    }
    cout << "! ";
    for (ll i = 1; i <= n; ++i) {
        cout << finArray[i] << " ";
    }
    cout << endl;
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
//    cin >> t;
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
