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

inline ll gcd(ll a, ll b) { if (a == 0) return b; else return gcd(b % a, a); }

/************************************* SOLUTION BELOW ***************************************/
void solve() {
    ll n;
    cin >> n;
//    map<ll, vl > theMap;
    ll array[n];
    ll sortedArray[n];
    cin >> array[0];
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    sortedArray[0] = array[0];
    for (ll i = 1; i < n; ++i) {
        cin >> array[i];
        sortedArray[i] = array[i];
    }
    sort(sortedArray, sortedArray + n);
    ll minNum = sortedArray[0];
    vector<pair<ll, ll>> pairs;
    for (ll i = 0; i < n; ++i) {
        if (array[i] != sortedArray[i]) {
            pairs.push_back(make_pair(array[i], sortedArray[i]));
        }
    }
    unordered_set<ll> set1;
    for (int i = 0; i < pairs.size(); ++i) {
        ll currentGCD = gcd(pairs[i].first, pairs[i].second);
        if (currentGCD != minNum){
            set1.insert(pairs[i].first);
            set1.insert(pairs[i].second);
        }
    }
    ll currentGCD = minNum;
    for (ll x: set1) {
        currentGCD = gcd(currentGCD, x);
    }
    if (currentGCD == minNum) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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