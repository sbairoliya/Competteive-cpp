/*
 * Developed By : Shivam Bairoliya
 */

#include <iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<chrono>


using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

#define int long long
#define vi vector<int>
#define vl vector<long long>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/
void solve() {
    string w;
    cin >> w;
    ll x;
    cin >> x;
    ll n = w.length();
    char array[n];
    for (int i = 0; i < n; ++i) {
        array[i] = '2';
    }
    for (int i = 0; i < x && i + x < n; ++i) {
        if (w[i] == '0') {
            array[i + x] = '0';
        } else {
            array[i + x] = '1';
        }
    }
    for (int i = 1; i <= x && (n - i - x) >= 0; ++i) {
        ll len = n - i;
        if (w[len] == '0') {
            if (array[len - x] == '1') {
                cout << -1 << endl;
                return;
            }
            array[len - x] = '0';
        } else {
            if (array[len - x] == '0') {
                cout << -1 << endl;
                return;
            }
            array[len - x] = '1';
        }
    }
    for (int i = x; i < n - x; ++i) {
        if (w[i] == '0') {
            if (i - x >= 0) {
                if (array[i - x] == '1') {
                    cout << -1 << endl;
                    return;
                }
                array[i - x] = '0';
            }
            if (i + x < n) {
                if (array[i + x] == '1') {
                    cout << -1 << endl;
                    return;
                }
                array[i + x] = '0';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (array[i] == '2')
            cout << 1;
        else
            cout << array[i];
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
