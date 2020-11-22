/*
 * Developed By : Shivam Bairoliya
 * Created on   : 11/22/2020 at 5:31 PM(UTC +5.5)
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
ll arrayXOR[65536 + 1];

ll getXOR(ll x, ll y) {
    return (arrayXOR[x] ^ arrayXOR[y]);
}

void solve() {
    ll n;
    cin >> n;
    ll temp1 = -1;
    ll temp2 = -1;
    unordered_map<ll, ll> checkSet;
    for (ll i = 2; i <= n; ++i) {
        cout << "XOR 1 " << i << endl;
        cout.flush();
        cin >> arrayXOR[i];
        if (temp1 == -1) {
            if (arrayXOR[i] == 0) {
                temp1 = 1;
                temp2 = i;
            }
            else if (checkSet.find(arrayXOR[i]) != checkSet.end()) {
                temp1 = i;
                temp2 = checkSet.find(arrayXOR[i])->second;
            } else {
                checkSet.emplace(arrayXOR[i], i);
            }
        }
    }
    ll finArray[n + 1];
    if (temp1 != -1) {
        if (temp1 == 1) {
            ll a2temp2;
            cout << "AND 1 " << temp2 << endl;
            cout.flush();
            cin >> a2temp2;
            finArray[1] = a2temp2;
        } else {
            ll atemp1, atemp2;
            cout << "AND " << min(temp1, temp2) << " " << max(temp1, temp2) << endl;
            cout.flush();
            cin >> atemp1;
            finArray[1] = (atemp1 ^ finArray[temp1]);
        }
    } else {
        ll find = -1;
        for (ll i = 2; i <= n; ++i) {
            if ((arrayXOR[i]) == n - 1) {
                find = i;
                break;
            }
        }
        if (find == -1) {
            for (ll i = 3; i <= n; ++i) {
                if ((arrayXOR[i] ^ arrayXOR[2]) == n - 1) {
                    find = i;
                    break;
                }
            }
            ll a12, a1find;
            cout << "AND 1 2" << endl;
            cout.flush();
            cin >> a12;
            cout << "AND 1 " << find << endl;
            cout.flush();
            cin >> a1find;
            // a1 + a2 = x
            ll x = arrayXOR[2] + 2 * a12;
            // a1 + a3 = y;
            ll y = arrayXOR[find] + 2 * a1find;
            // a2 + a3 = z;
            ll z = n - 1;
            finArray[1] = (x + y - z) / 2;
        } else {
            if (find != 2) {
                ll a12, a2find;
                cout << "AND 1 2" << endl;
                cout.flush();
                cin >> a12;
                cout << "AND 2 " << find << endl;
                cout.flush();
                cin >> a2find;
                // a1 + a2 = x
                ll x = arrayXOR[2] + 2 * a12;
                // a1 + a3 = y;
                ll y = n - 1;
                // a2 + a3 = z;
                ll z = (arrayXOR[2] ^ arrayXOR[find]) + 2 * a2find;
                finArray[1] = (x + y - z) / 2;
            } else {
                ll a13, a23;
                cout << "AND 1 3" << endl;
                cout.flush();
                cin >> a13;
                cout << "AND 2 3" << endl;
                cout.flush();
                cin >> a23;
                // a1 + a2 = x
                ll x = n - 1;
                // a1 + a3 = y;
                ll y = arrayXOR[3] + 2 * a13;
                // a2 + a3 = z;
                ll z = (arrayXOR[2] ^ arrayXOR[3]) + 2 * a23;
                finArray[1] = (x + y - z) / 2;
            }
        }
    }
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
