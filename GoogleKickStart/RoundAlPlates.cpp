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


using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;


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
ll knapSack(ll plates, vector<vl > wt, ll n, ll k) {
    ll i, p, j;
    ll knapSack[n + 1][plates + 1];
    for (i = 0; i <= n; i++) {
        for (p = 0; p <= plates; p++) {
            knapSack[i][p] = 0;
        }
    }
    for (i = 1; i <= n; i++) {
        for (p = 0; p <= plates; p++) {
            for (ll j = 0; j <= min(p, k); j++) {
                knapSack[i][p] = max(knapSack[i][p], wt[i][j] + knapSack[i - 1][p - j]);
            }
        }
    }
    return knapSack[n][plates];
}


void solve(ll caseNumber) {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<vl > beautyValue;
    for (int i = 0; i <= n; ++i)
        beautyValue.push_back(vl());
    for (int i = 1; i <= n; ++i) {
        beautyValue[i].push_back(0);
        for (int j = 1; j <= k; ++j) {
            ll x;
            cin >> x;
            beautyValue[i].push_back(beautyValue[i][j - 1] + x);
        }
    }
    cout << "Case #" << caseNumber << ": " << knapSack(p, beautyValue, n, k) << endl;

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
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken for execution: "
         << duration.count() << " ms" << endl;
#endif
}