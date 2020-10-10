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
#include<cmath>
#include<numeric>

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
    ll n;
    cin >> n;
    map<ll, vl> map1;
    ll x;
    for (int i = 1; i <= n; ++i) {
        map1[i].push_back(0);
    }
    for (int i = 1; i <= n; ++i) {
        cin >>x;
        map1[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        map1[i].push_back(n + 1);
    }
    ll array[n + 2];
    for (int i = 1; i <= n + 1; ++i) {
        array[i] = -1;
    }
    for (int i = n; i >= 1; --i) {
        ll diff = 0;
        vl vector1 = map1[i];
        for (int j = 1; j < vector1.size() ; ++j) {
            diff = max(diff, vector1[j] - vector1[j - 1]);
        }
        array[diff] = i;
    }
    ll notminus1 = 0;
    ll finalarray[n + 1];
    for (int i = 1; i <= n + 1; ++i) {
        if (array[i] != -1) {
            notminus1 = i;
            break;
        } else {
            finalarray[i] = -1;
        }
    }
    ll min = array[notminus1];
    for (int i = notminus1; i <= n; ++i) {
        if (array[i] != -1 && array[i] < min) {
            min = array[i];
        }
        finalarray[i] = min;
    }
    for (int i = 1; i <= n; ++i) {
        cout << finalarray[i] <<" ";
    }
    cout <<endl;
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
