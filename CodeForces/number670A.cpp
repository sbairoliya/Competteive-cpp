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
    cin>>n;
    ll array[102] = {0};
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >>x;
        array[x]++;
    }
    ll count1 = -1;
    ll count2 = -1;

    for (int i = 0; i < 102; ++i) {
        if (array[i] == 1) {
            if (count1 == -1) {
                count1 = i;
            }
        }
        if (array[i] == 0) {
            if (count1 != -1) {
                count2 = i;
                break;
            }
            else  {
                count1 = i;
                count2 = i;
                break;
            }
        }
    }
    if (count2 == -1)
        count2 = 0;
    if (count1 == -1)
        count1 = 0;
    cout<<count1 + count2<<endl;
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
