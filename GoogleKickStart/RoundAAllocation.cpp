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

/************************************* SOLUTION BELOW ***************************************/
void solve(ll t) {
    ll n, monies;
    cin >> n >> monies;
    ll array[n];
    for (ll i = 0; i < n; ++i) {
        cin >> array[i];
    }
    sort(array, array + n);
    ll sum = 0;
    if (array[0] > monies) {
        cout << "Case #" << t << ": " << 0 << endl;
        return;
    }
    sum += array[0];
    ll count = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (sum + array[i + 1] > monies) {
            cout << "Case #" << t << ": " << count << endl;
            return;
        } else {
            count++;
            sum += array[i + 1];
        }
    }
    cout << "Case #" << t << ": " << count << endl;
}

int32_t main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.in", "w", stderr);
    auto start = high_resolution_clock::now();
#endif
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t ; ++i) {
        solve(i);
    }
#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken for execution: "
         << duration.count() << " ms" << endl;
#endif
}