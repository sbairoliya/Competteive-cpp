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
    string s;
    cin >> s;
    ll n =s.length();
    ll ones = 0;
    ll zeros = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')
            ones++;
        else
            zeros++;
    }
    ll toOut = min(ones, zeros);
    for (int i = 0; i < n; ++i) {
        //make 00001111
        ll onex = 0, zerox =0;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '1')
                zerox++;
        }
        for (int j = i; j < n; ++j) {
            if (s[j] == '0')
                onex++;
        }
        //make 11110000
        ll oney = 0, zeroy =0;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '0')
                oney++;
        }
        for (int j = i; j < n; ++j) {
            if (s[j] == '1')
                zeroy++;
        }

        //min
        toOut = min(toOut, zeroy + oney);
        toOut = min(toOut, zerox + onex);
    }
    cout<<toOut<<endl;
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
    cout << __cplusplus << endl;
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
