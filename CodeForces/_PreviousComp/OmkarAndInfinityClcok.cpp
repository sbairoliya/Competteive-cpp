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
void solve() {
    ll n, k;
    cin>>n>>k;
    ll array[n];
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
    }
    ll max = *(max_element(array, array + n));
    ll min = *(min_element(array, array + n));
    ll array1[n];
    for (int i = 0; i < n; ++i) {
        array1[i] = max - array[i];
    }
    ll array2[n];
    max = max - min;
    for (int i = 0; i < n; ++i) {
        array2[i] = max - array1[i];
    }
    if (k % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            cout<<array1[i]<<" ";
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            cout << array2[i] << " ";
        }
    }
    cout<<endl;
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