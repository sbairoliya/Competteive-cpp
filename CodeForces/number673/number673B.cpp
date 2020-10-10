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
    ll n, t;
    cin >> n >> t;
    vector<pair<ll, ll>> array;
    array.push_back(make_pair(-1, -1));
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        array.push_back(make_pair(x, i));
    }
    sort(++array.begin(), array.end());
    ll bound = t / 2;
    ll find = 0;
    for (int i = 1; i <= n; ++i) {
        if (array[i].first <= bound) {
            find++;
        } else {
            break;
        }
    }
    ll index = 0;
    if (t % 2 == 1) {
        index = find;
    } else {
        ll temp = 0;
        for (int i = 1; i <= n; ++i) {
            if (array[i].first == bound) {
                temp = i;
                break;
            }
        }
        if (temp == 0)
            index = find;
        else
            index = (find + temp) / 2;
    }
    ll tempArray[n + 1];
    for (int i = 1; i <= index; ++i) {
        tempArray[array[i].second] = 0;
    }
    for (int i = index + 1; i <=n ; ++i) {
        tempArray[array[i].second] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << tempArray[i] << " ";
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
