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
    ll array1[n];
    ll array2[n];
    ll array3[n];
    readNumbersArray(n ,array1);
    readNumbersArray(n, array2);
    readNumbersArray(n, array3);
    ll answer[n];
    answer[0] = array1[0];
    for (int i = 1; i < n -1; ++i) {
        if (array1[i] == answer[i -1]) {
            answer[i] = array2[i];
        } else {
            answer[i] = array1[i];
        }
    }
    answer[n - 1] = array1[n - 1];
    if (answer[n -1] == answer[0] || answer[n - 1] == answer[n-2]) {
        answer[n - 1] = array2[n -1];
    }
    if (answer[n -1] == answer[0] || answer[n - 1] == answer[n-2]) {
        answer[n - 1] = array3[n -1];
    }
    for (int i = 0; i < n; ++i) {
        cout << answer[i] <<" ";
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
