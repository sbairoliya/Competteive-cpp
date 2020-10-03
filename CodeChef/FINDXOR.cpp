/*
 * Developed By : Shivam Bairoliya
 */

//#define ONLINE_JUDGE

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
#include<cmath>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;


#define vi vector<int>
#define vl vector<long long>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/
void solve() {
    vl set;
    ll x;
    ll n;
    cin >> n;
    cout << 1 << " " << 0 << endl;
    ll sum;
    cin >> sum;
    for (int i = 0; i < 19; ++i) {
        ll currPow = (ll)pow(2, i);
        ll tempSum = sum + currPow * n;
        cout << 1 << " " << currPow << endl;
        cin >> x;
        x = tempSum - x;
        if (x == 0) {
            break;
        }
        else {
            x = x / (2 * currPow);
            if (x % 2 == 1) {
                set.push_back(i);
            }
        }
    }
    ll out = 0;
    for(ll i : set) {
        out = out + pow(2, i);
    }
    cout << out <<endl;
    ll c;
    cin >> n;
    if (n == -1) {
        exit(0);
    }
}

int32_t main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.in","w",stderr);
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
